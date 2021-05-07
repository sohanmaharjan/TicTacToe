#pragma once
#include <iostream>

using namespace std;

class Game
{
public:
};

void drawBoard();

//void playerVScomputer();
//void computerChoice();

void playerVSplayer();
void playerChoice(int symbol);


char checkWinner();

int boardCount(char symbol);



