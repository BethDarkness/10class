#include <iostream>
#include <queue>
using namespace std; 
 
struct node {
    int data;
    node* left=NULL;
    node* right=NULL;
    int height;
};
 
class AVLTree {
    node* root;
    public:
    AVLTree (int data) {
        root=new node;
        root->data=data;
        root->right=NULL;
        root->left=NULL;
        root->height=1;      
    }
    bool DFS (int data, node* n) {
        if (n==NULL) {
            return false;
        }
        if (n->data==data) {
            return true;
        }
        if (DFS(data, n->left)) {
            return true;
        }
        if (DFS(data, n->right)) {
            return true;
        }
        return false;
    }
    bool BFS (int data, node* n) {
        queue <node*> A;
        A.push (root);
        while (!A.empty()) {
            node* temp=A.back();
            A.pop();
            if (temp->data==data){
                return true;
            }
            if (n->left!=NULL) {
                A.push(temp->left);
            }
            if (n->right!=NULL) {
                A.push(temp->right);
            }
        }
        return false;
    }
    node* search (int data, node* n) {
        if (n==NULL) {
            return 0;
        }
        if (n->data==data) {
            return n;
        }
        if (n->data>data) {
            return search (data, n->left);
        }
        if (n->data<data) {
            return search (data, n->right);
        }
    }
    void height (node* n) {
        int hleft;
        int hright;
        if (n->left!=NULL) {
            hleft=n->left->height;
        }
        else {
            hleft=0;
        }
        if (n->right!=NULL) {
            hright=n->right->height;
        }
        else {
            hright=0;
        }
        if (hleft<hright) {
            n->height=hright+1;
        }
        else {
            n->height=hleft+1;
        }
    }
    int diff (node* n) {
        if (n!=NULL) {
            return n->right->height - n->left->height; 
        }
        else {
            return 0;
        }
    }
    node* turn_right (node* n){
        node* p=n->right;
        n->right=p->left;
        p->left=n;
        height(n);
        height(p);
        return p;
    }
    node* turn_left (node* n){
        node* p=n->left;
        n->left=p->right;
        p->right=n;
        height(n);
        height(p);
        return p;
    }
    node* balance (node* n) {
        height(n);
        if (diff(n)==2) {
            if(diff(n->right)<0) {
                n->right=turn_left(n->right);
            }
            return turn_right(n);
        }
        if(diff(n)==-2)
        {
            if(diff(n->left)>0) {
                n->left=turn_right(n->left);
            }
            return turn_left(n);
        }
	    return n;
    }
    node* insert (int data, node* n) {
        if (n==NULL) {
            n=new node;
            n->data=data;
            n->right=NULL;
            n->left=NULL;
            n->height=1;
        }
        else {
            if (data>n->data) {
                if (n->right!=NULL) {
                    n->right=insert (data, n->right);
                }
                else {
                    n->right=new node;
                    n->right->data=data;
                    n->right->right=NULL;
                    n->right->left=NULL;
                }
            }
            else {
                if (n->left!=NULL) {
                    n->left=insert (data, n->left);
                }
                else {
                    n->left=new node;
                    n->left->data=data;
                    n->left->right=NULL;
                    n->left->left=NULL;
                }
            }
        }
        return balance(n);
    }
    void deleteTree (node* n) {
        if (n==NULL) {
            return;
        }
        deleteTree (n->left);
        deleteTree (n->right);
        delete n;
    }
    ~AVLTree() {
        deleteTree (root);
    }
};
 
int main () {
    return 0;
}
