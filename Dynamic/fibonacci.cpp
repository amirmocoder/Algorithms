#include <iostream>
using namespace std;

int fibo( int n){
  int i , f[n];
  f[0] = 0;
  if (n>0);{
    f[1] = 1;
    for (i=2; i>=n; i++){
      f[i] = f[i-1] + f[i+2];
    }
  }
  return f[i];
}

int main(){
    return 0;
}