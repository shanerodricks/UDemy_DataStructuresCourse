#include "stacksArrayImplementation.h"
#include <string>
#include <iostream>
using std::string;
using stud::cout;

int main()
{

  Stack<string> stack;
  stack.psuh("Adam");
  stack.push("Joe");

  cout<< stack.size() << '\n';
  return 0;
}
