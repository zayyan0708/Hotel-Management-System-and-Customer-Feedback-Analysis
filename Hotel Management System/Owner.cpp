#include <fstream>
#include <stack>
//#include "r.cpp"
#include <stack>
#include"HOTEL.cpp"
#include"test.cpp"
#include<iostream>
using namespace std;
class owner
{
	Manager m;
	customer cus;
	Staff s; 
	Account a;
    string name,email,phonenum,nic;
    string *noty;
	stack<string> stacko;
    public:
    	int count;
    owner()
    {
    	name="MR. ABDUL BARI";
    	email="Abdul.bari@hotel.sys.pk";
    	phonenum="021111244622";
    	nic="42201-6915092-9";
    }
    int get_Size(){
    	string noti;
    	ifstream fin;
    	fin.open("stack.txt");
		while(fin>>noti)
		{
			count++;
		}
		fin.close();
		return count;
}
	void notify()
	{
		ifstream fin2;
		string noti;
		int i,size;
		size=get_Size();
		 i=0;
		noty=new string[count];
		fin2.open("stack.txt");
		while(fin2>>noti)
		{   
			noty[i]=noti;
			i++;
		}
		fin2.close();

	}
	void Notificati(){
		system("cls");
		stack<string> msg;
		ifstream fin2;
		string noti;
		//int i,size;
		//size=get_Size();
		//i=0;
		//noty=new string[count];
		fin2.open("stack.txt");
		while ( getline (fin2,noti) )
    	{
      	//cout << noti << '\n';
		  msg.push(noti);
    	}
		fin2.close();
		remove("stack.txt");
		while(!msg.empty()){cout<<msg.top()<<endl;msg.pop();}
	}
	void Salary()
	{
		H:
		int ch,ss,sk;
		string st1,st2;
		cout<<"\nWHICH STAFF SALARY YOU WANT TO CHANGE\n1. MANAGER\n2. RECEPTIONIST\n3. ROOM SERVICE\n4. VALET\n5. BUTLER\n6. CHEF\n7. SWEEPER\n8. WATCHMAN\nCHOICE: ";cin>>ch;
		if(ch==1){st2="Manager";}if(ch==2){st2="Recep";}if(ch==3){st2="MANAGER";}if(ch==4){st2="Valet";}if(ch==5){st2="Butler";}if(ch==6){st2="Chef";}if(ch==7){st2="Sweeper";}if(ch==8){st2="Watchman";}
		if(ch<1&&ch>8){goto H;}
		fstream in;in.open("S.txt",ios::in);
		fstream out;out.open("Z.txt",ios::app);
		while(in>>st1>>ss)
		{
			if(st1==st2){cout<<"\nEnter the new SALARY: ";cin>>sk;out<<st1<<" "<<sk<<endl;}
			else{out<<st1<<" "<<ss<<endl;}
		}
		in.close();out.close();
		remove("S.txt");rename("Z.txt","S.txt");
	}
	void To_Do()
	{   	string des;
			des="Owner.";
		system("cls");
		W:
		int choice;
		cout<<"\n\n\n\n\t\t\tWhat do you want to do:\n\t\t\t1.View all Customers\n\t\t\t2.Change data of room\n\t\t\t3.Fire any staff member\n\t\t\t4.View Manager\n\t\t\t5.Fire Manager\n\t\t\t6. Show All Notifications\n\t\t\t7. Accounts\n\t\t\t8. Customer FeedBack\n\t\t\t9. Change Salary\n\t\t\tChoice: ";
		N:
		cin>>choice;
		switch (choice)
		{
			case 1:
				cus.Printing();
				break;
			case 2:
				cus.changerent();
				break;
			case 3:
				int ch;
				cout<<"\n\n\n\n\t\t\tWhich staff member you want to fire:\n\t\t\t1.Receiptionist\n\t\t\t2.Room Service\n\t\t\t3.Other Staff Member\n\t\t\tChoice: ";
				K:
				cin>>ch;
				if(ch==1){s.S.Delete_Receptionist(&stacko,des);Set_NStack();}
				if(ch==2){s.R.Delete_RoomSer(&stacko,des);Set_NStack();}
				if(ch==3){s.O.Delete_Other(&stacko,des);Set_NStack();}
				if(ch<1&&ch>3){cout<<"\n\t\t\tWrong choice enter correct choice: ";goto K;}
				break;
			case 4:
				cout<<"\n::::::Current Manager::::::"<<endl;
				m.Get_MAnager();
				break;
			case 5:
				cout<<"\nManager fired!!\nEnter new manager!!"<<endl;
				m.Set_Manager(); 
				break;
			case 6: 
			Notificati();
			break;
			case 7:
			+a;
        	a.setter();
        	a.getter();
			break;
			case 8:
			fun();
			break;
			case 9:
			
			break;
			default:
				cout<<"\nEnter correct choice";
				goto N;
		}
		char c;
		cout<<"\n\n\t\t\tDo you want to do more(Y/N): ";
		cin>>c;
		system("cls");
		if(c=='Y'){goto W;}
	}
		void Set_NStack(){
             fstream in("stack.txt",ios::out|ios::app);
             while(!stacko.empty()){
             	string msg;
             	msg=stacko.top();
             	in<<msg<<endl;
             	stacko.pop();
			 }
			 in.close();
		}
};

