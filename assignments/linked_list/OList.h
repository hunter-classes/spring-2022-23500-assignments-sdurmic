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
        void insert(string data);
        int remove(int n);
        string get(int loc);
        int length();
        string toString();
        int locator(Node* head, string data);
        bool contains(int value);
        void reverse();
};