#include <conio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <dos.h>
#include <cctype>
#include <sstream>
#include <string>
#include <fstream>
using namespace std; 	 
bool CTest_DataofStrings(string str){
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
class cnode    //structure of cnode//
{
	public:
 	string name,roomtype,nicno;
 	int family,roomid,totalbill,noofdays;
 	string facilities[5];
 	cnode *next;
	cnode(){} 
};
class customer
{
	cnode *head,*lastptr;
	int n_dailyrent,s_dailyrent,d_dailyrent;
	public:
		string fac1[5];
		customer()
		{
			char rt;int rn;			
			head=NULL;
			lastptr=NULL;
			fstream r;
			r.open("rent.txt",ios::in);
			while(r>>rt>>rn)
			{
				if(rt=='N'){n_dailyrent=rn;}
				if(rt=='D'){d_dailyrent=rn;}
				if(rt=='S'){s_dailyrent=rn;}
			}
		}
	bool CTest_code(int num,int count){
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
	void add(int data,string type)    //Adds record of student//
	{
		system("cls");
 cnode *p;
 p=new cnode;
 cout<<"Enter name of customer:"<<endl;
 cin>>p->name;
  if(CTest_DataofStrings(p->name)==false)
  {
	do{cout<<"\n\t\t\tEnter name of customer :";cin>>p->name;} while(CTest_DataofStrings(p->name)==false);
	}
 fflush(stdin);
 cout<<"Enter number of family members of customer:"<<endl;
 cin>>p->family;
 fflush(stdin);
 p->roomid=data;
 p->roomtype=type;
 fflush(stdin);
 cout<<"Enter nicno of customer:"<<endl;
 cin>>p->nicno;
 cout<<"How many days will you stay: "<<endl;
 cin>>p->noofdays;
 char *a;
 a=new char[type.length()];
 strcpy(a,type.c_str());
 for(int i=0;i<5;i++)
 {
 	p->facilities[i]="NO-FACILITY";
 }
 switch(a[0])
 {
    case 'N':
 	p->totalbill=p->noofdays*normfeatures(p);
 	break;
	 case 'D':
	p->totalbill=p->noofdays*Deluxefeatures(p);
	break;
    case 'S':
	p->totalbill=p->noofdays*Suitfeatures(p);
	break;
 }
 fflush(stdin);
 p->next=NULL;
 cnode* tmp2=head;
 if(tmp2==NULL)
 {
 	head=p;
 }
 else
 {
 	while(tmp2->next)
 	{
 		tmp2=tmp2->next;
	 }
	 tmp2->next=p;
 }
 cout<<endl<<"\n\n\n\n\t\t\tRecored Entered\n";
 	fstream f;
    f.open("Customer.txt",ios::app);
	f<<p->name<<" "<<p->roomid<<" "<<p->family<<" "<<p->nicno<<" "<<p->noofdays<<" "<<p->roomtype<<" "<<p->totalbill<<" "<<p->facilities[0]<<" "<<p->facilities[1]<<" "<<p->facilities[2]<<" "<<p->facilities[3]<<" "<<p->facilities[4]<<endl;
	 f.close();   
 getch();
}
///NORMAL FEATURE DONE
int normfeatures(cnode *t)
{
	system("cls");
	char choice;
	int ftchoice;
	//int dailyrent=10000;
	cout<<"\n\n\n\n\t\t\tComplimentary features given: \n\t\t\t1. One room 2 beds\n\t\t\t2. One Air Conditioner Room\n\t\t\t3. Breakfast & Snacks only\n\t\t\t4. Room Service";
    cout<<"\n\t\t\tDo you want to add more features: (y/n) ";
	cin>>choice;
	
	if(choice=='y')
	{
	cout<<"\n\n\n\n\t\t\tAdditional Features: \n\t\t\t1. Extra Mattress - 1500 PKR\n\t\t\t2.Buffet(Lunch/Dinner) - 2300PKR per person\n\t\t\t3. Swimming Pool - 950PKR\n\t\t\t4. GYM/SUANA - 950PKR\n\t\t\t5. Cab Services - 1000PKR ";
	do
    {
	cout<<"\n\t\t\tEnter choice: ";
	cin>>ftchoice;
	switch(ftchoice)
	{
	case 1:
		n_dailyrent=n_dailyrent+1500;
		t->facilities[0]="Extra-Mattress";
		break;
	case 2:
		n_dailyrent=n_dailyrent+2300;
		t->facilities[1]="Buffet-System";
		break;
	case 3:
		n_dailyrent=n_dailyrent+950;
		t->facilities[2]="Swimming-Pool";
		break;
	case 4:
		n_dailyrent=n_dailyrent+950;
		t->facilities[3]="GYM/SUANA";
		break;
	case 5:
		n_dailyrent=n_dailyrent+1000;
		t->facilities[4]="CAB-Services";
		break;
	}
	cout<<"\n\t\t\tDo you want to add more features: (y/n) ";
	cin>>choice;
	}while(choice=='y');
	}
	return n_dailyrent;	
}
//DELUXE FEATURE DONE
int Deluxefeatures(cnode *t)
{
	system("cls");
	char choice;
	int ftchoice;
	//int dailyrent=17999;
	cout<<"\n\n\n\n\t\t\tComplimentary features given: \n\t\t\t1.One room 3 beds\n\t\t\t2. Two Air Conditioner Room\n\t\t\t3. Breakfast & Lunch\n\t\t\t4. Room Service\n\t\t\t5. Cab Services\n\t\t\t6. Swimming Pool";
    cout<<"\n\t\t\tDo you want to add more features: (y/n) ";
	cin>>choice;
	
	if(choice=='y')
	{
	cout<<"\n\n\n\n\t\t\tAdditional Features: \n\t\t\t1. Extra Mattress - 1500 PKR\n\t\t\t2.Buffet(Brunch/Dinner) - 2300PKR per person\n\t\t\t3. GYM/SUANA - 950PKR";
	do
    {
	cout<<"\n\t\t\tEnter choice: ";
	cin>>ftchoice;
	switch(ftchoice)
	{
		
	case 1:
		d_dailyrent=d_dailyrent+1500;
		t->facilities[0]="Extra-Mattress";
		break;
	case 2:
		d_dailyrent=d_dailyrent+2300;
		t->facilities[1]="Buffet-System";
		break;
	case 3:
		d_dailyrent=d_dailyrent+950;
		t->facilities[0]="GYM/SUANA";
		break;
	}
	cout<<"\n\t\t\tDo you want to add more features: (y/n) ";
	cin>>choice;
	}while(choice=='y');
	}
	return d_dailyrent;	
}
//SUIT FEATURES DONE
int Suitfeatures(cnode *t)
{
	system("cls");
	char choice;
	int ftchoice;
	//int dailyrent=28999;
	cout<<"\n\n\n\n\t\t\tComplimentary features given: \n\t\t\t1.One room 3 beds\n\t\t\t2. Two Air Conditioner Room\n\t\t\t3. All time buffet\n\t\t\t4. Room Service\n\t\t\t5. Cab Services\n\t\t\t6. Swimming Pool\n\t\t\t7.GYM/SUANA\n\t\t\t8. Beach View Balcony";
    cout<<"\n\n\t\t\tDo you want to add more features: (y/n) ";
	cin>>choice;
	
	if(choice=='y')
	{
	cout<<"\n\n\n\n\t\t\tAdditional Features:\n\t\t\t1. Extra Mattress - 1500PKR\n\t\t\t2. Live BarbeQue/Seafood - 4999PKR\n\t\t\t3. Cuisine hotel - 8999PKR ";
	do
    {
	cout<<"Enter choice: ";
	cin>>ftchoice;
	switch(ftchoice)
	{
		
	case 1:
		s_dailyrent=s_dailyrent+1500;
		t->facilities[0]="Extra-Mattress";
		break;
	case 2:
		s_dailyrent=s_dailyrent+4999;
		t->facilities[1]="Live-BarbeQue";
		break;
	case 3:
		s_dailyrent=s_dailyrent+8999;
		t->facilities[2]="Cuisine-Hotel";
		break;
	}
	cout<<"\n\t\t\tDo you want to add more features: (y/n) ";
	cin>>choice;
	}while(choice=='y');
	}
	return s_dailyrent;	
}
//MODIFY FUNCTION DONE
void modify()   //modifies record of student//
{
	char v;
	do{
	system("cls");
	Z:
		fstream fin;
		fstream fout;
string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
int roomno,days,familyno,bill;
fstream z;
int key;
int flag=0;

cout<<"\n\t\t\tEnter Room ID of Customer: ";
cin>>key;
z.open("Customer.txt",ios::in);
head=NULL;
while(z>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)
{
	if(roomno==key)
	{
		flag=1;
	}

}
z.close();
	if(flag==0)
	{
		cout<<"\n\t\t\tInvalid Key Entered!!\n";
		goto Z;
	}
fin.open("Customer.txt");
fout.open("Newcustomer.txt",ios::app|ios::out);
fin.seekg(0, ios::beg);
int ch;
while(fin>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)
{
	if(roomno!=key)
	{
fout<<names<<" "<<roomno<<" "<<familyno<<" "<<nicnum<<" "<<days<<" "<<roomt<<" "<<bill<<" "<<fac1<<" "<<fac2<<" "<<fac3<<" "<<fac4<<" "<<fac4<<endl;
	}
	else
	{
		cout<<"\n\n\n\n\t\t\t1. Name\n\t\t\t2. NIC number\n\t\t\t3. No of Days\n\t\t\tEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			
		case 1:
			cout<<"Enter new Name: ";
			cin>>names;
			 if(CTest_DataofStrings(names)==false)
              {
              	do{cout<<"\n\t\t\tEnter name of customer :";cin>>names;} while(CTest_DataofStrings(names)==false);
	          }
            fout<<names<<" "<<roomno<<" "<<familyno<<" "<<nicnum<<" "<<days<<" "<<roomt<<" "<<bill<<" "<<fac1<<" "<<fac2<<" "<<fac3<<" "<<fac4<<" "<<fac4<<endl;
        break;
		case 2:
		    cout<<"Enter new NIC number: ";
		    cin>>nicnum;
		    fout<<names<<" "<<roomno<<" "<<familyno<<" "<<nicnum<<" "<<days<<" "<<roomt<<" "<<bill<<" "<<fac1<<" "<<fac2<<" "<<fac3<<" "<<fac4<<" "<<fac4<<endl;
		break;
		case 3:
		    cout<<"Enter number of days: ";
		    int ndays;
		    cin>>ndays;
		    bill=bill/days;
		    bill=ndays*bill;
		    fout<<names<<" "<<roomno<<" "<<familyno<<" "<<nicnum<<" "<<days<<" "<<roomt<<" "<<bill<<" "<<fac1<<" "<<fac2<<" "<<fac3<<" "<<fac4<<" "<<fac4<<endl;
		break;
		}
		}
	}
    fin.close();
	fout.close();
	remove("Customer.txt");
	rename("Newcustomer.txt", "Customer.txt");
	
	cout<<"\nDo you want to modify something else(y/n): ";
	fflush(stdin);
	cin>>v;
	}while(v=='y');
}
void Search() 
{
	
	Z:
		bool flag=false;
string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
int roomno,days,familyno,bill;
 int ide;
 cout<<"\n\n\n\n\t\t\tEnter room id of customer to search:";
 cin>>ide;
	string enames,ecnic,ephone,edesignation;
 	fstream z;
z.open("customer.txt",ios::in);
while(z>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)
{
       if(roomno==ide){
       	flag=true;
       	system("cls");
	   cout<<"\n\tNAME";
	   cout<<"\tROOM ID";
	   cout<<"\tFAMILY#";
	   cout<<"\t     NICNUM";
	   cout<<"\tTYPE";
	   cout<<"\tBILL";
	   cout<<"\tFACILTY";
	   cout<<"\t\t     FACILITY";
	   cout<<"\t        FACILITY";
	   cout<<"\tFACILITY";
	   cout<<"\tFACILITY";
	  cout<<"\n\t"<<names;
	  cout<<"\t"<<roomno;
	  cout<<"\t"<<familyno;
	  cout<<"\t\t"<<nicnum;
	  cout<<"\t"<<roomt;
	  cout<<"\t"<<bill;
	  cout<<"\t"<<fac1;
	  cout<<"\t     "<<fac2;
	  cout<<"\t"<<fac3;
	  cout<<"\t"<<fac4;
	  cout<<"\t"<<fac5;
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
bool IsCheck(string ename,int eroom){
 fstream z;
 string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
int roomno,days,familyno,bill;
z.open("Customer.txt",ios::in);
while(z>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)
{
	if(roomno==eroom&&names==ename)
	{
		z.close();
		return true;
	}
}
return false;
z.close(); 
}
bool del(string ename,int eroom) 
{
	fstream z;
	z.open("Customer.txt",ios::in);
	fstream temp;
	temp.open("Garbage.txt",ios::out);
 	string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
	int roomno,days,familyno,bill;
	while(z>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)
	{
	if(roomno!=eroom&&names!=ename){temp<<names<<" "<<roomno<<" "<<familyno<<" "<<nicnum<<" "<<days<<" "<<roomt<<" "<<bill<<" "<<fac1<<" "<<fac2<<" "<<fac3<<" "<<fac4<<" "<<fac5<<" "<<endl;}
	}
	z.close();
	temp.close();
	remove("Customer.txt");
	rename("Garbage.txt", "Customer.txt");
}
////////PRINTING SORTED DATA OF CUSTOMERS///////////////////////
void Printing()
{
	system("cls");
int choice;	
string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
int roomno,days,familyno,bill;
cout<<"\n\n\n\n\t\t\tDisplay by:"<<endl<<"\n\t\t\t1. Room ID"<<endl<<"\n\t\t\t2. Customer Name"<<endl<<"\n\t\t\t3. Enter choice: ";
cin>>choice;

{
	//cout<<"\n\n\n\n\t\t\tDATA SORTING USING ROOM ID: ";
	fstream z;
z.open("Customer.txt",ios::in);
head=NULL;
while(z>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)
{
cnode* temp1=new cnode;
temp1->next=NULL;
cnode* temp2;
temp2=head;
temp1->name=names;temp1->roomid=roomno;temp1->roomtype=roomt;temp1->nicno=nicnum;temp1->noofdays=days;temp1->totalbill=bill;temp1->family=familyno;temp1->facilities[0]=fac1;temp1->facilities[1]=fac2;temp1->facilities[2]=fac3;temp1->facilities[3]=fac4;temp1->facilities[4]=fac5;
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
if(choice==1){selection_sorting();}
if(choice==2){insertionSort(&head);}

system("cls");
cnode* temp3=head;

cout<<"\n\tNAME";
cout<<"\tROOM ID";
cout<<"\tFAMILY#";
cout<<"\tNICNUM";
cout<<"\t\tTYPE";
cout<<"\tBILL";
cout<<"\t\tFACILTY";
cout<<"\t\t     FACILITY";
cout<<"\t        FACILITY";
cout<<"\tFACILITY";
cout<<"\tFACILITY";
while(temp3!=NULL)
{
	  cout<<"\n\t"<<temp3->name;
	  cout<<"\t"<<temp3 ->roomid;
	  cout<<"\t"<<temp3->family;
	  cout<<"\t"<<temp3->nicno;
	  cout<<"\t"<<temp3->roomtype;
	  cout<<"\t"<<temp3->totalbill;
	  cout<<"\t\t"<<temp3->facilities[0];
	  cout<<"\t     "<<temp3->facilities[1];
	  cout<<"\t"<<temp3->facilities[2];
	  cout<<"\t"<<temp3->facilities[3];
	  cout<<"\t"<<temp3->facilities[4];
	  temp3=temp3->next;
}
}

}
/////////////INSERTION SORT IMPLEMENTATIONS//////////////
void insertionSort(cnode **head_ref)
{
     cnode *sorted = NULL;
     cnode *current = *head_ref;
    while (current != NULL)
    {
         cnode *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}
void sortedInsert(cnode** head_ref, cnode* new_node)
{
    cnode* current;
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
///////SELECTION SORTING IMPLEMENTATION////////////////////
void selection_sorting()
    {
        string t;
        int s;
        cnode *temp = head;
        while(temp!=NULL)
        {
            cnode *min = temp;
            cnode *temp2 = temp->next;
            while(temp2!=NULL)
            {
                if(min->roomid>temp2->roomid)
                {
                    min = temp2;
                }
                temp2 = temp2->next;
            }
            t = temp->name;
            temp->name = min->name;
            min->name= t;
            t = temp->roomtype;
            temp->roomtype = min->roomtype;
            min->roomtype= t;
            s = temp->family;
            temp->family = min->family;
            min->family= s;
            s = temp->roomid;
            temp->roomid = min->roomid;
            min->roomid= s;
            t = temp->nicno;
            temp->nicno= min->nicno;
            min->nicno=t;
            t = temp->facilities[0];
            temp->facilities[0]= min->facilities[0];
            min->facilities[0]=t;
            t = temp->facilities[1];
            temp->facilities[1]= min->facilities[1];
            min->facilities[1]=t;
            t = temp->facilities[2];
            temp->facilities[2]= min->facilities[2];
            min->facilities[2]=t;
            t = temp->facilities[3];
            temp->facilities[3]= min->facilities[3];
            min->facilities[3]=t;
            t = temp->facilities[4];
            temp->facilities[4]= min->facilities[4];
            min->facilities[4]=t;
            temp=temp->next;
        }
    }
	void changerent()
	{
		system("cls");
			fstream f1,f2;
			int rn,choice;char rt,k;
			cout<<"\nWhich room daily rent you want to change:\n1.Noraml\n2.Deluxe\n3.Suite\nChoice: ";
			cin>>choice;
			if(choice==1){k='N';}if(choice==2){k='D';}if(choice==3){k='S';}
			f1.open("rent.txt",ios::in);
			f2.open("tmp.txt",ios::out);
			while(f1>>rt>>rn)
			{
				if(k!=rt){f2<<rt<<" "<<rn<<endl;}
				else
				{
					cout<<"\nEnter new daily rent: ";
					cin>>rn;
					f2<<rt<<" "<<rn<<endl;
				}
			}
			f1.close();f2.close();
			remove("rent.txt");
			rename("tmp.txt","rent.txt");				
	}
	int *c_show_bill()
	{
		
		string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
		int roomno,days,familyno,bill;			
		int *billc;
		fstream z2;
		billc = new int[get_count()];
		z2.open("Customer.txt",ios::in);
		for(int i=0;i<get_count();i++){z2>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5;billc[i]=bill;}
		//for(int i=0;i<100;i++){cout<<billc[i]<<" ";}
		z2.close();
		return billc;
	}
	int get_count()
	{
		string names,roomt,fac1,fac2,fac3,fac4,fac5,nicnum;
		int roomno,days,familyno,bill;
		int countc=0;
		fstream z,z2;
		z.open("Customer.txt",ios::in);
		while(z>>names>>roomno>>familyno>>nicnum>>days>>roomt>>bill>>fac1>>fac2>>fac3>>fac4>>fac5)	
		{countc=countc+1;}
		z.close();
		return countc;
	}
};

