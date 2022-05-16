#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

TEST_CASE("Search and Insert Tests") 
{
    BSTree *tree = new BSTree();
    tree->setup();

    CHECK(tree->rsearch(8) == 8);
	CHECK(tree->rsearch(15) == 15);
	CHECK(tree->rsearch(3) == 3);
	CHECK(tree->rsearch(30) == 30);

    tree->insert(77);
	CHECK(tree->rsearch(77) == 77);
}

TEST_CASE("Delete Value Tests") 
{ 
    BSTree *tree = new BSTree();
    tree->setup();

    CHECK(tree->get_debug_string() == "2, 3, 5, 8, 10, 15, 20, 30, ");
    tree->deleteVal(15);
    CHECK(tree->get_debug_string() == "2, 3, 5, 8, 10, 20, 30, ");
    tree->deleteVal(5);
    CHECK(tree->get_debug_string() == "2, 3, 8, 10, 20, 30, ");
}

TEST_CASE("Count Leaves Tests") 
{
    BSTree *tree = new BSTree();

    CHECK(tree->countLeaves() == 0);

    tree->setup();
    CHECK(tree->countLeaves() == 4);
    tree->insert(4);
    CHECK(tree->countLeaves() == 5);
}

TEST_CASE("Height Tests") 
{
    BSTree *tree = new BSTree();
    tree->setup();
    CHECK(tree->treeHeight() == 4);

    tree->deleteVal(5);
    CHECK(tree->treeHeight() == 3);
}

TEST_CASE("Level Sum Tests") 
{
    BSTree *tree = new BSTree();
    tree->setup();

    CHECK(tree->levelSum(1) == 10);
    CHECK(tree->levelSum(2) == 5 + 20);
    CHECK(tree->levelSum(3) == 3 + 8 + 15 + 30);
}