#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

//set all board cells to dead
void initializeBoard() {
	int h, w;
	for (h = 0; h < boardHeight; h++)
		for (w = 0; w < boardWidth; w++)
			board[w][h] = 0;
}

//place live cell on board
void seed(width, height) {
	board[width][height] = 1;
}

//print board
//'-' = 0 or dead
//'*' = 1 or live
void printarray(){
	int h, w;
	for (h = boardHeight - 1; h >= 0; h--) {
		if (h < 10)
			printf("0");
		printf("%d", h);//DECORATES Y-AXIS
		for (w = 0; w < boardWidth; w++) {
			if (board[w][h] == 0)
				printf("-");
			else if (board[w][h] == 1)
				printf("*");
		}
		printf("\n");
	}
	printf("  ");

	for (w = 0; w < boardWidth; w++) //DECORATES X-AXIS
		printf("%d", w / 10);
	printf("\n  ");
	for (w = 0; w < boardWidth; w++)
		printf("%d", w % 10);
}

//calculate next generation
void tick() {
	int i, j, a;
	born = 0;
	died = 0;
	for (i = 0; i < boardWidth; i++) for (j = 0; j < boardHeight; j++) {
		lastboard[i][j] = board[i][j];
	}

	for (i = 0; i < boardWidth; i++) for (j = 0; j < boardHeight; j++) {
		a = adjacent(i, j);
		if (a == 2) board[i][j] = lastboard[i][j];
		if (a == 3){
			board[i][j] = 1;
			if (lastboard[i][j] == 0)
				born++;
		}
		
		if (a < 2){
			board[i][j] = 0;
			if (lastboard[i][j] == 1)
				died++;
		}
		
		if (a > 3) {
			board[i][j] = 0;
			if (lastboard[i][j] == 1)
				died++;
		}
		
	}
	
}

//count adjacent live cells
int adjacent(x, y) {
	int count = 0;
	int h, w;
	for (h = y - 1; h <= y + 1; h++) {
		for (w = x - 1; w <= x + 1; w++) {
			if (h == y && w == x)
				continue;
			if (lastboard[w][h] == 1) {
				count++;
			}

//			printf("\nw=%d h=%d count=%d", w, h, count);//TESTING COORDINATES
		}
	}
	return count;
}



