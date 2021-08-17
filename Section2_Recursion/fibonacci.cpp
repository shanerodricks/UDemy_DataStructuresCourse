#include <iostream>

using namespace std;

int fibonacci(int n) {

  //recursive function so this is the base case
  if(n==0) return 0;
  if(n==1) return 1;

  //this is the formula for Fibonacci numbers
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {

  cout << fibonacci(10) << endl;

  return 0;
}
