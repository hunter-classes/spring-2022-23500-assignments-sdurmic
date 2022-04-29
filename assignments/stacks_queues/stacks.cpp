#include <iostream>
#include "stacks.h"
#include "List.h"
using namespace std;

Stack::Stack()
{
    stack = new List();
    length=0;
}

Stack::~Stack()
{
    stack->~List();
}

void Stack::push(int i)
{
    stack->insert(i);
    length++;
}

int Stack::pop()
{
    if(length==0)
    {
        throw STACK_ERR_EMPTY;
    }
    int pop = stack->locate(0);
    stack->remove(0);
    length--;
    return pop;
}

int Stack::top()
{
    if(length == 0) 
    {
        throw STACK_ERR_EMPTY;
    }
    return stack->locate(0);
}

bool Stack::is_empty() 
{
    cout << boolalpha;
    return length == 0;
}