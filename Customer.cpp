#include <iostream>
#include <fstream>
#include "ClearScreen.cpp"
#include  "rang.hpp"
using namespace std;
using namespace rang;

class Customer
{
protected:
	char name[100];
	int age;
	int acc_no;
	float balance;
	int password;
};



class existing_cust:private Customer{
private:
	friend class new_customer;

public:


	existing_cust(){

		strcpy(name,"NULL");
		acc_no=0;
		age=0;
		balance=0;
		password=0;
	}

	bool compareano(int ano){
		return (this->acc_no == ano);
	}

	bool comparepss(int pss){
		return password==pss;
	}

	void deposit(){
		cout<<endl<<endl;
		cout<<fgB::yellow;
		cout<<"Enter amount to be deposited : ";
		int q;
		cout<<fgB::magenta;
		cin>>q;
		balance += q;
		cout<<fgB::cyan;
		cout<<endl<<endl<<"AMOUNT ADDED SUCCESSFULLY!!!"<<endl<<endl;
		cin.get();
		cin.get();
		clear();
		return ;
	}

	void withdraw(){
		cout<<endl<<endl;
		cout<<fgB::yellow;
		cout<<"Enter amount to be collected : ";
		int c;
		cout<<fgB::magenta;
		cin>>c;

		if(c>balance){
			clear();
			cout<<fgB::red;
			cout<<"Enter a valid amount !!!";
			cin.get();
			cin.get();
			withdraw();
		}
		else{
			balance -= c;
			cout<<fgB::cyan;
			cout<<endl<<endl<<"TRANSACTION COMPLETED SUCCESSFULLY !!!"<<endl<<endl;
			cin.get();
			cin.get();
			clear();
		}
		return ;
	}

	void close(){
		cout<<endl<<endl;
		cout<<fgB::red;
		cout<<"ARE YOU SURE YOU WANT TO CLOSE YOUR ACCOUNT Y/N ???"<<endl<<endl;
		cout<<"-------> ";
		char a;
		cout<<fgB::yellow;
		cin>>a;

		if(a=='Y'){
			cout<<fgB::cyan;
			cout<<"Enter your password to confirm :- ";
			int z;
			cout<<fg::reset;
			cin>>z;

			if(z==password){
				cout<<fgB::green;
				cout<<"ACCOUNT CLOSED SUCCESSFULLY!!!"<<endl<<endl;
			}
			else{
				cout<<fgB::red;
				cout<<"Password incorrect !!! ";
			}
		}
		cin.get();
		cin.get();
		clear();	
		return ;
	}

	void check_balance(){
		cout<<endl<<endl;
		cout<<fgB::green;
		cout<<"Available balance in the account is = "<<balance<<endl<<endl;
		cin.get();
		cin.get();
		clear();
		return;
	}

	void password_change(){
		cout<<fgB::cyan;
		cout<<"Enter your existing password :- ";
		cout<<fgB::yellow;
		int z;
		cin>>z;

		if(z==password){
			cout<<fgB::red;
			cout<<endl<<endl<<"Enter new password :- ";
			cout<<fgB::yellow;
			int p;
			cin>>p;
			password = p;
		}
		else{
			clear();
			cout<<fgB::red;
			cout<<"Password incorrect !!! "<<endl<<"TRY AGAIN !!!"<<endl<<endl;
			password_change();
		}
		cout<<fgB::green<<"Password Changed";
		cin.get();
		cin.get();
		clear();
		return ;
	}

	int option(){
		cout<<fgB::blue;
		cout<<"HELLO "<<this->name<<"\n";
		cout<<fgB::red;
		cout<<"___________________________________________"<<endl<<endl;
		cout<<fgB::green;
		cout<<"1. Deposit Amount "<<endl<<endl;
		cout<<"2. Withdraw Amount "<<endl<<endl;
		cout<<"3. Change Password"<<endl<<endl;
		cout<<"4. Close Account"<<endl<<endl;
		cout<<"5. Check Balance "<<endl<<endl;
		cout<<"6. Exit \n";
		cout<<fgB::yellow;
		cout<<"Option :- ";
		cout<<fg::reset;
		int x;
		cin>>x;
		clear();
		if(x==1){
			deposit();
			return option();
		}

		else if(x==2){
			withdraw();
			return option();
		}

		else if(x==3){
			password_change();
			return option();
		}

		else if(x==4){
			close();
			return -1;
		}

		else if(x==5){
			check_balance();
			return option();

		}
		else if(x==6)
			return 0;
		else{
			cout<<fgB::red;
			cout<<"Type a valid number!!!"<<endl<<endl;
			return option();
		}
	}

	void display(){
		cout<<"A/c:"<<acc_no<<"\nPass:"<<password<<"\n"<<balance;
	}
};

class new_customer{

public:

	void start(){
		existing_cust e;
		cout<<endl<<endl;
		cin.get();
		cout<<fgB::gray;
		cout<<"\t\tNEW ACCOUNT FORM\n";
		cout<<fgB::blue;
		cout<<"Name :-  ";
		cout<<fgB::cyan;
		cin.getline(e.name,100);
		cout<<fgB::blue;
		try{
			cout<<"Age :-  ";
			cout<<fgB::cyan;
			cin>>e.age;
			if(e.age < 18){
				throw(e);
				
			}
		}
		catch(existing_cust e){
			cout<<fgB::red;
			cout<<"You must be atleast 18 years to open an account in this bank";
			cin.get();
			cin.get();
			clear();
			return;
		}
		
		option(e);
	}

	void balance_set(existing_cust &e){
		cout<<fgB::blue;
		cout<<"Enter initial Deposit Amount :- ";
		int y;
		cout<<fgB::cyan;
		cin>>y;
		e.balance += y;

		return;
	}
	void allocateNumber(existing_cust &e){
		fstream ob;
        ob.open("Accounts.dat",ios::in);
        existing_cust h;
        int acnt=1;
        while(ob.read((char*)&h,sizeof(h)))
        {
        	acnt++;
        }
    	ob.close();		
		e.acc_no=110000+acnt;
		acnt++;
	}

	void set_password(existing_cust &e){
		tr:
		cout<<fgB::blue;
		cout<<"ENTER NEW PASSWORD : ";
		int p;
		cout<<fgB::cyan;
		cin>>p;
		cout<<fgB::blue;
		cout<<"CONFIRM YOUR PASSWORD : ";
		int p1;
		cout<<fgB::cyan;
		cin>>p1;

		if(p1!=p){
			clear();
			cout<<fgB::red;
			cout<<"NOT CONFIRMED ... retry!!!"<<endl<<endl;
			goto tr;
		}
		e.password=p;
		return;
	}

	void option(existing_cust &e){
		cout<<fg::green;
		cout<<" Follow the steps as prompted !!! "<<endl<<endl;
		cout<<fg::red;
		cout<<"_______________________________________"<<endl<<endl;
		cout<<fgB::gray;
		cout<<"STEP 1: Add initial amount in account"<<endl<<endl;
		balance_set(e);
		cout<<fgB::gray;
		cout<<endl<<endl<<"STEP 2: Password Setup "<<endl<<endl;
		set_password(e);
		allocateNumber(e);
		cout<<fg::red;
		cout<<"_______________________________________"<<endl<<endl;
		cout<<fgB::green;
		cout<<endl<<endl<<"ACCOUNT SET UP DONE !!!"<<endl<<endl;
		cout<<"Account Number:"<<e.acc_no;
		cout<<fgB::magenta;
		cout<<endl<<endl<<"\t\t\t THANK YOU !!!"<<endl<<endl;
		cin.get();
		cin.get();
		clear();
		fstream ob;
        ob.open("Accounts.dat",ios::app|ios::binary);
        ob.write((char*)&e,sizeof(e));
        ob.close();
	}


};
