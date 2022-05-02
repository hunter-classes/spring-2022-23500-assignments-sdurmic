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
        cout << t->rsearch(2) << endl;
    }
    catch (int e)
    {
        cout << "2 is not in the tree" << endl;
    }
}
