#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BSTree.h"
using namespace std;

int main()
{
    BSTree *tree = new BSTree();
    tree->setup();

    cout << tree->rsearch(8) << endl;
    cout << tree->rsearch(15) << endl;
    cout << tree->rsearch(3) << endl;
    cout << tree->rsearch(30) << endl;
    cout << tree->rsearch(5) << endl;
    cout << tree->rsearch(20) << endl;

    try
    {
        cout << tree->rsearch(2) << endl;
    }
    catch (int e)
    {
        cout << "2 is not in the tree" << endl;
    }

    BSTree *tree2 = new BSTree();
    tree2->insert(11);
    tree2->insert(6);
    tree2->insert(9);
    tree2->insert(22);
    cout <<  tree2->get_debug_string() << "\n";
    tree2->deleteVal(6);
    cout <<  tree2->get_debug_string() << "\n";
    tree2->deleteVal(22);
    cout <<  tree2->get_debug_string() << "\n";
    return 0;
}
