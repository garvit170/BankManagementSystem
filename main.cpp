
#include "Customer.cpp"


using namespace std;
using namespace rang;

int main()
{	
	int ch;
	home:
        cout<<fgB::cyan<<style::bold;
	cout<<"\t\t\tWELCOME\n\n";
        cout<<style::reset;
        cout<<fgB::yellow;
	cout<<"1.Existing Account\n";
	cout<<"2.New account\n";
	cout<<"3.Exit\n";
	cin>>ch;
        cout<<fg::reset;
        clear();
	if(ch == 1){
		int tacc_no;
                cout<<fgB::cyan<<style::bold;
		cout<<"Enter your Details\n";
                cout<<style::reset;
                cout<<fgB::yellow;
                cout<<"Account number :- ";
                cout<<fgB::magenta;
		cin>>tacc_no;
		int tpassword;
                cout<<fgB::yellow;
		cout<<"Enter your password :- ";
                cout<<fgB::magenta;
		cin>>tpassword;
		fstream ob,ob2;
        ob.open("Accounts.dat",ios::in);
        ob2.open("Accounts2.dat",ios::out|ios::binary);
        int pos=0;
        existing_cust h;
        bool found=false;
        while(ob.read((char*)&h,sizeof(h)))
        {
        	
        	if(h.compareano(tacc_no)){
        		found=true;
        		if(h.comparepss(tpassword) ){
                                cout<<fg::reset;
                                clear();
        			if(h.option()==0)
        			     ob2.write((char*)&h,sizeof(h));
        		}
        		else{
                                cout<<fgB::red<<style::bold;
        			cout<<"\nIncorrect Password";
        			ob2.write((char*)&h,sizeof(h));
        		}
        	}
        	else{
        		ob2.write((char*)&h,sizeof(h));
        	}
        }
        if(!found){
                cout<<fgB::red<<style::bold;
        	cout<<"\nAccount Number not found\n";
                cout<<style::reset;
        }
        ob.close();
        ob2.close();
        remove("Accounts.dat");
        rename("Accounts2.dat","Accounts.dat");
        cin.get();
        cin.get();
        clear();
        goto home;
	}
	if(ch==2){
		new_customer n;
		n.start();
		goto home;
	}
	if(ch==3){
		return 0;
	}
	return 0;
}