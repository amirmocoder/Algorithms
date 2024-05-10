#include <iostream>
using namespace std;

// stack

#define MAX_STACK 100
struct stack {
    int top;
    int items[MAX_STACK];
}s;

// Push

void push(stack *s, int x) {
    if (s->top==MAX_STACK-1) {
        cout<<"overflow";
    }
    else{
        (s->top)++;
        s->items[s->top]=x;
    }
}

// Pop

int pop(stack *s) {
    if (s->top==-1) {
        cout<<"underflow"; 
        return -1;
    }
    int x=s->items[s->top];
    (s->top)--;
    return x;
}

int main() {
    return 0;
}