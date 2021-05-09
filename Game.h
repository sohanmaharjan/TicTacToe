#pragma once
#include <iostream>


using namespace std;

class Game
{
public:
};

void drawBoard();

void playerVScomputer();
//void computerChoice();
void computerVScomputer();
void computerHistory(int result);

void playerVSplayer();
void playerChoice(int symbol);


char checkWinner();

int boardCount(char symbol);

void clearBoard();

void getComputerChoice(int symbol);
int score();
int minimax(char AIBoard[9]);
int maxSearch(char AIBoard[9]);
int minSearch(char AIBoard[9]);



