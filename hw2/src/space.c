/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include "space.h"


//Initializes a Board to all zeroes
//The arguments are and integerPointer (to a Board) and an int for size of square

bool initSpace(int* corner, int howManyRows)
{
	bool ok = true;
	for(int row = 0; row< howManyRows; row++)
	{
		for(int col = 0; col < howManyRows; col++)
		{
			*(corner+row*howManyRows + col) = 0;
		}
	}
	return ok;
}

/// Prints the board to the console.
/// board: pointer to square 2D array
/// size: side length of square board
void displaySpace(int* board, int size){

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            int num = *(board + i*size + j);
            if (num == -1){
                num = 10;
            } else{
                num = num % 10;
            }

            printf("%x | ", num);
        }
        printf("\n");
        for(int j=0; j<size; j++){
            printf("-   ");
        }
        printf("\n");
    }
}
