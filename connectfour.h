#ifndef _CONNECTFOUR_H_
#define _CONNECTFOUR_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void CreateHelper();
int ValidateFour(int Col, int Row, char WHO );
int MakeTheBestMove();
int AssumeHisMove();
void MakeMove(int col);
void displayGrid();
int ObtainDifficulty();

#endif
