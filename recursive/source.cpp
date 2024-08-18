#include <iostream>
#include <vector>
using namespace std;

// Factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// The largest common divisor

int lcd(int a,int b){
    if (b==0){
        return a;
    }
    else{
        return lcd(b,a%b);
    }
}

// Fibonacci sequence

int fibo(int n){
    if (n<=1){
        return n;
    }
    else{
        return fibo(n-1) + fibo(n-2);
    }
}

void fibo_2(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    return 0;
}

// the Tower of Hanoi
void towerOfHanoi(int n, a, b, c) {
    if (n == 1) {
        cout << "Move disk 1 from " << a << " to " << b << endl;
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    cout << "Move disk " << n << " from " << a << " to " << b << endl;
    towerOfHanoi(n - 1, c, b, a);
