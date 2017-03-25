// Implementation file for the IntStack class
// Adapted from Gaddis source code

#include <iostream>
#include <cassert>
#include "IntStack.h"
using namespace std;

//***********************************************
// Constructor                                  *
// This constructor creates an empty stack.     *
//***********************************************

IntStack::IntStack()
{
    top = -1;
}


//*************************************************
// Member function push pushes the argument onto  *
// the stack, unless stack is full.               *
//*************************************************

void IntStack::push(int num)
{
    assert (!isFull());  // will exit program if this happens
    top++;
    stackArray[top] = num;
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and returns it as the result.   *
//  If the stack is empty, outputs message and       *
//  returns -1                                       *
//****************************************************

int IntStack::pop()
{
    assert(!isEmpty());  // will exit program if this happens
    int num = stackArray[top];
    top--;
    return num;
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

bool IntStack::isFull() const
{
    return (top == STACK_SIZE - 1);
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

bool IntStack::isEmpty() const
{
    return (top == -1);
}

