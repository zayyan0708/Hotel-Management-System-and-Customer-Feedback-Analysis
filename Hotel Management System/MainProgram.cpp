#include <iostream>
#include "Owner.cpp"
/////    PROJECT MADE BY:
////     1. Muhammad Zahid 19K-0334
////     2. Muhammad Zayyan 19K-0182
////     3. Ahmed Saeed 19K-0159 
////     SECTION B
//////   HOTEL's CUSTOMER HANDLING AND FEEDBACK ANALYSIS
using namespace std;
void loadingBar();
void main_menu(int c)
{	
	char s;
	if (c==1){
		int ch;
		owner o1;
		system("cls");
		o1.To_Do();
		cout<<"\nBack(y/n): ";cin>>s;
		if(s=='y'){main_menu(c);}
		}
	if (c==2)
	{
		int ch;
		Manager m1;
		system("cls");
		m1.Menu();
		cout<<"\nBack(y/n): ";cin>>s;
		if(s=='y'){main_menu(c);}
	}
	if (c==3)
	{
		Hotel h("FAST");
		system("cls");
		h.menu();
		h.end();
		cout<<"\nBack(y/n): ";cin>>s;
		if(s=='y'){main_menu(c);}
	}
	if (c==4)
	{
		cout<<"\n\n\n\n\t\t\tTHANK YOU FOR USING THIS PROGRAM";
		exit(1);
	}
}
int main()
{
	int choice;
	system("color 70");
	printf("\n\n\t\t\tWELCOME TO HOTEL MANAGEMENT SYSTEM");
	cout<<"\n\n\t\tWait a second!\n\n\t\tLOADING SYSTEM";
loadingBar();
system("cls");
    do
	{
	F:
	int c;
	cout<<"\n\n\n\n\t\t\t1. Owner\n\t\t\t2. Manager\n\t\t\t3. Receptionist\n\t\t\t4. Exit Program\n\t\t\t   Enter your choice: ";
	cin>>c;	
	system("cls");
	if(c>4&&c<1){cout<<"\nEnter correct choice!!"<<endl;goto F;}
	main_menu(c);
	cout<<"\n1.Main Menu\n2.Exit Program\nChoice: ";
	cin>>choice;
	system("cls");
}
while(choice!=2);
system("cls");
cout<<"\n\n\n\n\t\t\tTHANK YOU FOR USING THIS PROGRAM";
}  
void loadingBar() 
{ 
    system("color 70"); 
    char a = 177, b = 219; 
    cout<<"\n\n\n\n"; 
    cout<<"\t\t\t\t\t";  
    for (int i = 0; i < 26; i++) 
        cout<<a; 
    cout<<"\r"; 
    cout<<"\t\t\t\t\t";  
    for (int i=0;i<20;i++) { 
        cout<<b; 
        Sleep(50); 
    } 
} 
