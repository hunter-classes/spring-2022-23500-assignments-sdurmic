#pragma once
#include "List.h"

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4

class Stack 
{
    private:
        List *stack;
        int length;
    public:
        Stack();
        ~Stack();
        void push(int i);
        int pop();
        int top();
        bool is_empty();
};