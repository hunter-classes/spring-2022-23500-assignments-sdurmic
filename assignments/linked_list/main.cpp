#include <iostream>
#include "Node.h"
#include "OList.h"
using namespace std;

int main(int argc, char *argv[])
{
    OList *l1 = new OList();

    cout << "Insert Function: \n" << endl;
    l1->insert(1);
    cout << l1->toString() << endl; 
    l1->insert(2);
    cout << l1->toString() << endl;
    l1->insert(3);
    cout << l1->toString() << endl;
    l1->insert(4);
    cout << l1->toString() << endl;
    l1->insert(5);
    cout << l1->toString() << endl;
    l1->insert(6);
    cout << l1->toString() << endl;

    cout << "Contains Function: \n" << endl;
    cout << l1->contains(2) << endl;
    cout << l1->contains(9) << endl;
    cout << l1->contains(1) << endl;
    cout << l1->contains(6) << endl;

    cout << "Get Function: \n" << endl;
    cout << l1->get(0) << endl;
    cout << l1->get(1) << endl;
    cout << l1->get(2) << endl;
    cout << l1->get(3) << endl;
    cout << l1->get(4) << endl;

    cout << "Remove Function: \n" << endl;
    l1->remove(1);
    l1->remove(2);
    l1->remove(3);
    cout << "Removed 1,2,3: " << l1->toString() << endl;

    cout << "Reverse Function: \n";
    l1->reverse();
    cout << l1->toString() << "\n";

    cout << "Destructor: \n" << endl;
    l1->~OList();
    cout << l1->toString() << endl;
}