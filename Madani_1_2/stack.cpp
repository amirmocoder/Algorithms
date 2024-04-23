#define MAX_STACK 100
struct stack {
    int top;
    int items[MAX_STACK];
}s;

void push(stack *s, int x) {
    if (s->top==MAX_STACK-1) {
        cout<<"overflow";
    }
    else{
        (s->top)++;
        s->items[s->top]=x;
    }
}

int pop(stack *s) {
    if (s->top==-1) {
        cout<<"underflow"; 
        return -1;
    }
    x=s->items[s->top];
    (s->top)--;
    return x;
}

#define MAX_QUEUE 100
struct queue {
    int front,rear;
    int items[MAX_QUEUE];
}q;

void enqueue(queue *q,int x) {
    if (q->front==(q->rear+1)%MAX_QUEUE) 
        cout<<"overflow";
    }
    else {
        if (q->front==-1) {
            q->front=0;
            q->rear=0;
        }
        else {
            q->rear=(q->rear+1)%MAX_QUEUE;
            q->items[q->rear]=x;
        }   
}

int dequeue(queue *q) {
    int x = -1;
    if (q->front==-1) {
        cout<<"underflow";
    }
    else {
        x=q->items[q->front];
        if (q->front==q->rear) {
           q->front=-1;
           q->rear=-1;
        }
        else {
            q->front=(q->front+1)%MAX_QUEUE;
        }
    return x;
}