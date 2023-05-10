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
bool OTest_DataofStrings(string str){
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
bool check = true;
struct node    //structure of node //
{
 int id;
 string name;
 string phoneno;
 string cnic;
 string Designation;
 long int Salary;
 node *next;
};
class OtherStaff{
 node* head;
 node* tail;
 public:
 	OtherStaff(){
 		head=NULL;
 		tail=NULL;
	 }
bool OTest_code(int num,int count){
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
void Insert_Other(stack<string>* s)    //Adds record of student//
{	string enames,ecnic,ephone,edesignation;
int esal,iide;
 node *p;
 p=new node;
 Z:
 cout<<"Enter ID of staff Member:";
 cin>>p->id;
 if(OTest_code(p->id,5)==false)
   {
	do{cout<<"\n\t\t\tEnter ID of staff Member:";cin>>p->id;} while(OTest_code(p->id,5)==false);
   }
	   fstream d;
     d.open("OtherStaff.txt",ios::in);
	 {		
		
			 while(d>>enames>>iide>>ecnic>>ephone>>edesignation>>esal){
				 if(p->id==iide)
				 {
					 cout<<"\n\t\t\tStaff Member again already taken: ";
					 d.close();
					 goto Z;
				 }
			 }
}
d.close();
 fflush(stdin);
 cout<<"Enter Name of staff Member:";
 cin>>p->name;
   if(OTest_DataofStrings(p->name)==false)
  {
	do{cout<<"\n\t\t\tEnter name of staff Member :";cin>>p->name;} while(OTest_DataofStrings(p->name)==false);
	}
 fflush(stdin);
 cout<<"Enter CNIC Number of staff Member:";
 cin>>p->cnic;
 fflush(stdin);
 cout<<"Enter Phone Number of staff Member:";
 cin>>p->phoneno;
 fflush(stdin);
 int v,ss;string st;
 cout<<"Enter Designation of staff Member(1.WatchMan  2.Chef  3.Sweeper  4.Valet  5.Butler):";cin>>v;
 if(v==1){p->Designation="WatchMan";}if(v==2){p->Designation="Chef";}if(v==3){p->Designation="Sweeper";}if(v==4){p->Designation="Valet";}if(v==5){p->Designation="Butler";}
 fstream k;k.open("S.txt",ios::in);
 while(k>>st>>ss){if(st==p->Designation){p->Salary=ss;}}
 k.close();
 //cin>>p->Designation;
 fflush(stdin);
 //cout<<"Enter Salary of staff Member:";
 cout<<"Salary: "<<p->Salary;
 p->next=NULL;

//  if(check)
//  {
//   head = p;
//   tail = p;
//   check = false;
//  }
//  else
//  {
//   tail->next=p;
//   tail=p;
//  }
 cout<<endl<<"Recored Entered";
string msg,notific;
msg=" Is Appoint As A ";
notific=p->name+msg+p->Designation+" By A Manager.";
s->push(notific);	
  	fstream f;
    f.open("OtherStaff.txt",ios::app);
	f<<p->name<<" "<<p->id<<" "<<p->cnic<<" "<<p->phoneno<<" "<<p->Designation<<" "<<p->Salary<<endl;
	 f.close(); 
}



void Modify_Other(stack<string>* s)   //modifies record of student//
{  
Q:
  char ch;
	int ide,a;
	bool flag=false;
 cout<<"\nEnter ID of Receptionist to MOdify Record:";
 cin>>ide;
	string enames,ecnic,ephone,edesignation;
int esal,iide;
int iid; 	
do{
	fstream z,out;
z.open("OtherStaff.txt",ios::in);
out.open("New.txt",ios::app);
while(z>>enames>>iide>>ecnic>>ephone>>edesignation>>esal)
{fstream d;
       if(iide==ide){
       	flag=true;
       	cout<<"\n1:NAME\t \n2:ID\t \n3:CNIC\t \n4:PHONE NUMBER\t\n";
       	cin>>a;
       	string msg,notific;
       	switch(a){
       	case 1:
       	    cout<<"Enter Name of staff Member:";
            cin>>enames;
             if(OTest_DataofStrings(enames)==false)
              {
	            do{cout<<"\n\t\t\tEnter name of staff Member :";cin>>enames;} while(OTest_DataofStrings(enames)==false);
	          }
            out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
		   
           msg="Name is Modified Of A ";
           notific=msg+edesignation+" Member By A Manager.";
           s->push(notific);
		   break;	
		case 2:
			cout<<"Enter ID of staff Member:";
            cin>>iid;
             if(OTest_code(iid,5)==false)
            {
	              do{cout<<"\n\t\t\tEnter ID of staff Member:";cin>>iid;} while(OTest_code(iid,5)==false);
            }
	   
     d.open("OtherStaff.txt",ios::in);
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
           msg="ID is Modified Of A ";
           notific=msg+edesignation+" Member By A Manager.";
           s->push(notific);
		   break;
		case 3:
			cout<<"Enter CNIC of staff Member:";
            cin>>ecnic;
            out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
           msg="CNIC is Modified Of A ";
           notific=msg+edesignation+" Member By A Manager.";
           s->push(notific);
		   break;
		case 4:
			cout<<"Enter PHONE NUMBER of staff Member:";
            cin>>ephone;
            out<<enames<<" "<<iide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
           msg="Phone Number is Modified Of A ";
           notific=msg+edesignation+" Member By A Manager.";
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
			if (flag==false)
			{
			 	cout<<"NOT FOUND!!!";
			 	goto Q;
			}
remove("OtherStaff.txt");
rename("New.txt","OtherStaff.txt");
cout<<"DO YOU WANT TO MODIFY ANYTHING ELSE (Y/N): ";
       	   cin>>ch;
}while(ch!='N');

}
void Search_Other()   //searches record of student//
{
	Z:
		bool flag=false;
 int ide;
 cout<<"\nEnter ID of Receptionist to search:";
 cin>>ide;
	string enames,ecnic,ephone,edesignation;
int esal,iide;
 	fstream z;
z.open("OtherStaff.txt",ios::in);
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
void Delete_Other(stack<string>* s,string des)    //deletes record of a student//
{
 string enames,ecnic,ephone,edesignation;
    int esal,ide,id;
    cout<<"\nEnter ID of Receptionist whose record you want to delete:";
 cin>>id;
 	fstream z,out;
z.open("OtherStaff.txt",ios::in);
out.open("New.txt",ios::app);
while(z>>enames>>ide>>ecnic>>ephone>>edesignation>>esal){
	if(ide==id){
		cout<<"RECORD DELTED-----------\n";
		 string msg,notific;
        msg=" Is Fired By A ";
        notific=enames+" Who Is A "+edesignation+msg+des;
        s->push(notific);
	}else{
	out<<enames<<" "<<ide<<" "<<ecnic<<" "<<ephone<<" "<<edesignation<<" "<<esal<<endl;
	}
}
z.close();
out.close();

remove("OtherStaff.txt");
rename("New.txt","OtherStaff.txt");
}
void Printing_Other()
{
int choice;	
string enames,ecnic,ephone,edesignation;
int esal,ide;
cout<<"Display by:"<<endl<<"1. ID"<<endl<<"2. Name"<<endl<<"3. Enter choice: ";
cin>>choice;
	fstream z;
z.open("OtherStaff.txt",ios::in);
head=NULL;
while(z>>enames>>ide>>ecnic>>ephone>>edesignation>>esal)
{
node* temp1=new node;
temp1->next=NULL;
node* temp2;
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
sorting_Other();
}
if (choice==2)
{
	insertionSort(&head);
}
node* temp3=head;
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
void insertionSort(node **head_ref)
{
     node *sorted = NULL;
     node *current = *head_ref;
    while (current != NULL)
    {
         node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}
void sortedInsert(node** head_ref, node* new_node)
{
    node* current;
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
void sorting_Other()
    {
        string t;
        int s;
        
        node *temp = head;
        while(temp!=NULL)
        {
            node *min = temp;
            node *temp2 = temp->next;
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
            t = temp->Designation;
            temp->Designation= min->Designation;
            min->Designation=t;
			s = temp->Salary;
            temp->Salary = min->Salary;
            min->Salary= s;
			temp=temp->next;
        }
    }
    int *ot_salary_show()
	{
		string enames,ecnic,ephone,edesignation;
		int esal,ide;
		int *rs;
		rs = new int[get_count()];
		fstream z2;
		z2.open("OtherStaff.txt",ios::in);
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
		z.open("OtherStaff.txt",ios::in);
		//head=NULL;
		while(z>>enames>>ide>>ecnic>>ephone>>edesignation>>esal)
		{
			countr++;
		}
		z.close();
		return countr;
	}
};


