#include <iostream>
using namespace std;

// Queue

#define MAX_QUEUE 100
struct queue {
    int front,rear;
    int items[MAX_QUEUE];
}q;

// Enqueue

void enqueue(queue *q,int x) {
    if (q->front==(q->rear+1)%MAX_QUEUE){
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
}

// Dequeue

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
    return -1;
}

int main(){
    return 0;
}
