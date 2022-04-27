#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;


class BSTree
{
    private:
        Node *root;

    public:
        BSTree();
        void insert(int d);
        string get_debug_string();
        string get_debug_stringL(Node *n);
        string get_debug_stringR(Node *n);
        void setup();
};