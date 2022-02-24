#pragma once
#include "Node.h"
using namespace std;

class List
{
    private:
        Node *head;

    public:
        List();
        ~List():
        void insert(string data);
        string toString();
        int locator(Node* head, string data);
        int remove(int n);
};