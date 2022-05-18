#pragma once
#include "Node.h"
using namespace std;
#define NOT_FOUND 1

class List 
{
    private:
        Node *head;
    public:
        List();
        ~List();
        Person* locate(Person *d, int i);
        void insert(Person *d);
        void insert(Person *d, int i);
        string toString();
        void remove(int i);
        Person* search(Person *d);
        Node* getHead();
};