#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main()
{
    int mode;
    string option;

    cout << "\n";
    cout << "\t\t\t\t\t\t *****************\n";
    cout << "\t\t\t\t\t\t    Tic-Tac-Toe\n";
    cout << "\t\t\t\t\t\t *****************\n\n\n\n";
    cout << "\n\n\n Select Game Mode" << endl << endl;
    cout << "\t1.Computer VS Player." << endl;
    cout << "\t2.Player VS Player." << endl;
    cout << "\t3.Computer VS Computer." << endl << endl;
    cout << " Please select your game mode: ";
    cin >> mode;
    switch (mode) 
    {
    case 1:
        playerVScomputer();
        break;
 
    case 2:
        playerVSplayer();
        break;

    case 3:
        computerVScomputer();
        break;

    default:
        cout << " Please Select Valid Game Mode." << endl;
        //break;
    }

    //system("cls");
    return 0;
}