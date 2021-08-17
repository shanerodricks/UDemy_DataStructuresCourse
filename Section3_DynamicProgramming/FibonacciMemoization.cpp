#include <iostream>
using std::cout;

FibonacciAlgorithm::FibonacciAlgorithm(){
  memoizeTable.resize(100);
  memoizeTable[0] = 0;
  memoizeTable[1] = 1;
}

int FibonacciAlgorithm::fibonacciMemoize(int n) {

  if(n==0) return 0;
  if(n==1) return 1;

  if (memoizeTable[n]!=0) {
    return memoizeTable[n];
  }
  else{
    memoizeTable[n] = fibonacciMemoize(n-1) + fibonacciMemoize(n-2);
    return memoizeTable[n];
  }
}
