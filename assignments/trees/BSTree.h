#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"
#define TREE_ERR_VALUE_NOT_FOUND 1

class BSTree
{
    private:
        Node *root;

    public:
        BSTree();
        string traverse(Node *n);
        string get_debug_string();
        void setup();
        int search(int value);
        void insert(int d);
        int rsearch(int value);
        int rsearch(int value, Node *p);
        void rinsert(int d);
        void rinsert(int d, Node *p);
};