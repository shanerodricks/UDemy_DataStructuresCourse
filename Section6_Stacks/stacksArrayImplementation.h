#pragma once

#include <memory>

template<class t_Data>
class Stack{

  t_Data *stack = nullptr;
  int numberOfItems = 0;
  int capcity = 0;

public:

  //at beginning the array size is 1
  Stack(){
    stack = new t_Data[1];
    capcity = 1;
  }

  //we have to delete the array in the end
  ~Stack(){
    stack = new t_Data[1];
    capcity = 1;
  }

  //we have to delete the array in the endif
  ~Stack() {
    delete[] stack;
  }

  //push a given item onto the stack
  void push(const t_Data &item) {

    //resize array [O(N)]
    if(numberOfItems == capcity) {
      resize(2*capcity);
    }

    //insert given item into array
    stack[numberOfItems++] = item;
  }

  //O(1) if no need to resize
  t_Data pop() {
    //if stack may be empty
    if(isEmpty())
      throw std::out_of_range("Stack is empty.");
  }

  t_Data pop() {

    if(isEmpty())
      throw std::out_of_range("Stack is empty.");

    //item we want to pop
    t_Data itemToPop = stack[--numberOfItems];

    //if we have opped too many items: resize array
    if(numberOfItems > 0 && numberOfItems == capcity / 4) {
      resize(capacity / 2);
    }

    return itemToPop;
  }


  void reize(int _capcity) {

    t_Data *stackCopy = new t_Data[_capcity];

    for (int i = 0; i < numberOfItems; i++) {
      stackCopy[i] = stack[i];
    }

    delete[] stack;
    stack = stackCopy;
    capcity = _capcity;
  }
}
