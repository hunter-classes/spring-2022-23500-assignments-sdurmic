#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"
using namespace std;
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
        int rsearch(int val);
        int rsearch(int val, Node *root);
        void insert(int d, Node *p);
        void deleteVal(int val);
        int countLeaves(Node *node);
        int countLeaves();
        int treeHeight(Node *node);
        int treeHeight();
        int levelSum(Node *node, int lvl);
        int levelSum(int lvl);
};