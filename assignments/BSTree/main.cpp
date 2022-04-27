#include <iostream>
#include "Node.h"
#include "BSTree.h"
using namespace std;

int main()
{
    Node *root = new Node(20);
    Node *n1 = new Node(30);
    root->setLeft(n1);
    Node *n2 = new Node(40);
    root->setRight(n2);
    Node *n3 = new Node(50);
    root->getLeft()->setLeft(n3);

    cout << root->getData() << endl;
    cout << n1->getData() << endl;
    cout << n2->getData() << endl;
    cout << n3->getData() << endl;
    
    BSTree *t = new BSTree();
    t->setup();
    cout << t->get_debug_string() << '\n';

    return 0;
}

