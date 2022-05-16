#include <iostream>
#include "Node.h"
#include "BSTree.h"
using namespace std;

int main()
{
    BSTree *tree = new BSTree();
    tree->setup();
    
    cout << "Search Test" << endl;
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

    cout << endl << "Insert and Delete Test:" << endl;
    BSTree *tree2 = new BSTree();
    tree2->insert(11);
    tree2->insert(6);
    tree2->insert(9);
    tree2->insert(22);
    cout <<  tree2->get_debug_string() << "\n";
    tree2->deleteVal(6);
    cout << "delete 6 -> " << tree2->get_debug_string() << "\n";
    tree2->deleteVal(22);
    cout << "delete 22 -> " << tree2->get_debug_string() << "\n";

    cout << endl << "Count Leave Test:" << endl;
    BSTree *tree3 = new BSTree();
    int count = tree3->countLeaves();
    cout << "Number of leaves -> " << count << endl;
    tree3->setup(); 
    cout << tree3->get_debug_string() << endl;
    int count2 = tree3->countLeaves();
    cout << "Number of leaves -> " << count2 << endl;
    tree3->insert(4);
    cout << tree3->get_debug_string() << endl;
    int count3 = tree3->countLeaves();
    cout << "Number of leaves -> " << count3 << endl;

    cout << endl << "Height Test:" << endl;
    BSTree *tree4 = new BSTree();
    tree4->setup();
    cout << tree4->get_debug_string() << endl;
    int height = tree4->treeHeight();
    cout << "Height of tree -> " << height << endl;
    tree4->deleteVal(5);
    cout << tree4->get_debug_string() << endl;
    int height2 = tree4->treeHeight();
    cout << "Height of tree -> " << height2 << endl;

    cout << endl << "Sum Test: " << endl;
    BSTree *tree5 = new BSTree();
    tree5->setup(); 
    cout << tree5->get_debug_string() << "\n";
    int sum = tree5->levelSum(1);
    cout << "Level 1 sum -> " << sum << "\n";
    int sum2 = tree5->levelSum(2);
    cout << "Level 2 sum -> " << sum2 << "\n";
    int sum3 = tree5->levelSum(3);
    cout << "Level 3 sum -> " << sum3 << "\n";

    return 0;
}
