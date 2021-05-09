#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include "Game.h"

//globally defined variables
using namespace std;
char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
//int player = 1;
//int position = 0;
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
    system("cls");
    cout << "\n";
    cout << "\t\t\t\t\t\t *****************\n";
    cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
    cout << "\t\t\t\t\t\t *****************\n\n\n\n";
    cout << "You are playing against computer.\n\n" << endl;
    string playerName, option;
    cout << "Enter Your Name : ";
    cin >> playerName;
 
    do
    {
        while (true)
        {
            system("cls");
            drawBoard();
            if (boardCount('X') == boardCount('O')) {
                cout << "Your Turn." << endl;
                playerChoice(1);
            }
            else {
                getComputerChoice(2);
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
        cout << "Do you want to play again? " << endl;
        cin >> option;
        clearBoard();
    } while (option == "Y" || option == "y");
}

void computerVScomputer()
{
    {
        system("cls");
        cout << "\n";
        cout << "\t\t\t\t\t\t *****************\n";
        cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
        cout << "\t\t\t\t\t\t *****************\n\n\n\n";
        cout << "\t\t\t\t\t AFFLE VS FANDROID .\n\n" << endl;
        string option;

        do
        {
            while (true)
            {
                system("cls");
                drawBoard();
                if (boardCount('X') == boardCount('O')) {
                    cout << "Your Turn." << endl;
                    getComputerChoice(1);
                    Sleep(1500);
                }
                else {
                    getComputerChoice(2);
                    Sleep(1500);
                }
                char winner = checkWinner();
                if (winner == 'X') {
                    system("cls");
                    drawBoard();
                    cout << "Affle Won The Game." << endl;
                    computerHistory(-1);
                    break;
                }
                else if (winner == 'O') {
                    system("cls");
                    drawBoard();
                    cout << "Fandroid Won The Game." << endl;
                    computerHistory(1);
                    break;
                }
                else if (winner == 'D') {
                    cout << "Game is Draw." << endl;
                    computerHistory(0);
                    break;
                }
            }
            cout << " Press 'Y' to play again. " << endl;
            cin >> option;
            clearBoard();
        } while (option == "Y" || option == "y");
    }
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

    cout << "\n\n\t\tComputer History" << endl;
    cout << "\t\tWin: \t" << computerWin << endl;
    cout << "\t\tLoss: \t" << computerLoss << endl;
    cout << "\t\tDraw: \t" << computerDraw << endl;
}

void playerVSplayer()
{
    string player1, player2,option;
    system("cls");
    cout << "\n";
    cout << "\t\t\t\t\t\t *****************\n";
    cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
    cout << "\t\t\t\t\t\t *****************\n\n\n\n";
    cout << "You are playing two player mode.\n\n" << endl;
    cout << "Enter First Player Name : ";
    cin >> player1;
    cout << "Enter Second Player Name : ";
    cin >> player2;

    do
    {
        while (true)
        {
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
        cout << "Do you want to play again? " << endl;
        cin >> option;
        clearBoard();
    } while (option == "Y" || option == "y");
}

void playerChoice(int symbol )
{

    //auto begin = chrono::steady_clock::now();
    while (true) 
    {
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
    //auto end = chrono::steady_clock::now(); //time after the sorting is completed
    //auto time = end - begin; //the difference between starting time and end time is time taken to execute sorting
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

void clearBoard()
{
    //makes the array empty and resets the board
    //lets user to play again
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

void getComputerChoice(int symbol)
{
    int AImove;

    if (boardCount('X') == 0)
    {
        srand(time(0));
        AImove = rand() % 10;
    }
    else 
    {
        AImove = minimax(board);
    }
    if (symbol == 1)
    {
        board[AImove] = 'X';
    }
    else
    {
        board[AImove] = 'O';
    }
}

//Minimax algorithm
int score() {
    if (checkWinner() == 'X') { return 10; }
    else if (checkWinner() == 'O') { return -10; }
    return 0; // draw
}

int minimax(char AIBoard[9])
{
    int bestMoveScore = 1000; 
    int bestmove;

    for (int i = 0; i < 9; i++)
    {
        //for (int j = 0; j < 3; j++) {
        if (AIBoard[i] == ' ')
        {
            AIBoard[i] = 'O';
            int tempMoveScore = maxSearch(AIBoard);
            if (tempMoveScore <= bestMoveScore)
            {
                bestMoveScore = tempMoveScore;
                bestmove = i;
            }
            AIBoard[i] = ' ';
        }
    }

    return bestmove;
}

int maxSearch(char AIboard[9])
{
    if (checkWinner()!='C') return score();
    int bestMove;

    int bestMoveScore = -1000;
    for (int i = 0; i < 9; i++)
    {
        if (AIboard[i] == ' ')
        {
            AIboard[i] = 'X';
            int tempMoveScore = minSearch(AIboard);
            if (tempMoveScore >= bestMoveScore)
            {
                bestMoveScore = tempMoveScore;
                bestMove = i;
            }
            AIboard[i] = ' ';
        }
    }
    return bestMoveScore;
}

int minSearch(char AIboard[9]) {
    if (checkWinner() != 'C') return score();
    int bestMove;

    int bestMoveScore = 1000;
    for (int i = 0; i < 9; i++)
    {
        if (AIboard[i] == ' ')
        {
            AIboard[i] = 'O';
            int tempMoveScore = minSearch(AIboard);
            if (tempMoveScore <= bestMoveScore)
            {
                bestMoveScore = tempMoveScore;
                bestMove = i;
            }
            AIboard[i] = ' ';
        }
    }

    return bestMoveScore;
}