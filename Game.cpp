#include <iostream>
#include "Game.h"

//globally defined variables
using namespace std;
string board[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
int player = 1;
int position = 0;

//draw a TicTacToe board to play
void drawBoard()
{

	cout << "\n";
	cout << "\t\t\t\t\t\t *****************\n";
	cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
	cout << "\t\t\t\t\t\t *****************\n";

	cout << "Player 1) X\n";
	cout << "Player 2) O\n";

	cout << "The 3x3 grid is shown below:\n\n";

	cout << "\t\t\t\t\t\t     |     |      \n";
	cout << "\t\t\t\t\t\t  1  |  2  |  3   \n";
	cout << "\t\t\t\t\t\t_____|_____|_____ \n";
	cout << "\t\t\t\t\t\t     |     |      \n";
	cout << "\t\t\t\t\t\t  4  |  5  |  6   \n";
	cout << "\t\t\t\t\t\t_____|_____|_____ \n";
	cout << "\t\t\t\t\t\t     |     |      \n";
	cout << "\t\t\t\t\t\t  7  |  8  |  9   \n";
	cout << "\t\t\t\t\t\t     |     |      \n\n";


}
