#include <iostream>
using namespace std;

// Binary tree

struct node {
    char data;
    node *left,*right;
};

//example

int main() {
    node *tree,*p,*q;
    tree=new node();
    p=new node(); 
    q=new node();

    tree ->data ='A' ; 
    p ->data='B'; 
    q ->data='C'; 

    tree->left=p; 
    tree->right=NULL;

    p->left=NULL;
    p->right=q;

    q->left=NULL; 
    q->right=NULL;
}

// Traversing on a Binary tree

void preorder ( node *tree) {
    if (tree) {
        cout<< tree->data;
        preorder(tree->left);
        preorder(tree->right);         // Preorder: vLR
    }
}

void inorder ( node *tree) {
    if (tree) {
        inorder(tree->left); 
        cout<< tree->data;
        inorder(tree->right);        // Inorder: LvR
    }
}

void postorder ( node *tree) {
    if (tree) {
        postorder(tree->left); 
        postorder(tree->right);
        cout<< tree->data;            // Postorder: LRv
    }
}

#define MAX_STACK 100 
node *s[MAX_STACK];
int top = -1;

// Function to push a node onto the stack
void push(node* data) {
    if (top == MAX_STACK - 1) {
        std::cout << "Stack overflow!" << std::endl;
        return;
    }
    s[++top] = data;
}

// Function to pop a node from the stack
node* pop() {
    if (top == -1) {
        std::cout << "Stack underflow!" << std::endl;
        return nullptr;
    }
    return s[top--];
}

// Non-recursive sequential traversal

void inorder_2 (node *tree) { 
    for(;;) {
        for( ; tree ; tree=tree->left) {
           push(tree);
        }
        tree= pop();
        if(!tree) {
            break;
        }
        cout<<tree->data;
        tree=tree->right; 
    }
}

// Search X to BST

node* search(node *tree,int x) {
    node *p=tree;
    while(p!=NULL) {
        if(x < p->data) {
            p=p->left;
        }
        else if(x > p->data) {
            p=p->right;
        }
        else {
            return p;
         }
    }
    return NULL;
}

// Insert X to BST

int insert(node **tree, int x) { 
    node *p=*tree, *t=new node(); 
    
    t->data=x;
    t->left=NULL; 
    t->right=NULL;

    if(*tree==NULL) {
        *tree=t; 
        return 0 ;    //root
    }
    while(p!=NULL) {
        if(x < p->data) {
            if (p->left !=NULL) {
                p=p->left;
            }
            else {
                p->left=t;
                break ;
            }
        }
        else {
            if (p->right !=NULL) {
                p=p->right;
            }
            else {
                p->right=t;
                break ;
             }
            }
        }
    return -1;
}