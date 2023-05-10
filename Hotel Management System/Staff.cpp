#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include "Otherstaff.cpp"
#include "RoomSer.cpp"
#include "Receptionist.cpp"
using namespace std;
class Staff{
	string name,email,nic,phone,address,designation;
	int id,salary;
	public:
	
	Receptionist S;
	OtherStaff O;
	RoomService R;	
		void Setter(string fileName){
			string t;int sa;
			fstream s("S.txt",ios::in);
			while(s>>t>>sa)
			{if(t=="Manager"){salary=sa;}}
			s.close();
		fstream in(fileName.c_str(),ios::out);	
	       cout<<"ENTER ID: ";
		   cin>>id;
		   cout<<"ENTER NAME: ";
		   cin>>name;
		   cout<<"ENTER EMAIL: ";
		   cin>>email;
		   cout<<"ENTER CNIC: ";
		   cin>>nic;
		   cout<<"ENTER PHONE NUMBER: ";
		   cin>>phone;
		   cout<<"ENTER ADDRESS: ";
		   cin>>address;
		   //cout<<"ENTER DESIGNATION: ";
		   //cin>>designation;
		   designation="Manager";
		   //cout<<"ENTER SALARY: ";
		   //cin>>salary;
		   in<<name<<" "<<id<<" "<<email<<" "<<nic<<" "<<phone<<" "<<address<<" "<<designation<<" "<<salary<<endl;
		   cout<<endl;
		   in.close();		
		}
		void Getter(string fileName){
	  fstream out(fileName.c_str(),ios::in);
	  out>>name>>id>>email>>nic>>phone>>address>>designation>>salary;
	  cout<<"_________________________________________________";
	  cout<<"\n| Name  ->>>> "<<name<<endl;
	  cout<<"\n| ID  ->>>> "<<id<<endl;
	  cout<<"\n| CNIC  ->>>>: "<<nic<<endl;
	  cout<<"\n| PHONE NUMBER ->>>> "<<phone<<endl;
	  cout<<"\n| DESIGNATION ->>>> "<<designation;
	  cout<<"\n| SALARY  ->>>> "<<salary;
	  cout<<"\n";
	  cout<<"_________________________________________________";
		out.close();
		}
		
	
};
class Manager:public Staff
{
	stack<string> stack;
	
	public:
			
		void Set_Manager(){
			 
			Setter("Manager.txt");
		}
		void Get_MAnager(){
			Getter("Manager.txt");
		}
		void Menu(){
			int ch;
			cout<<"\t\t1: RECEPTIONIST\n\t\t2: ROOM SERVICE\n\t\t3: OTHER STAFF\n";
		    cout<<"ENTER YOUR CHOICE: ";
			A:
			cin>>ch;
		    switch(ch){
		    	case 1:
		         Receptionist();
		    		break;
		    	case 2:
		        Room_Service();   
		    		break;
		    	case 3:
		        Other_Staff();	
		    		break;	
		    	
				default:
		    		cout<<"\nINVLAID CHOICE!!!!!\nPLEASE RE-ENTER YOUR CHOICE: ";
		    	    goto A;
			}
		}
		void Receptionist(){
			string des="Manager.";
			int ch;
			cout<<"\t\t1:ADD NEW MEMBER\n\t\t2: MODIFY RECEPTIONIST MEMBER\n\t\t3: FIRE RECEPTIONIST MEMBER\n\t\t4: DISPLAY ALL MEMBERS\n\t\t5: SEARCH A SPECIFIC MEMBER\n";
		    cout<<"ENTER YOUR CHOICE: ";
			A:
			cin>>ch;
		    switch(ch){
		    	case 1:
		    		S.Insert_Receptionist(&stack);
		    		cout<<" "<<stack.top();
		    		break;
		    	case 2:
		    		S.Modify_Receptionist(&stack);
		    		break;
		    	case 3:
		    	
		    		S.Delete_Receptionist(&stack,des);
		    		break;
				case 4:
		    		S.Printing_Receptionist();
		    		break;	
				case 5:
		    		S.Search_Receptionist();
		    		break;		
		    	default:
		    		cout<<"\nINVLAID CHOICE!!!!!\nPLEASE RE-ENTER YOUR CHOICE: ";
		    	    goto A;
			}
			Set_Stack();
		}
		void Room_Service(){
			string des="Manager.";
			int ch;
			cout<<"\t\t1:ADD NEW MEMBER\n\t\t2: MODIFY ROOM SERVICE MEMBER\n\t\t3: FIRE ROOM SERVICE MEMBER\n\t\t4: DISPLAY ALL ROOM SERVICE MEMBERS\n\t\t5: SEARCH A SPECIFIC MEMBER\n";
		    cout<<"ENTER YOUR CHOICE: ";
			A:
			cin>>ch;
		    switch(ch){
		    	case 1:
		    		R.Insert_RoomSer(&stack);
		    		cout<<" "<<stack.top();
					break;
		    	case 2:
		    		R.Modify_RoomSer(&stack);
		    		break;
		    	case 3:
		    		R.Delete_RoomSer(&stack,des);
		    		break;
				case 4:
		    		R.Printing_RoomSer();
		    		break;	
				case 5:
		    		R.Search_RoomSer();
		    		break;		
		    	default:
		    		cout<<"\nINVLAID CHOICE!!!!!\nPLEASE RE-ENTER YOUR CHOICE: ";
		    	    goto A;
			}
			Set_Stack();
		}
		void Other_Staff(){
			string des="Manager.";
			int ch;
			cout<<"\t\t1:ADD NEW MEMBER\n\t\t2: MODIFY STAFF MEMBER\n\t\t3: FIRE STAFF MEMBER\n\t\t4: DISPLAY ALL STAFF MEMBERS\n\t\t5: SEARCH A SPECIFIC MEMBER\n";
		    cout<<"ENTER YOUR CHOICE: ";
			A:
			cin>>ch;
		    switch(ch){
		    	case 1:
		    		O.Insert_Other(&stack);
		    		cout<<" "<<stack.top();
					break;
		    	case 2:
		    		O.Modify_Other(&stack);
		    		
		    		break;
		    	case 3:
		    		O.Delete_Other(&stack,des);
		    		break;
				case 4:
		    		O.Printing_Other();
		    		break;	
				case 5:
		    		O.Search_Other();
		    		break;		
		    	default:
		    		cout<<"\nINVLAID CHOICE!!!!!\nPLEASE RE-ENTER YOUR CHOICE: ";
		    	    goto A;
			}
			Set_Stack();
		}
		void Set_Stack(){
             fstream in("stack.txt",ios::out|ios::app);
             while(!stack.empty()){
             	string msg;
             	msg=stack.top();
             	in<<msg<<endl;
             	stack.pop();
			 }
			 in.close();
		}
		int m_show_salary()
		{
			string name,email,nic,phone,address,designation;
			int id,salary;
			fstream f;
			f.open("Manager.txt",ios::in);
			f>>name>>id>>email>>nic>>phone>>address>>designation>>salary;		
			return salary;
		}
};

