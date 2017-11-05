#include <stdio.h>
#include <stdlib.h>

#ifndef __CELL_H__
#define __CELL_H__

//board[width][height]
int board[100][100];
int lastboard[100][100];

int boardHeight, boardWidth, generations;
int born, died;

void initializeBoard();
void seed();
void printarray();
int adjacent();
void tick();

#endif
