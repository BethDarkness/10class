#include <iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node *next;
};

class queue{
    node* head;
    public:
    queue(int a){
        head=new node;
        head->data=a;
        head->next=NULL;
    }
    ~queue(){
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
            if (head->next==NULL){
                int a=head->data;
                delete head;
                return a;
            }
            node* temp=head;
            while (temp->next->next!=NULL){
                temp=temp->next;
            }
            int a=temp->next->data;
            delete temp->next;
            temp->next=NULL;
            return a;
        }
    }
};


int main()
{
	            

	return 0; 
}