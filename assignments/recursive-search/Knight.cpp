#include <iostream>
#include <iomanip>
#include "Knight.h"
using namespace std;

int knightMove(int x, int y, int turn, int pos[5][5], int xTurn[8], int yTurn[8])
{
    int boardSize = 5;
	int x2, y2;

	if(turn == boardSize * boardSize)
		return 1;

	for(int a=0; a<8; a++)
    {
		x2 = xTurn[a]+x;
        y2 = yTurn[a]+y;
		if(x2>=0 && x2<boardSize && y2>=0 && y2<boardSize && pos[x2][y2] && pos[x2][y2]==-1)
        {
			pos[x2][y2] = turn;

			if(knightMove(x2, y2, turn+1, pos, xTurn, yTurn) == 1)
            {
				return 1;
			}else {
				pos[x2][y2] = -1;
			}
		}	
    }
    return 0;
}


void board(int n, int x1, int y1)
{
    int boardSize = 5;
	int pos[5][5];

	for(int i=0; i<n; i++) 
    {
		for(int j=0; j<n; j++)
        {
			pos[i][j] = -1;
		}
	}
	
	int xTurn[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int yTurn[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

	pos[x1][y1] = 0;

	if(knightMove(x1, y1, 1, pos, xTurn, yTurn) != 0)
    {
		for(int x=0; x<n; x++)
        {
			for(int y=0; y<n; y++)
            {
				cout << setw(2) << pos[x][y] << " ";
			}
			cout << endl;
		}
	}	
};
