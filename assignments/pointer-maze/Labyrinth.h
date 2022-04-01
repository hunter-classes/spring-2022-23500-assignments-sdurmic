#pragma once
#include <string>
using namespace std;

enum class Item
{
    NOTHING, SPELLBOOK, POTION, WAND
};

struct MazeCell
{
    Item whatsHere;

    MazeCell* north;
    MazeCell* south;
    MazeCell* east;
    MazeCell* west;
};

bool isPathToFreedom(MazeCell* start, const string& moves);
