struct node {
    int data;
    node *next;
};

int main() {
    
    node *s,*p,*q;
    
    s =new node();
    p =new node();
    q =new node();
    
    s ->data =2;
    p ->data =1;
    q ->data =3;
    
    s ->next =p;
    p ->next =q;
    q ->next =NULL;
    
    return 0;
}

void print(node *start){
    node *p=start;
    
    while(p){
        cout << p->data;
        p=p->next;
    }
}

void insertFirst(node **start, int x) {
    node *p=new node();
    
    p ->data =x;
    p ->next=*start; 
    *start=p;
}

void insertLast(node **start, int x) {
    node *t=new node();

    t ->data =x; 
    t ->next=NULL; 
    
    if(*start==NULL) {
        *start=t;
    } 
    else {
        node *p=*start;
        while(p->next) {
            p=p->next;
            p->next=t;
}
}

void del(node **start, int x) {
    node *p,*q;
    
    p=*start;
    
    if ((*start)->data==x) {
        *start=(*start)->next;
        free(p); 
    }
    else {
        q=p->next;
        
        while (q && q->data!=x) {
            p=q;
            q=q->next;
         }
         if(q) {
             p->next=q->next;
             free(q);
         }
}

void iterat(node *start) {
    node *p=start;
    if(p) {
        do {
            cout<< p->data;
            p=p->next;
        }
        while(p!=start)
    }
}

void insertFirst(node **start, int x) { 
     node *p,*q,*t=new node(); 
     t ->data =x; 
     if(*start==NULL) { 
         *start=t; 
         (*start) ->next=*start; 
         return; 
    } 
    p=*start; 
    while (p->next!=*start) {
       p=p->next; 
    }
    p->next=t; 
    t->next=*start; 
    *start= t; 
}

struct node {
    int data;
    node *left,*right;
};

void del(node *r) {
    node *p,*q;
    
    p=r->left;
    q=r->right;
    p->right=q;
    q->left=p;
    
    free(r);
}

//1,3: (r->left)->right=r->right;
//2,4: (r->right)->left=r->left;

void insert(node *p , node *q , int x) {
    node *r=new node();

    r->data=x;
    p->right=r;
    r->left=p;
    q->left=r;
    r->right=q;
}