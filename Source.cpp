#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main()
{
    int mode;
    string option;

    cout << "\n\n\t\t\t\t\t\t Tic Tac Toe" << endl;
    cout << "\n\n\nSelect Game Mode" << endl << endl;
    cout << "\t1.Computer VS Player." << endl;
    cout << "\t2.Player VS Player." << endl << endl;
    cout << "Please select your game mode...... " << endl;
    cin >> mode;
    switch (mode) {
    case 1:
        //computer_vs_player();
        break;
    case 2:
        playerVSplayer();
        break;
    default:
        cout << "Please Select Valid Game Mode." << endl;
        break;
    }
    system("cls");
    return 0;
}