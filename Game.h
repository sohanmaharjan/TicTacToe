#pragma once
#include <iostream>


using namespace std;

class Game
{
public:
};

void drawBoard();
void displayMenuScreen();
void displayExitScreen();
void displayPreviewScreen();

void playerVScomputer();
void computerVScomputer();
void playerVSplayer();

void playerChoice(int symbol); //,double* timeTaken);
void getComputerChoice(int symbol);

void computerHistory(int result);
char checkWinner();

int boardCount(char symbol);

void clearBoard();

int score();
int minimax(char AIBoard[9]);
int maxSearch(char AIBoard[9]);
int minSearch(char AIBoard[9]);






