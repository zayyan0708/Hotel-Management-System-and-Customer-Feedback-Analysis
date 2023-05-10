#include <conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>
#include<stack>
using namespace std; 	 
bool RTest_DataofStrings(string str){
    try
	{
		for (int i = 0; i < str.size(); i++)
		{
		if (str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){return true;}
        else
		{ throw(str); }
        }	
	}
    catch(string str)
	{
		cout<<str<<"  is invalid!!!!"<<endl;
		return false;
	}    
	}
bool Rcheck = true;
struct RNode   //structure of RNode//
{
 int id;
 string name;
 string phoneno;
 string Designation;
 string cnic;
 int Salary;
 RNode*next;
};
class RoomService{
 RNode* head;
 RNode* tail;
 public:
 	RoomService()
	 {
	 	head=NULL;
	 	tail=NULL;
	 }
bool RTest_code(int num,int count){
			try{
		int digit,temp,i;
		temp=num;
		i=0;
		do{
			digit=temp/10;
			temp=digit;
			i++;
		}while(digit!=0);
		if(i!=count){throw"code_no";}
		else{return true;}
	}
	catch(const char* str){
		cout<<str<<"is invalid should contain"<<count<<"digit!!"<<endl;
		cout<<"\n\t\t\tEnter again"<<endl;
		return false;
	}
}	 
void Insert_RoomSer(stack<string>* s)    //Adds record of student//
{
		string enames,ecnic,ephone,edesignation;
int esal,iide;
 RNode* p;
 p=new RNode;
 Z:
 cout<<"Enter ID of staff Member:";
 cin>>p->id;
 if(RTest_code(p->id,5)==false)
   {
	do{cout<<"\n\t\t\tEnter ID of staff Member: ";cin>>p->id;} while(RTest_code(p->id,5)==false);
   }
	   fstream d;
     d.open("RoomSer.txt",ios::in);
	 {		
		
			 while(d>>enames>>iide>>ecnic>>ephone>>edesignation>>esal){
				 if(p->id==iide)
				 {
					 cout<<"\n\t\t\tStaff Member again already taken: ";
					 d.close();
					 goto Z;
				 }
			 }
}d.close();
 fflush(stdin);
 cout<<"Enter Name of staff Member:";
 cin>>p->name;
  if(RTest_DataofStrings(p->name)==false)
  {
	do{cout<<"\n\t\t\tEnter name of staff Member :";cin>>p->name;} while(RTest_DataofStrings(p->name)==false);
	}
 fflush(stdin);
  cout<<"Enter CNIC Number of staff Member:";
 cin>>p->cnic;
 fflush(stdin);
 cout<<"Enter Phone Number of staff Member:";
 cin>>p->phoneno;
 fflush(stdin);
 string st;int ss;
 fstream v;v.open("S.txt",ios::in);
 while(v>>st>>ss){if(st=="Hou"){p->Salary=ss;}}
 //cout<<"Enter Salary of staff Member:";
 cout<<"Salary: "<<p->Salary;
 p->Designation="ROOM_SERVICE";
 p->next=NULL;
 
//  if(Rcheck)
//  {
//   head = p;
//   tail = p;
//   Rcheck = false;
//  }
//  else
//  {
//   tail->next=p;
//   tail=p;
//  }
 cout<<endl<<"Recored Entered-------------";
string msg,notific;
msg=" Is Appoint As A Room Servicer By A Manager.";
notific=p->name+msg;
s->push(notific);
 	fstream f;
    f.open("RoomSer.txt",ios::app);
	f<<p->name<<" "<<p->id<<" "<<p->cnic<<" "<<p->phoneno<<" "<<p->Designation<<" "<<p->Salary<<endl;
	 f.close();
 getch();
}

void Modify_RoomSer(stack<string>* s)   //modifies record of student//
{
Q:    
char ch;
	int ide,iid,a;
	bool flag=false;
 cout<<"\nEnter ID of Receptionist to MOdify Record:";
 cin>>ide;
	string enames,ecnic,ephone,edesignation;
int esal,iide;
 
do{
		fstream z,out;
z.open("RoomSer.txt",ios::in);
out.open("NewRoom.txt",ios::app);
while(z>>enames>>iide>>ecnic>>ephone>>edesignation>>esal)
{ fstream d;
       if(iide==ide){
       	flag=true;
       	cout<<"\n1:NAME\t \n2:ID\t \n3:CNIC\t \n4:PHONE NUMBER\t\n";
       	cin>>a;
       	string msg,notific;
       	switch(a){
       	case 1:
       	    cout<<"Enter Name of staff Member:";
            cin>>enames;
             if(RTest_DataofStrings(enames)==false)
             {
	           do{cout<<"\n\t\t\tEnter name of staff Member :";cin>>enames;} while(RTest_DataofStrings(enames)==false);
	         }
            out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
		    
           msg=" is Modified Of A Room Service Member.";
           notific="Name"+msg;
           s->push(notific);
		   break;	
		case 2:
			cout<<"Enter ID of staff Member:";
            cin>>iid;
             if(RTest_code(iid,5)==false)
   {
	do{cout<<"\n\t\t\tEnter ID of staff Member: ";cin>>iid;} while(RTest_code(iid,5)==false);
   }
	  
     d.open("RoomSer.txt",ios::in);
	 {		Z:
		
			 while(d>>enames>>iide>>ecnic>>ephone>>edesignation>>esal){
				 if(iid==iide)
				 {
					 cout<<"\n\t\t\tEnter ID of staff Member again already taken: ";
					 cin>>iid;
					 goto Z;
				 }
			 }
}d.close();
            ide=iid;
            out<<enames<<" "<<ide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
           msg=" is Modified Of A Room Service Member.";
           notific="ID"+msg;
           s->push(notific);
		   break;
		case 3:
			cout<<"Enter CNIC of staff Member:";
            cin>>ecnic;
            out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
           msg=" is Modified Of A Room Service Member.";
           notific="CNIC"+msg;
           s->push(notific);
		   break;
		case 4:
			cout<<"Enter PHONE NUMBER of staff Member:";
            cin>>ephone;
            out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
           msg=" is Modified Of A Room Service Member.";
           notific="Phone Number"+msg;
           s->push(notific);
		   break;         
		default:
			cout<<"\nINVALID CHOICE!!!!!!!";
		   break;   
		   }
		   
       	   //break;
	   }
	   else{
	   	out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
	   }
	   
}
z.close();
out.close();
if(flag==false)
	   {
	   	cout<<"NOT FOUND!!!!";
	   	goto Q;
	   	system("cls");
	   }
remove("RoomSer.txt");
rename("NewRoom.txt","RoomSer.txt");
cout<<"DO YOU WANT TO MODIFY ANYTHING ELSE (Y/N): ";
       	   cin>>ch;
}while(ch!='N');


}

void Search_RoomSer()   //searches record of student//
{
	Z:
		bool flag=false;
 int ide;
 cout<<"\nEnter ID of Receptionist to search:";
 cin>>ide;
	string enames,ecnic,ephone,edesignation;
int esal,iide;
 	fstream z;
z.open("RoomSer.txt",ios::in);
while(z>>enames>>iide>>ecnic>>ephone>>edesignation>>esal)
{
       if(iide==ide){
       	flag=true;
        cout<<"\nName: ";
        cout<<enames;
        cout<<"\nID:";
        cout<<iide;
        cout<<"\nCNIC:";
        cout<<ecnic;
        cout<<"\nPhone Number:";
        cout<<ephone;
        cout<<"\nDESIGNATION: ";
        cout<<edesignation;
        cout<<"\nSalary:";
        cout<<esal;
	   break;
	   }
}
if (flag==true)
{
}
else
{
	cout<<"NOT FOUND!!!";
	goto Z;
}
}
void Delete_RoomSer(stack<string>* s,string des)    //deletes record of a student//
{
	string enames,ecnic,ephone,edesignation;
    int esal,ide,id;
    cout<<"\nEnter ID of Receptionist whose record you want to delete:";
 cin>>id;
 	fstream z,out;
z.open("RoomSer.txt",ios::in);
out.open("New.txt",ios::app);
while(z>>enames>>ide>>ecnic>>ephone>>edesignation>>esal){
	if(ide==id){
		cout<<"RECORD DELTED-----------\n";
	     string msg,notific;
        msg=" Who Is A Room Servicer Is Fired By A .";
        notific=enames+msg+des;
        s->push(notific);
	}else{
	out<<enames<<" "<<ide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
	}
}
z.close();
out.close();
remove("RoomSer.txt");
rename("New.txt","RoomSer.txt");
}
void Printing_RoomSer()
{
int choice;	
string enames,ecnic,ephone,edesignation;
int esal,ide;
cout<<"Display by:"<<endl<<"1. ID"<<endl<<"2. Name"<<endl<<"3. Enter choice: ";
cin>>choice;
	fstream z;
z.open("RoomSer.txt",ios::in);
head=NULL;
while(z>>enames>>ide>>ecnic>>ephone>>edesignation>>esal)
{
RNode* temp1=new RNode;
temp1->next=NULL;
RNode* temp2;
temp2=head;
temp1->name=enames; temp1->cnic=ecnic;temp1->phoneno=ephone;temp1->Designation=edesignation; temp1->id=ide;temp1->Salary=esal;
	if(head==NULL)
{
	head=temp1;
}
else
{
	while(temp2->next)
	{
		temp2=temp2->next;
	}
	temp2->next=temp1;
}
}
if (choice==1)
{	
sorting_RoomSer();
}
if (choice==2)
{
	insertionSort(&head);
}
RNode* temp3=head;
while(temp3!=NULL)
{

      cout<<"_________________________________________________";
	  cout<<"\n| Name  ->>>> "<<temp3->name<<endl;
	  cout<<"\n| STAFF ID  ->>>> "<<temp3->id<<endl;
	  cout<<"\n| CNIC  ->>>>: "<<temp3->cnic<<endl;
	  cout<<"\n| PHONE NUMBER ->>>> "<<temp3->phoneno<<endl;
	  cout<<"\n| DESIGNATION ->>>> "<<temp3->Designation;
	  cout<<"\n| SALARY  ->>>> "<<temp3->Salary;
	  cout<<"\n";
	  cout<<"_________________________________________________";
	  temp3=temp3->next;
}
}
/////////////INSERTION SORT IMPLEMENTATIONS//////////////
void insertionSort(RNode **head_ref)
{
     RNode *sorted = NULL;
     RNode *current = *head_ref;
    while (current != NULL)
    {
         RNode *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}
void sortedInsert(RNode** head_ref, RNode* new_node)
{
    RNode* current;
    if (*head_ref == NULL || (*head_ref)->name >= new_node->name)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->name < new_node->name)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
void sorting_RoomSer()
    {
        string t;
        int s;
        
        RNode*temp = head;
        while(temp!=NULL)
        {
            RNode*min = temp;
            RNode*temp2 = temp->next;
            while(temp2!=NULL)
            {
                if(min->id>temp2->id)
                {
                    min = temp2;
                }
                temp2 = temp2->next;
            }
            t = temp->name;
            temp->name = min->name;
            min->name= t;
            s = temp->id;
            temp->id = min->id;
            min->id= s;
            t = temp->cnic;
            temp->cnic= min->cnic;
            min->cnic= t;
            t = temp->phoneno;
            temp->phoneno= min->phoneno;
            min->phoneno=t;
			s = temp->Salary;
            temp->Salary = min->Salary;
            min->Salary= s;
			temp=temp->next;
        }
    }
	int *rs_salary_show()
	{
		string enames,ecnic,ephone,edesignation;
		int esal,ide;
		int *rs;
		fstream z2;
		rs=new int[get_count()];
		z2.open("RoomSer.txt",ios::in);
		for(int i=0;i<get_count();i++){z2>>enames>>ide>>ecnic>>ephone>>edesignation>>esal;rs[i]=esal;}
		z2.close();
		return rs;
	}
	int get_count()
	{
		int countr=0;
		string enames,ecnic,ephone,edesignation;
		int esal,ide;
		fstream z;
		z.open("RoomSer.txt",ios::in);
		//head=NULL;
		while(z>>enames>>ide>>ecnic>>ephone>>edesignation>>esal)
		{
			countr++;
		}
		z.close();
		return countr;
	}
};

