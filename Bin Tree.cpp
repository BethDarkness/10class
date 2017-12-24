#include <iostream>
#include <queue>
using namespace std;
 
struct node {
    int data;
    node* left=NULL;
    node* right=NULL;
};
 
class BinTree {
    node* root;
    public:
    BinTree (int data) {
        root=new node;
        root->data=data;
        root->right=NULL;
        root->left=NULL;
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
    void insert (int data, node* n) {
        if (root==NULL) {
            root=new node;
            root->data=data;
            root->right=NULL;
            root->left=NULL;
        }
        else {
            if (data>n->data) {
                if (n->right!=NULL) {
                    insert (data, n->right);
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
                    insert (data, n->left);
                }
                else {
                    n->left=new node;
                    n->left->data=data;
                    n->left->right=NULL;
                    n->left->left=NULL;
                }
            }
        }
    }
    void deleteTree (node* n) {
        if (n==NULL) {
            return;
        }
        deleteTree (n->left);
        deleteTree (n->right);
        delete n;
    }
    ~BinTree() {
        deleteTree (root);
    }
};
 
int main () {
    return 0;
}
