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
        void insert(string data);
        void insert(int loc, string data);
        int remove(int n);
        string get(int loc);
        int length();
        string toString();
        int locator(Node* head, string data);
};