#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

FILE *in;

int main(){

	initializeBoard();

	printf("Enter board dimensions. Keep the size 100x100 or less.\n");
	do {
		printf("Width: ");
		scanf("%d", &boardWidth);
		if (boardWidth < 0 || boardWidth > 100)
			printf("Invalid entry. Try again\n");
	} while (boardWidth < 0 || boardWidth > 100);

	do {
		printf("Height: ");
		scanf("%d", &boardHeight);
		if (boardWidth < 0 || boardHeight > 100)
			printf("Invalid entry. Try again\n");
	} while (boardWidth < 0 || boardHeight > 100);	

	printf("Enter number of generations: ");
	scanf("%d", &generations);
	printf("\n");

	int option, currentNumX, currentNumY;

	char line[50];

	in = fopen("data.txt", "rt");

	printf("Enter cell data from user or file input?\n\n");
	printf("0 - User\n1 - File\n");
	scanf("%d", &option);


	if (option == 1) {

		while (fgets(line, 80, in) != NULL) {
			sscanf(line, "%d%d", &currentNumX, &currentNumY);
			printf("\n");
			if (currentNumX == -1)
				break;
			else	{
				seed(currentNumX, currentNumY);
				printf("coordinate (%d,%d) selected", currentNumX, currentNumY);
			}
		}
		printf("\n");
		fclose(in);
	}
	else if (option == 0) {

		printf("Enter integer coordinates of live cells.\nLimits: 0 <= X <= %d, 0 <= Y <= %d\n", boardWidth - 1, boardHeight - 1);
		printf("Enter -1 to finish\n");
		while (1) {
			do {
				printf("X: ");
				scanf("%d", &currentNumX);
				if (currentNumX == -1)
					break;
				printf("Y: ");
				scanf("%d", &currentNumY);
				if (currentNumY < 0 || currentNumY > (boardHeight - 1)
				|| currentNumX < -1 || currentNumX > (boardWidth - 1)) {
					printf("Invalid entry. Try again\n");				
					}
			} while (currentNumY < 0 || currentNumY > (boardHeight - 1)
				|| currentNumX < -1 || currentNumX > (boardWidth - 1));
			if (currentNumX == -1)
				break;
			seed(currentNumX, currentNumY);
			printf("coordinate (%d,%d) selected\n", currentNumX, currentNumY); 
		}
	}
	printf("\n======initial state======\n");
	printarray();


	int i;
	for (i = 1; i <= generations; i++) {
		tick();
		printf("\n\n /======generation %d======\\", i);
		printf("\n|  born = %d     died = %d   |", born, died);
		printf("\n \\========================/\n\n");
		printarray();
	}
	printf("\n\n");
}
