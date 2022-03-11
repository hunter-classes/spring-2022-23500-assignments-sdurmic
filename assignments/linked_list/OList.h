#pragma once
#include "Node.h"
using namespace std;

class OList
{
    private:
        Node *head;

    public:
        OList();
        ~OList();
        void insert(int val);
        int remove(int n);
        int get(int loc);
        int length();
        string toString();
        int locator(Node* head, int data);
        bool contains(int value);
        void reverse();
};