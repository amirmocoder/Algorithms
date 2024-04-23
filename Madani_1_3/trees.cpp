struct node {
    char data;
    node *left,*right;
};

//example

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

void inorder2 (node *tree) { 
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

int search(node *tree,int x) {
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
    return NULL;
}

int insert(node **tree, int x) { 
    node *p=*tree, *t=new node(); 
    
    t->data=x;
    t->left=NULL; 
    t->right=NULL;

    if(*tree==NULL) {
        *tree=t; return;    //root
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
        else {
            if (p->right !=NULL) {
                p=p->right;
            else {
                p->right=t;
                break ;
             }
        }
}