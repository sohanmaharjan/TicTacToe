#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include "Game.h"

using namespace std;

//globally defined variables

//create an array of size 9
char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' }; 
int computerWin, computerDraw, computerLoss; //stores computer game stats against player

//draw a TicTacToe board to play
void drawBoard()
{

	cout << "\n";
	cout << "\t\t\t\t\t\t *****************\n";
	cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
	cout << "\t\t\t\t\t\t *****************\n\n\n\n";

    //place stack of 3 elements in an array to create a 3*3 matrix like structure
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

void displayMenuScreen() 
{
    system("cls");
    bool validChoice = false; //False until they enter 1,2,3 or 4.
    int choice = 0;
    string error = "";

    while (!validChoice)
    {
        cout << "\n";
        cout << "\t\t\t\t\t\t *****************\n";
        cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
        cout << "\t\t\t\t\t\t *****************\n\n\n\n";
        cout << "\n\n\n Select Game Mode" << endl << endl;
        cout << "\t1. Computer VS Player." << endl;
        cout << "\t2. Player VS Player." << endl;
        cout << "\t3. Computer VS Computer." << endl;
        cout << "\t4. Quit." << endl << endl;

        if (!error.empty()) //If the player messed up, the error string won't be empty.
        {
            cout << "\t" << error;
            cout << "\n\t" << "Just press a number on the menu screen and hit enter." << endl;
        }

        cout << "\t" << "Enter 1,2 or 3: ";
        cin >> choice;

        //There's no 0 in the menu, and < 5 gives us a limit to stay below.
        if (choice > 0 && choice < 5)
        {
            validChoice = true;
        }
        else
        {
            error = "There is no " + to_string(choice) + " in the menu option.";

            system("cls");  //Need to clear again before redrawing menu.
        }
    }

    //draw fucntion according to player's choice
    if (choice == 1)
    {
        system("cls");
        playerVScomputer();
    }
    else if (choice == 2)
    {
        system("cls");
        playerVSplayer();
    }
    else if (choice == 3)
    {
        system("cls");
        computerVScomputer();
    }
    else if (choice == 4)
    {
        system("cls");
        displayExitScreen();
    }
}

void displayExitScreen() 
{
    system("cls");

    //Run a loop of spaces that would make it seem like an animated effect 
    for (int i = 1; i < 38; i++)
    {
        cout << "\n\n\t\t\t\t\t" << "   -You're done-   " << "\n\n\n\n";
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        cout << "Thanks for playing Tic Tac Toe.";
        system("cls");
    }

    cout << "\n\n\t\t\t\t\t" << "   -You're done-   " << endl << endl;
    cout << "\n\n\t\t\t\tThanks for playing Tic Tac Toe.\n\n\n\n";
    Sleep(1000);

    cout << "\t\t\t\t\t  See you next time.\n\n\n\n\n\n" << endl << endl;

    Sleep(1000);


    return;   //No return value needed
}

void displayPreviewScreen()
{
    {
        for (int i = 0; i < 3; i++)
        {
            system("cls");
            Sleep(700);
            cout << "\n\n\t\t\t\t\t      *****************\n";
            cout << "\t\t\t\t\t         Tic-Tac-Toe\n";
            cout << "\t\t\t\t\t      *****************\n\n";
            Sleep(700);
        }
        Sleep(500);

        cout << "\n\t\t\t\t\t\t" << "  E";
        Sleep(1000);
        cout << "A ";
        Sleep(1000);
        cout << "Sports";
        Sleep(1000);
        cout << "\n\t\t\t\t\t\t" << " To ";
        Sleep(1000);
        cout << "The ";
        Sleep(1000);
        cout << "Game." << endl;
        Sleep(1000);
        cout << "\n\n\t\t\t\t\t\t   Welcome.";
        Sleep(1000);
        cout << "\n\n\t\t\t\t\t You are playing Tic Tac Toe." << endl << endl;
        Sleep(2000);

        cout << "\t\t\t\t\t\t     |     |      \n";
        cout << "\t\t\t\t\t\t  1  |  2  |  3   \n";
        cout << "\t\t\t\t\t\t_____|_____|_____ \n";
        cout << "\t\t\t\t\t\t     |     |      \n";
        cout << "\t\t\t\t\t\t  4  |  5  |  6   \n";
        cout << "\t\t\t\t\t\t_____|_____|_____ \n";
        cout << "\t\t\t\t\t\t     |     |      \n";
        cout << "\t\t\t\t\t\t  7  |  8  |  9   \n";
        cout << "\t\t\t\t\t\t     |     |      \n\n";
        Sleep(1000);

        cout << "\t\t\t\t\t\tYou know the rules." << endl;
        Sleep(1500);
        cout << "\t\t\t\t\tSelect numbers on the board to draw." << endl;
        Sleep(1500);
        cout << "\t\t\t\t\t\t  Play and enjoy." << endl;

        Sleep(3000);

        system("cls");
    }
}


//different game modes
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

            //if number of X's and O's are equal, its player 1's turn
            if (boardCount('X') == boardCount('O')) 
            {
                cout << " Your Turn." << endl;
                playerChoice(1);
            }
            else 
            {
                cout << " Computer's Turn." << endl;
                Sleep(1000);
                getComputerChoice(2);
            }
            char winner = checkWinner(); //checks after every move if any player has won (or draw)

            //checks the return value from checkWinner() function 
            if (winner == 'X') 
            {
                system("cls");
                drawBoard();
                cout <<" "<< playerName << " Won The Game." << endl;
                computerHistory(-1); //computer has lost
                break;
            }
            else if (winner == 'O') {
                system("cls");
                drawBoard();
                cout << " Computer Won The Game." << endl;
                computerHistory(1); //computer has won
                break;
            }
            else if (winner == 'D') {
                cout << " Game is Draw." << endl;
                computerHistory(0); //game ends in draw
                break;
            }
        }

        //gives player option to play again having to return to main menu
        //also allows player to go back to main menu or quit the game
        cout << "\n\n P: Play Again \t\t B: Main Menu \t\t Q: Quit" << endl;
        cout << " Enter your choice: ";
        cin >> option;
        clearBoard(); //resets the array so that player can play again
    } while (option == "P" || option == "p"); //continue looping if player decides to play again

    //go back to main menu i player presses B
    if (option == "B" || option == "b")
    {
        system("cls");
        displayMenuScreen();
    }
    //quit otherwise
    else
    {
        system("cls");
        displayExitScreen();
    }
}

void playerVSplayer()
{
    string player1, player2,option;
    system("cls");
    cout << "\n";
    cout << "\t\t\t\t\t\t *****************\n";
    cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
    cout << "\t\t\t\t\t\t *****************\n\n\n\n";
    cout << " You are playing two player mode.\n\n" << endl;
    cout << " Enter First Player Name : ";
    cin >> player1;
    cout << " Enter Second Player Name : ";
    cin >> player2;

    do
    {
        while (true)
        {
            system("cls");
            drawBoard();
            cout << "\t\t\t\t\t\t "<<player1<<" VS " << player2<<"\n\n" << endl;
            if (boardCount('X') == boardCount('O')) 
            {
                cout << " " << player1 << "'s Turn." << endl;
                playerChoice(1);
            }
            else 
            {
                cout << " " << player2 << "'s Turn." << endl;
                playerChoice(2);
            }
            char winner = checkWinner();
            if (winner == 'X') 
            {
                system("cls");
                drawBoard();
                cout <<" " << player1 << " Won The Game." << endl;
                break;
            }
            else if (winner == 'O') 
            {
                system("cls");
                drawBoard();
                cout <<" "<< player2 << " Won The Game." << endl;
                break;
            }
            else if (winner == 'D') 
            {
                cout << " Game is Draw." << endl;
                break;
            }
        }
        cout << "\n\n P: Play Again \t\t B: Main Menu \t\t Q: Quit" << endl;
        cout << " Enter your choice: ";
        cin >> option;
        clearBoard();
    } while (option == "P" || option == "p");

    if (option == "B" || option == "b")
    {
        displayMenuScreen();
    }
    else
    {
        displayExitScreen();
    }
}

void computerVScomputer()
{
    system("cls");
    cout << "\n";
    cout << "\t\t\t\t\t\t *****************\n";
    cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
    cout << "\t\t\t\t\t\t *****************\n\n\n\n";
    string option;

    do
    {
        while (true)
        {
            system("cls");
            drawBoard();
            cout << "\t\t\t\t\t\t AFFLE VS FANDROID\n\n" << endl;

            if (boardCount('X') == boardCount('O')) 
            {
                cout << " AFFLE's Turn." << endl;
                getComputerChoice(1);
                Sleep(1500);
            }        
            else 
            {
                cout << " FANDROID's Turn." << endl;
                getComputerChoice(2);
                Sleep(1500);
            }
                
            char winner = checkWinner();      
            if (winner == 'X') 
            {
                system("cls");
                drawBoard();
                cout << " Affle Won The Game." << endl;
                computerHistory(-1);
                break;
            }
            else if (winner == 'O') 
            {
                system("cls");
                drawBoard();
                cout << "Fandroid Won The Game." << endl;
                computerHistory(1);
                break;
            }
            else if (winner == 'D') 
            {
                cout << "Game is Draw." << endl;
                computerHistory(0);
                break;
            }
               
        }
        cout << "\n\n P: Play Again \t\t B: Main Menu \t\t Q: Quit" << endl;
        cout << " Enter your choice: ";
        cin >> option;
        clearBoard();

    } while (option == "P" || option == "p");
        
    if (option == "B" || option == "b")
    {
        system("cls");
        displayMenuScreen();
    }
    else
    {
        system("cls");
        displayExitScreen();
    }
}


//stores game stat of computer 
void computerHistory(int result)
{
    //checks value passed into the fuction
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


//get choice from player and computer
void playerChoice(int symbol )
{

    //auto begin = chrono::steady_clock::now();
    while (true) 
    {
        cout << " Select Your Position(1 - 9) : ";
        int choice;
        cin >> choice;
        choice--; //array position(0-8)

        if (choice < 0 || choice > 8) 
        {
            cout << " Please Select Your Choice From(1 - 9)." << endl;
        }
        //if the chosen position has already been marked then let player know and allow player to select another position
        else if (board[choice] != ' ') 
        {
            cout << " Please Select An Empty Position." << endl;
        }
        else 
        {
            //player1 if symbol is 1 otherwise player2
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

void getComputerChoice(int symbol)
{
    int AImove;

    //were using the same move in computerVScomputer move 
    //so let the first move be random 
    if (boardCount('X') == 0)
    {
        srand(time(0));
        AImove = rand() % 10;
    }
    else 
    {
        //get the bst possible move using minimax function
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


//check if any player has won
char checkWinner()
{
    // checking winner in row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0]; //returns 'X' or 'O'
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];

    // checking winner in column
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

    //if the board is full and there is still no winner then declare ame as draw
    if (boardCount('X') + boardCount('O') < 9)
        return 'C';
    else
        //there are still empty spaces on the board
        //continue playing
        return 'D'; 
}

//helps to know total number of turns completed by each player
//useful to figure out whose turn it is
int boardCount(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == symbol)
            total += 1;
    }
   return total;
}

//clear board so that player has the option to replay the game
void clearBoard()
{
    //makes the array empty and resets the board
    //lets user to play again
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}


//Minimax algorithm to get best possible move
//had to go through a lot of videos and codes to understand and implement minimax function
//but still does not work so well
int score() 
{
    if (checkWinner() == 'X') 
    { 
        return 10; 
    }
    else if (checkWinner() == 'O') 
    { 
        return -10; 
    }
    return 0; // draw
}

//tries to find next optimal solution
int minimax(char AIBoard[9])
{
    int bestMoveScore = 1000; //initialize best score
    int bestmove;

    //run loop through the board
    for (int i = 0; i < 9; i++)
    {
        if (AIBoard[i] == ' ') //check if the position is empty
        {
            AIBoard[i] = 'O'; 
            int tempMoveScore = maxSearch(AIBoard); //call recursion function to check every possible outcome and get best possible score
            if (tempMoveScore <= bestMoveScore)
            {
                bestMoveScore = tempMoveScore;
                bestmove = i;
            }
            AIBoard[i] = ' '; //clear the position to check through other position and outcome
        }
    }

    return bestmove;
}

//tries to maximize score
int maxSearch(char AIBoard[9])
{
    if (checkWinner()!='C') return score();
    int bestMove;

    int bestMoveScore = -1000;
    for (int i = 0; i < 9; i++)
    {
        if (AIBoard[i] == ' ')
        {
            AIBoard[i] = 'X';
            int tempMoveScore = minSearch(AIBoard);
            if (tempMoveScore >= bestMoveScore)
            {
                bestMoveScore = tempMoveScore;
                bestMove = i;
            }
            AIBoard[i] = ' ';
        }
    }
    return bestMoveScore;
}

//tries to minimize score
int minSearch(char AIBoard[9]) {
    if (checkWinner() != 'C') return score();
    int bestMove;

    int bestMoveScore = 1000;
    for (int i = 0; i < 9; i++)
    {
        if (AIBoard[i] == ' ')
        {
            AIBoard[i] = 'O';
            int tempMoveScore = minSearch(AIBoard);
            if (tempMoveScore <= bestMoveScore)
            {
                bestMoveScore = tempMoveScore;
                bestMove = i;
            }
            AIBoard[i] = ' ';
        }
    }

    return bestMoveScore;
}



