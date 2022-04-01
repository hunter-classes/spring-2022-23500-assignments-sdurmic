#include "Labyrinth.h"
#include <iostream>
using namespace std;

bool isPathToFreedom(MazeCell* start, const string& moves)
{
    int magItem[3]={0, 0, 0};
    Item item=start->whatsHere;

    if(item == Item::SPELLBOOK) magItem[1] += 1;
    if(item == Item::POTION) magItem[0] += 1;
    if(item == Item::WAND) magItem[2] += 1;
   
    for(int x=0; x<moves.length(); x++)
    {
   	    char move = moves[x];

   	    if (move=='N') 
            start=start->north;

   	    else if(move=='W') 
            start=start->west;

        else if(move=='S') 
            start=start->south;

   	    else if(move=='E') 
            start=start->east;

		if (start==nullptr)
            return false;
		else
        {
			item=start->whatsHere;

			if(item==Item::SPELLBOOK)
            {	
				magItem[1]+=1;
				cout << "Spellbook discovered" << endl;
			}

			if(item==Item::POTION)
            {
				magItem[0]+=1;
				cout << "Potion discovered" << endl;
			}

			if(item==Item::WAND)
            {
				magItem[2] += 1;
				cout << "Wand discovered" << endl;
			}
		}
    }
   
    for (int x=0; x<sizeof(magItem)/sizeof(magItem[0]); x++)
    {
   	    if(magItem[x]<=0)
            return false;
    }
	return true;
}
