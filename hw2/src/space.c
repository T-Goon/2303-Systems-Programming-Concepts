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

/// Checks if the board if full.
/// board: pointer to 2D array
/// bSize: size length of square board.
/// return: true if the board contains no 0s.
///         false otherwise.
bool isFull(int* board, int bSize){
    for(int i=0; i<bSize; i++){
        for(int j=0; j<bSize; j++){
            if (*(board + i*bSize + j) == 0){
                return false;
            }
        }
    }

    return true;
}

/// Prints the board to the console.
/// board: pointer to square 2D array
/// size: side length of square board
void displaySpace(int* board, int size){


    for(int i=0; i<size; i++){
        printf("| ");
        for(int j=0; j<size; j++){
            int num = *(board + i*size + j);

            printf("%x | ", num == -1 ? 10 : num%10);
        }
        printf("\n  ");
        for(int j=0; j<size; j++){
            printf("-   ");
        }
        printf("\n");
    }
}
