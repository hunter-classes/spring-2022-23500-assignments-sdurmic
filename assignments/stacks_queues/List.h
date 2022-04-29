#pragma once
#include "Node.h"
using namespace std;

class List 
{
    private:
        Node *head;

    public:
        List();
        ~List();
        int locate(int index);
        void insert(int data);
        string toString();
        void remove(int index);
};