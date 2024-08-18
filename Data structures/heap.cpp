#include <iostream>
using namespace std;

// Heap

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void moveUp(int a[], int i) {
    int k=i/2;
    while(k>=1 && a[k]<a[i]) {
        swap(a[k],a[i]);
        i=k;
        k=i/2;
    }
}

void insert(int a[], int i,int x) {
    a[i]=x;
    moveUp(a,i);
}

void moveDown(int a[], int n, int i ) {
    while(2*i<=n) {
        int k=2*i;
        if(k<n && a[k]<a[k+1]) {
            k++;
        }
        if(a[i]>a[k]) { 
            break;
        }
        swap(a[i],a[k]);
        i=k;
    }
}

void remove(int a[], int n) {
    swap(a[1], a[n]);
    moveDown(a,n-1, 1);
}

void makeHeap(int a[], int n){
    for(int i=n/2; i>=1; i--) {
        moveDown(a,n,i);
    }
}

void HeapSort(int a[], int n) {
    makeHeap(a,n);
    for( int i=1;i<=n-1;i++) {
        remove(a, n-i+1);
    }
}

int main(){
    return 0;
}
