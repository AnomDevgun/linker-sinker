#include<iostream>   //input output stream(contains cin and cout)
#include<fstream>  //filestream, used for filehandeling operations
#include<cctype>  //character conversion example: small character to capital
#include<iomanip> //input output library,c contains the accesibility for thing's like setw()
#include<cstdio>
using namespace std;


class account
{
	int acno;
	int apas;              //private variables of the class (var are private by default)
	char name[50];
	int pass;
	int deposit;
	char type;
public:
	void create_account();
	void create_admi();          //public functions declaration in the class
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retpas() const;
	int retapas() const;
	int retdeposit() const;
	char rettype() const;
};

void account::create_account()   //function definition outside class using SRO
{
    jp:

	cout<<"\n\t\t\tEnter Account Number. : ";
	cin>>acno;
	account ac;  //creating object of class to access it mem fn and mem data
	bool flag=false;
	ifstream inFile;  //object of ifstream to access external file for reading and related task
	inFile.open("account.dat",ios::binary); //opening external file
	if(!inFile)  //checks if file is present
	{
		return;
	}
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==acno)
		{
			flag=true;
		}
	}
    inFile.close();  //close the file
	if(flag==true)
	{
		cout<<"\n\n\t\t\tEntered Account number already exists\n";
		cout<<"\t\t\tPlease Enter A Different Account Number\n\n";
		goto jp;
		}
		else if(flag==false)
		{
		goto jmp;
		}
	jmp:
	cout<<"\n\n\t\t\tEnter Name of Account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\n\t\t\tCreate Password for Account(numeric only) : ";
	cin>>pass;
	cout<<"\n\t\t\tEnter Type of Account (C for Current, S for Savings) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Has Been Created.";
}
void account::create_admi()
{
    cout<<"\n\t\t\tEnter a numeric password that is the admin password\n";
    cin>>apas;
}

void account::show_account() const  //function definition outside class using SRO
{
	cout<<"\n\t\t\tAccount Number. : "<<acno;
	cout<<"\n\t\t\tAccount Holder's Name : ";
	cout<<name;
	cout<<"\n\t\t\tAccount Type : "<<type;
	cout<<"\n\t\t\tBalance amount of Account : "<<deposit;
}


void account::modify()  //function definition outside class using SRO
{
	cout<<"\n\t\t\tAccount Number. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of The Account(C->S or S->C) : ";
	cin>>type;
	type=toupper(type);
}


void account::dep(int x) //function definition outside class using SRO
{
	deposit+=x;
}

void account::draw(int x) //function definition outside class using SRO
{
	deposit-=x;
}

void account::report() const  //function definition outside class using SRO
{
	cout<<acno<<setw(10)<<""<<name<<setw(10)<<""<<type<<setw(1)<<'-'<<deposit<<'$'<<endl;  //setw() sets a defined width syn: setw(int)
}

int account::retacno() const //function definition outside class using SRO
{
	return acno;
}
int account::retpas() const
{
	return pass;
}
int account::retapas() const
{
	return apas;
}

int account::retdeposit() const //function definition outside class using SRO
{
	return deposit;
}

char account::rettype() const //function definition outside class using SRO
{
	return type;
}



void write_account();   //functions declared outside the class, they cannot access the private and protected members of the class
void write_admin();
void display_sp(int, int);
void modify_account(int, int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int, int);

int main()
{
	char ch,ace,che,n;
	int num;
	int p;
	int ap;
	jump:
	    cout<<"\n\n";
	cout<<"\t\t\t\t\tWELCOME TO THE BANK MANAGEMENT SYSTEM\n";
	cout<<"\t\t\t\t\t\t      MAIN MENU\n\n";
	cout<<"\t\t\t\t1)Please Enter 1 for accessing Bank Manager Services\n";
	cout<<"\t\t\t\t2)Please Enter 2 for accessing Customer Services\n";
	cout<<"\t\t\t\t3)Enter any other number if you wish to exit\n";
	cin>>ace;
	switch(ace)
    {
        case '1':
               do
               {


                cout<<"\t\t\t\tENTER ADMINISTRATIVE PASSWORD TO CONTINUE\n";
                cout<<"\t\t\t\tOr Press 0 to go back to the main menu\n";
                cin>>ap;
                if(ap==0)
                    goto jump;
                account adb;  //creating object of class to access it mem fn and mem data
	bool flag=false;
	ifstream inFile;  //object of ifstream to access external file for reading and related task
	inFile.open("admin.dat",ios::binary); //opening external file
	if(!inFile)  //checks if file is present
	{
		cout<<"File could not be opened !! Press any Key To Continue."; //file not found
		break;
	}

    	while(inFile.read(reinterpret_cast<char *> (&adb), sizeof(account)))
	{
		if(adb.retapas()==ap)
		{
            cout<<"\n\n\t\t\t\t===============================\n";
	cout<<"\t\t\t\t\tADMINISTRATOR PORTAL";
	cout<<"\n\t\t\t\t===============================\n";
      cout<<"\n\t\t\t\t1. VIEW ALL AVAILABLE ACCOUNTS";
      cout<<"\n\t\t\t\t2. DELETE A RECORD";
      cout<<"\n\t\t\t\t3. MODIFY AN ACCOUNT";
      cout<<"\n\t\t\t\t4. EXIT TO MAIN MENU\n";
      cin>>che;
      switch(che)
      {
          case '1':
			display_all(); //fn call
				cout<<"\nYou will now be taken back to the Administrator Portal where you can re-view other functions or exit to the main menu\n";
	cout<<"Thank You\n";

			break;
          case '2':
              cout<<"\n\n\t\t\tEnter The account No. : ";
			cin>>num;
			delete_account(num); //fn call

			break;
          case '3':
            cout<<"\n\n\t\t\tEnter The account No. : ";
			cin>>num;
			cout<<"\n\t\t\tEnter The password :";
			cin>>p;
			modify_account(num,p); //fn call

			break;

			 case '4':
            cout<<"\n\n\t\t\tThank You For Using Our Services\n";
            goto jump;
            break;
			 default :cout<<"Incorrect Selection Please try again\n";
      }
      flag=true;
            }


		}
    inFile.close();  //close the file
	if(flag==false)
		cout<<"\n\n\t\t\tEntered Admin password is wrong, please try again Or enter 0 to goto main menu\n";
    }
    while(che!='0');



    case '2':
	do
	{
	cout<<"\n\n\t\t\t\t=============================\n";
	cout<<"\t\t\t\t\tCUSTOMER PORTAL";
	cout<<"\n\t\t\t\t=============================\n";
		cout<<"\t\t\t\t         MAIN MENU\n";
		cout<<"\n\t\t\t\t1. START A NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AN AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AN AMOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. EXIT TO MAIN MENU";
		cout<<"\n\t\t\t\t6. EXIT THE PROGRAM";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-6): ";
		cin>>ch;
		switch(ch)
		{
		case '1':

			write_account(); //fn call
			break;
		case '2':

			cout<<"\n\n\t\t\tEnter The account No. : ";
			cin>>num;
			cout<<"\n\t\t\tEnter The password :";
			cin>>p;
			deposit_withdraw(num, 1, p);  //fn call
			break;
		case '3':

			cout<<"\n\n\t\t\tEnter The account No. : ";
			cin>>num;
			cout<<"\n\t\t\tEnter The password :";
			cin>>p;
			deposit_withdraw(num, 2, p);//fn call
			break;
		case '4':

			cout<<"\n\n\t\t\tEnter The account No. : ";
			cin>>num;
			cout<<"\n\t\t\tEnter The password :";
			cin>>p;
			display_sp(num,p); //fn call
			break;
         case '5':
            goto jump;
            break;
		 case '6':

			cout<<"\n\n\t\t\tThank You For Using Our Services";
			break;
		 default :cout<<"Incorrect Selection Please try again\a";
		}
		cin.ignore(); //Ignore function is used to skip(discard/throw away) characters in the input stream.(is stream)
		cin.get(); //gets a whole line as opposed to cin reading single char
    }
                while(ch!='6'); //loops till input is not 7
}
    return 0;
}

void write_admin()
{
    account adm;
    ofstream outFile;
    outFile.open("admin.dat",ios::binary|ios::app);
    adm.create_admi();
    outFile.write(reinterpret_cast<char *> (&adm), sizeof(account));
    outFile.close();
}


void write_account()  //fn definition
{
	account ac; //creating object of class to access it mem fn and mem data
	ofstream outFile;  //object of ofstream to access external file for writing and related task
	outFile.open("account.dat",ios::binary|ios::app); //ios app is append to end of file opened
	ac.create_account();//calls the fn and in fn, cin,cout do read and write to file
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account)); /*data_type *var_name = reinterpret_cast <data_type *>(pointer_variable);
	//reinterpret cast tells the compiler to reinterpret the data being pointed to as something else in this case reinterpret &ac as a char pointer
	outfile.write(reinterpret_cast<char *> (&ac), sizeof(account)); Reads the account class data directly from a file into the memory occupied by ac.*/
	outFile.close();
}

void display_sp(int n, int pa)  //fn definition
{
	account ac;  //creating object of class to access it mem fn and mem data
	bool flag=false;
	ifstream inFile;  //object of ifstream to access external file for reading and related task
	inFile.open("account.dat",ios::binary); //opening external file
	if(!inFile)  //checks if file is present
	{
		cout<<"File could not be opened !! Press any Key To Continue."; //file not found
		return;
	}

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n && ac.retpas()==pa)
		{
		    cout<<"\n\t\t\tBALANCE DETAILS\n";
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();  //close the file
	if(flag==false)
		cout<<"\n\n\t\t\tEntered Account data does not match a record, please try again\n";
}



void modify_account(int n, int pw)  //fn definition
{
	bool found=false;
	account ac;  //creating object of class to access it mem fn and mem data
	fstream File; //object of filestream
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be opened !! Press any Key to continue.";
		return;
	}
	while(!File.eof() && found==false) //eof is end of file, for when no more data to be read
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpas()==pw)  //check if returned ac no is equal to search query
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account\n"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account)); //the negative 1 is to go back one pointer space
                          //static_cast operator converts a given expression to a specified type
			File.seekp(pos,ios::cur); //ios::cur is to denote current pointer position
			/*seekp() is used to move the put pointer to a desired location with respect to a reference point.

Syntax:       file_pointer.seekp(number of bytes ,Reference point);*/
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated\n";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tEntered Combination of username and password doesn't match records\n";
}



void delete_account(int n)  //fn definition
{
	account ac;  //creating object of class to access it mem fn and mem data
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key to continue.";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);  // seekg Sets the position of the next character to be extracted from the input stream.

	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted ..\n";
}


void display_all() //fn definition
{

	account ac; //creating object of class to access its mem fn and mem data
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key to continue.\n";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"Acc num      Name           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option, int p)  //fn definition
{
	int amt;
	bool found=false;
	account ac;  //creating object of class to access it mem fn and mem data
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);  //ios in and out open file for reading and writing to respectively,binary for opening in binary mode
	if(!File)
	{
		cout<<"File could not be opened !! Press any Key to continue.\n";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpas()==p)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\t  DEPOSIT AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tWITHDRAWAL AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdrawn: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficient balance\n";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tIncorrect User-name/Password was input please try again\n";
}

