#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>

using namespace std;
class Queue{
	int rear,front,size;
	int *queue;
	public:
		Queue(){
			
		}
		void Set_Queue(int num){
			rear=front=0;
			size=num;
			queue=new int[num];
		}
		bool isFull(){
			if(rear==size){
			  return true;
		}else{
			return false;
		}
		}
     	void EnQueue(int data){
		if(rear==size){
			cout<<"\nQUEUE IS OVERFLOWED!!!!!!!\n";
		}else{
			queue[rear]=data;
			rear++;
		}
	}
	int DeQueue(){
		if(front==rear){
			cout<<"\nQUEUE IS EMPTY!!!!!!!\n";
		}else{
			int data;
			data=queue[front];
			for(int i=0;i<rear;i++){
				queue[i]=queue[i+1];
			}
			rear--;
		return data;
		}
		
	}
	void DisplayQueue(){
		
		if(front==rear){
			cout<<"\nQUEUE IS EMPTY!!!!!!!\n";
		}
		else{
			cout<<"\n\nTHE QUEUE ELEMENTS ARE:";
			for(int i=0;i<rear;i++){
				cout<<" "<<queue[i];
			}
		}
		}
			
};
#endif
