//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main(){
//	fstream in;
//	string str;
//	in.open("Sentiments.txt",ios::in);
//	while(in>>str){
//		//getline(in,str);
//		cout<<str;
//		}
//	}
	#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fun () {
  string line1,line2;
  ifstream myfile1 ("finalReview.txt");
  ifstream myfile2 ("Sentiments.txt");
  L:
  int k;
  cout<<"\nPrint Review\n1. ONE BY ONE\n2. ALL TOGETHER\nCHOICE: ";cin>>k;system("cls");
  if(k==1)
  {
    if (myfile1.is_open()&&myfile2.is_open())
  {
    while ( getline (myfile1,line1) && getline (myfile2,line2) )
    {
      cout<<"\nReview given by user: "<<endl;  
      cout<< line2 ;
      cout<<"\nIt is: ";
      if(line1=="Good"){system("color 72");}
      if(line1=="Average"){system("color 71");}
      if(line1=="Poor"){system("color 7C");}
      if(line1=="Worst"){system("color 74");}
      cout << line1 << '\n' << "Press ENTER for next review";getchar();system("cls");
      system("color 70");
    }
    myfile1.close();
    myfile2.close();
    cout<<"\nEND OF REVIEW";getchar();system("cls");
  }

  else cout << "Unable to open file";
  }
  if(k==2)
  {
    if (myfile1.is_open()&&myfile2.is_open())
  {
    while ( getline (myfile1,line1) && getline (myfile2,line2) )
    {
      cout<<"\nReview given by user: "<<endl;  
      cout<< line2 ;
      cout<<"\nIt is: ";
      cout << line1 << '\n' ;
    }
    myfile1.close();
    myfile2.close();
    cout<<"\nEND OF REVIEW";getchar();
  }

  else cout << "Unable to open file";
  }   
  if(k<1&&k>2){goto L;}
  return ;
}

