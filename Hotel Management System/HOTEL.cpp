#include <iostream>
#include "r.cpp"
#include <fstream>
#include "Account.cpp"
#include<string>
using namespace std;
class Hotel
{
    string name;
    Room *r;
    customer cus;
    queue<int> Normal;
    queue<int> Deluxe;
    queue<int> Suite;
    public:
        Hotel(string n)
        {
            name=n;
            r=NULL;
            r=restore(r);
            inorderq(r,&Normal,"Normal");
            inorderq(r,&Deluxe,"Deluxe");
            inorderq(r,&Suite,"Suite");
            //while(!Normal.empty()){cout<<Normal.front()<<endl;Normal.pop();}
        }
        void CheckIn_Room(){
			int ch,rn;
			char as;
			A:
				system("cls");
			cout<<"Enter your room type:\n1:NORMAL\n2:DELUXE\n3:SUIT\n";
			cin>>ch;
			B:
			if(ch==1)
			{   
			    if(!Normal.empty())
				{  rn=Normal.front();
                    Normal.pop(); 
				   checkio(r,rn,1);
				    
				   cus.add(rn,"Normal");	
				}else{
					system("cls");
					cout<<"NORMAL ROOM ARE ALL RESERVED!!!!!";
					cout<<"Do you want any other type of room: (y/n)";
					cin>>as;
					system("cls");
					if(as=='y')
					{
						cout<<"Enter your room type:\n2:DELUXE\n3:SUITE\n";
						cin>>ch;
						goto B;
					}
				} 
			}
			else if(ch==2)
			{
				if(!Deluxe.empty())
				{
                    rn=Deluxe.front();
                    Deluxe.pop();
				    checkio(r,rn,1);
                   cus.add(rn,"Deluxe");
				}else{
					system("cls");
					cout<<"DELUXE ROOMS ARE ALL RESERVED!!!!!";
					cout<<"Do you any other type of room: (y/n)";
					cin>>as;
					system("cls");
					if(as=='y')
					{
						cout<<"\nEnter your room type:\n1.NORMAL\n3:SUITE\n";
						cin>>ch;
						goto B;
					}
				} 
			}else if(ch==3){
				if(!Suite.empty())
				{
			        rn=Suite.front();
                    Suite.pop();
				    checkio(r,rn,1); 	
				   cus.add(rn,"Suite");
				}else{
					system("cls");
					cout<<"SUIT ROOM ARE ALL RESERVED!!!!!";
					cout<<"\nDo you any other type of room: (y/n)";
					cin>>as;
					system("cls");
					if(as=='y')
					{
						cout<<"\nEnter your room type:\n1:NORMAL\n2:DELUXE\n";
						cin>>ch;
						goto B;
					}
				} 
			}else{
				cout<<"\nENTER CORRECT CHOICE:";
				goto A;
			}
	}
    void CheckOut_Room()//how was your stay
		{   char ch;
		    bool flag=false;
		    string ename;
			string sentiment;
		    int eroom;
		    Z:
		    	system("cls");
		    	cout<<"ARE YOU SURE YOU WANT TO CHECK OUT(Y/N):";
		    	cin>>ch;
		    if(ch=='Y'){
		    	system("cls");
		    	cout<<"ENTER YOUR NAME:";
		    	cin>>ename;
		    	cout<<"ENTER YOUR ROOM NUMBER:";
		    	cin>>eroom;
		    	flag=cus.IsCheck(ename,eroom);
		    	if(flag==true){
				cus.del(ename,eroom);
                checkio(r,eroom,2);
				if(eroom>=1&&eroom<=5){Normal.push(eroom);}
                if(eroom>=6&&eroom<=10){Deluxe.push(eroom);}
                if(eroom>=11&&eroom<=15){Suite.push(eroom);}
				cout<<"\nHow was your stay in the Hotel:\n";
				fflush(stdin);
				getline(cin,sentiment);
				
				fstream sd;
				sd.open("Sentiments.txt",ios::out|ios::app);
				sd<<sentiment<<endl;
				sd.close();
	          	}
	          	else{
	          		cout<<"\nPLEASE ENTER CORRECT DATA\n";
	          		goto Z;
				  }
	          	
			}	
		}
        void menu()
        {
            S:
            int choice;
            cout<<"\nWhat do you want to do :\n1. Check IN\n2. Check OUT\n3.SEARCH A CUSTOMER\n4.MODIFY A CUSTOMER\n5.Entire MENU\nChoice: ";
            cin>>choice;
            system("cls");
            if(choice==1){CheckIn_Room();}
            if(choice==2){CheckOut_Room();}
            if(choice==3){cus.Search();	}
			if(choice==4){cus.modify();}
			if(choice==5){operate(r);}
            
            if(choice>5&&choice<1){cout<<"\nInvalid choice!!!"<<endl;goto S;}
        }
        void end()
        {
        	fstream fout;
     		fout.open("Room.txt",ios::out);fout<<"";fout.close();
		    restoref(r);
		}
};
// int main()
// {
//     Hotel h("Airover");
//     h.menu();
// }
