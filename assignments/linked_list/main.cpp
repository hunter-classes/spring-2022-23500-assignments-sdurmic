#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[])
{
    /*
    Node *a = new Node();
    a->setData("Hello");

    Node *b = new Node("World");

    a->setNext(b);

    cout << a->getData() << "\n";
    cout << b->getData() << "\n";
    cout << a->getNext()->getData() << "\n";

    b = new Node("!");

    a->getNext()->setNext(b);

    cout << a->getData() << "\n";
    cout << a->getNext()->getData() << "\n";
    cout << a->getNext()->getNext()->getData() << "\n";

    Node *walker = a;
    cout << walker->getData() << "\n";

    walker = walker->getNext();  //walker = a->getNext();
    cout << walker->getData() << "\n";

    walker = a;
    while(walker != nullptr)
    {
        cout << walker->getData() << "\n";
        walker = walker->getNext();
    }
    */

    List *x = new List();
    x->insert("a");
    x->insert("b");
    x->insert("c");

    cout << x->toString() << "\n";
    return 0;
}