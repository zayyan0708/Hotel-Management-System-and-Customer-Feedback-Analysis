#include <iostream>//    Print thru inorder intialize AVL tree by filling
#include<fstream>
#include<stack>
//#include "Queue.h"
#include <queue>
using namespace std;

class Room {
   public:
  int key;
  string room_type;
  string status;
  Room *left;
  Room *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(Room *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Room *newnod(int key,int st) 
{
  bool flag=false;
  Room *node = new Room;
  node->key = key;
  if(key>=1&&key<=5){node->room_type="Normal";}
  if(key>=6&&key<=10){node->room_type="Deluxe";}
  if(key>=11&&key<=15){node->room_type="Suite";}
  if(st==1){node->status="Booked";}
  if(st==2){node->status="Available";}
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Room *rightRotate(Room *y) {
  Room *x = y->left;
  Room *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
Room *leftRotate(Room *x) {
  Room *y = x->right;
  Room *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Room *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a node
Room *insertNode(Room *node, int key,int st) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newnod(key,st));
  if (key < node->key)
    node->left = insertNode(node->left, key,st);
  else if (key > node->key)
    node->right = insertNode(node->right, key,st);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}
Room *restore(Room *node)
{
    int rn;
    string rt,rs;
    int flag=0;
    fstream fin;
    fin.open("Room.txt",ios::in);
    {
        while(fin>>rn>>rt>>rs)
        {
        	if(rs=="Booked"){node=insertNode(node,rn,1);}
        	if(rs=="Available"){node=insertNode(node,rn,2);}	
		}
    }
    fin.close();
    return node;
}

void inorder(Room *root,string st)
{
	if(root)
	{
		inorder(root->left,st);
		if(root->status==st){cout<<"Room number: "<<root->key<<"\tRoom type: "<<root->room_type<<"\tRoom status: "<<root->status<<endl;}
		if(st=="All"){cout<<"Room number: "<<root->key<<"\tRoom type: "<<root->room_type<<"\tRoom status: "<<root->status<<endl;}
        inorder(root->right,st);
	}
}
void inorderr(Room *root,string rt,string rs)
{
	if(root)
	{
		inorderr(root->left,rt,rs);
		if(root->room_type==rt&&root->status==rs){cout<<"Room number: "<<root->key<<"\tRoom type: "<<root->room_type<<"\tRoom status: "<<root->status<<endl;}
		inorderr(root->right,rt,rs);
	}
}
void inorderq(Room *root,queue<int>* N,string rt)
{
	if(root)
	{
		inorderq(root->left,N,rt);
		if((root->status=="Available")&&root->room_type==rt){N->push(root->key);}
    inorderq(root->right,N,rt);
	}
}

void operate(Room *root)
{
    int ch;
    Z:
    	system("cls");
    cout<<"\nWhat operation do you perform:\n1. Print Non-Booked rooms\n2. Print Booked rooms\n3. Print all rooms"<<endl<<"Choice: ";
    cin>>ch;
    
    if(ch==1){system("cls");cout<<"Room no\t\tRoom Type\t\tRoom Status"<<endl;inorder(root,"Available");}
    if(ch==2){system("cls");cout<<"Room no\t\tRoom Type\t\tRoom Status"<<endl;inorder(root,"Booked");}
    if(ch==3){system("cls");cout<<"Room no\t\tRoom Type\t\tRoom Status"<<endl;inorder(root,"All");}
    if(ch>3&&ch<1){cout<<"\nWrong choice!! Enter correct choice";goto Z;}
}
void operater(Room *root,int rt)
{
  {cout<<"Room no\t\tRoom Type\t\tRoom Status"<<endl;inorder(root,"Available");}
}
void checkio(Room *root,int rn,int k)   //THIS IS A CHECK IN FUNCTION OR CAN BE USE AS A CHECKOUT FUNCTION
{
	if(root)
	{
		checkio(root->left,rn,k);
		if(rn==root->key&&k==1){root->status="Booked";}
    if(rn==root->key&&k==2){root->status="Available";}
		checkio(root->right,rn,k);
	}
}

void restoref(Room *root)
{
    if(root)
	{
		restoref(root->left);
        fstream fout;
        fout.open("Room.txt",ios::out|ios::app);
        fout<<root->key<<" "<<root->room_type<<" "<<root->status<<endl;
        fout.close();
    restoref(root->right);
	}
}

// int main()
// {
//     fstream f;
//     Room *r;
//     r=NULL;
//     r=restore(r);
//     operate(r);
//     check(r,11,1);
//     operate(r);
//     fstream fout;
//     fout.open("Room.txt",ios::out);fout<<"";fout.close();
//     restoref(r);
// }
