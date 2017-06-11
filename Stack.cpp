#include <iostream>
#include <string>

using namespace std;

struct node{
    int data;
    node *next;
};

class stack{
    node* head;
    public:
    stack (int a){
        head=new node;
        head->data=a;
        head->next=NULL;
    }
    ~stack(){
        while (head!=NULL){
            node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    void push (int a){
        if (head!=NULL){
            node* temp=new node;
            temp->data=a;
            temp->next=head;
            head=temp;
        }
    }
    int pop(){
        if (head!=NULL){
            node* temp=head;
            head=head->next;
            int a=temp->data;
            delete temp;
            return a;
        }
    }
};


int main()
{
	            

	return 0; 
}