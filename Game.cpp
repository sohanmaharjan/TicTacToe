#include <iostream>
#include "Game.h"

//globally defined variables
using namespace std;
char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
int player = 1;
int position = 0;
int computerWin, computerDraw, computerLoss;

//draw a TicTacToe board to play
void drawBoard()
{

	cout << "\n";
	cout << "\t\t\t\t\t\t *****************\n";
	cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
	cout << "\t\t\t\t\t\t *****************\n\n\n\n";


    cout << "\t\t\t\t\t\t     |     |      \n";
    cout << "\t\t\t\t\t\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "   \n";
    cout << "\t\t\t\t\t\t_____|_____|_____ \n";
    cout << "\t\t\t\t\t\t     |     |      \n";
    cout << "\t\t\t\t\t\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "   \n";
    cout << "\t\t\t\t\t\t_____|_____|_____ \n";
    cout << "\t\t\t\t\t\t     |     |      \n";
    cout << "\t\t\t\t\t\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "   \n";
    cout << "\t\t\t\t\t\t     |     |      \n\n";


}

void playerVScomputer()
{
    string playerName, option;
    cout << "Enter Your Name : ";
    cin >> playerName;
    bool play = true;

    while (true) {
        system("cls");
        drawBoard();
        if (boardCount('X') == boardCount('O')) {
            cout << playerName << "'s Turn." << endl;
            playerChoice(1);
        }
        else {
            computerChoice();
        }
        char winner = checkWinner();
        if (winner == 'X') {
            system("cls");
            drawBoard();
            cout << playerName << " Won The Game." << endl;
            computerHistory(-1);
            break;
        }
        else if (winner == 'O') {
            system("cls");
            drawBoard();
            cout << "Computer Won The Game." << endl;
            computerHistory(1);
            break;
        }
        else if (winner == 'D') {
            cout << "Game is Draw." << endl;
            computerHistory(0);
            break;
        }
    }
}

void computerChoice()
{
    srand(time(0));
    int choice;
    do
    {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'O';
}

void computerHistory(int result)
{
    //int win, loss, draw;
    if (result < 0)
    {
        computerLoss++;
    }
    else if (result > 0)
    {
        computerWin++;
    }
    else
    {
        computerDraw++;
    }

    cout << "\n\n\t\t\t\tComputer History" << endl;
    cout << "\t\t\t\tWin: \t" << computerWin << endl;
    cout << "\t\t\t\tLoss: \t" << computerLoss << endl;
    cout << "\t\t\t\tDraw: \t" << computerDraw << endl;
    //cout << computerWin << "    " << computerLoss << "     " << computerDraw << endl;
}

void playerVSplayer()
{
    string player1, player2;
    cout << "Enter First Player Name : ";
    cin >> player1;
    cout << "Enter Second Player Name : ";
    cin >> player2;
    while (true) {
        system("cls");
        drawBoard();
        if (boardCount('X') == boardCount('O')) {
            cout << player1 << "'s Turn." << endl;
            playerChoice(1);
        }
        else {
            cout << player2 << "'s Turn." << endl;
            playerChoice(2);
        }
        char winner = checkWinner();
        if (winner == 'X') {
            system("cls");
            drawBoard();
            cout << player1 << " Won The Game." << endl;
            break;
        }
        else if (winner == 'O') {
            system("cls");
            drawBoard();
            cout << player2 << " Won The Game." << endl;
            break;
        }
        else if (winner == 'D') {
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

void playerChoice(int symbol )
{
    while (true) {
        cout << "Select Your Position(1 - 9) : ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From(1 - 9)." << endl;
        }
        else if (board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            if (symbol == 1)
            {
                board[choice] = 'X';
                break;
            }
            else
            {
                board[choice] = 'O';
                break;
            }
        }
    }
}

char checkWinner()
{
    // checking winner in horizontal/row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    // checking winner in vertical/column
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    // checking winner in diagonal
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if (boardCount('X') + boardCount('O') < 9)
        return 'C';
    else
        return 'D';
}

int boardCount(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == symbol)
            total += 1;
    }
   return total;
}



