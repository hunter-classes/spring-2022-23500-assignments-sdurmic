#include "Labyrinth.h"
#include <iostream>
using namespace std;

bool isPathToFreedom(MazeCell* start, const string& moves)
{
	bool wand = false;
    bool spellbook = false;
	bool potion = false;

	for(int x=0; x<moves.length(); x++)
    {
		if(moves[x]=='N')
        {
			start = start->north;
		}else if(moves[x]=='S')
        {
            start = start->south;
		}else if(moves[x]=='W')
        {
            start = start->west;
		}else if(moves[x] == 'E')
        {
            start = start->east;
		}

		if(start->whatsHere == Item::SPELLBOOK)
        {
			spellbook = true;
		}else if(start->whatsHere == Item::POTION)
        {
            potion = true;	
		}else if(start->whatsHere == Item::WAND)
        {
            wand = true;
		}
	}
	if(spellbook && potion && wand)
    {
		return true;
	}else{
		return false;
	}
}