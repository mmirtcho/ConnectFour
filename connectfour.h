#ifndef _CONNECTFOUR_H_
#define _CONNECTFOUR_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char aMain[8][7];
char piece[2]={ 'X','O'};
int NO_WAY=1;
int THE_ONLY_MOVE=2;
int GAME_IS_OVER=0;

typedef struct{
    int HorizontalLeft;
    int HorizontalRight;
    int PositiveDiagonalBottomCOL;
    int PositiveDiagonalBottomROW;
    int PositiveDiagonalTopCOL;
    int PositiveDiagonalTopROW;
    int NegativeDiagonalBottomCOL;
    int NegativeDiagonalBottomROW;
    int NegativeDiagonalTopCOL;
    int NegativeDiagonalTopROW;
}  HELPER;
HELPER aHELPER[8][7];
char iMove;
char sColor;

int Ply=1;
char WhoWin='B';
int TheMoveCol;
int TheMoveRoW;
int RedCounter[8];
int Difficulty=16;
char highscorename[10][10];
int highscoreval[10];
int ihighscore=0;
int maxsize=256;

void CreateHelper();
int ValidateFour(int Col, int Row, char WHO );
int MakeTheBestMove();
int AssumeHisMove();

void MakeMove(int col);
void displayGrid();
int ObtainMove();
int ObtainDifficulty();
void ObtainName();
int ObtainScore();
void PrintHighScore();
void ObtainInstructions();

#endif
