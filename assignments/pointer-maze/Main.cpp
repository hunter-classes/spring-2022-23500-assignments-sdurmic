#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>
using namespace std;

const string kYourName = "Sara Durmic";
const string kPathOutOfNormalMaze = "";
const string kPathOutOfTwistyMaze = "";

int main() 
{
    MazeCell* startLocation = mazeFor(kYourName);

    /* Set a breakpoint here to explore your maze! */
    
    if (isPathToFreedom(startLocation, kPathOutOfNormalMaze))
    {
        cout << "Congratulations! You've found a way out of your labyrinth." << endl;
    }else
    {
        cout << "Sorry, but you're still stuck in your labyrinth." << endl;
    }
    
    MazeCell* twistyStartLocation = twistyMazeFor(kYourName);
    
    if (isPathToFreedom(twistyStartLocation, kPathOutOfTwistyMaze))
    {
        cout << "Congratulations! You've found a way out of your twisty labyrinth." << endl;
    } else {
        cout << "Sorry, but you're still stuck in your twisty labyrinth." << endl;
    }
    return 0;
}
