/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "marker.h"
#include "space.h"

bool tests()
{
	bool answer = false;
	bool ok1 =  testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testPlaceMarker();
	bool ok4 = testRemoveFromList();
	printf("place marker test pass: %d\n", ok3);
	answer = ok1 && ok2 && ok3 && ok4;
	return answer;
}

bool testReadFile()
{
	bool ok = false;
	puts("starting testReadFile");fflush(stdout);
	//what are the criteria for success for
	//test case 1:
	//test case 2:

    if(ok)
    {
    	puts("test read file passed.");
    }
    else
    {
    	puts("test read file did not pass.");
    }
	return ok;
}

bool testGotAdjacencyMatrix()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}

/// Helper for testPlaceMarker(). Checks if 2 boards of a certain size contain all the same values.
bool boardEquals(int* board1, int* board2, int size){
    bool isSame = true;

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(*(board1 + i*size + j) != *(board2 + i*size + j)){
                isSame = false;
            }
        }
    }

    return isSame;
}

/// Checks placeMaker() in marker.c.
bool testPlaceMarker()
{
	bool ans = true;
    int boardsize = 20;
    int* board = (int*) malloc(boardsize*boardsize*sizeof(int));
    int* board2 = (int*) malloc(boardsize*boardsize*sizeof(int));

    // Test 1
    // Place marker at row 5, col 5, with index 4
    int row = 5, col = 5, index = 4;
    initSpace(board, boardsize);
    initSpace(board2, boardsize);
    // answer board
    *(board2 + row*boardsize + col) = index;

    Marker* m = placeMarker(board, boardsize, row, col, index);
	ans = ans && m->col==row && m->row==col && m->index==index && boardEquals(board, board2,
	        boardsize);

    // Test 2
    // Place marker at row 0, col 0, with index 1
    row = 0, col = 0, index = 1;
    initSpace(board, boardsize);
    initSpace(board2, boardsize);
    // answer board
    *(board2 + row*boardsize + col) = index;

    m = placeMarker(board, boardsize, row, col, index);
    ans = ans && m->col==row && m->row==col && m->index==index && boardEquals(board, board2,
            boardsize);

    // Test 3
    // Place marker at row 20, col 20, with index 10
    row = 20, col = 20, index = 10;
    initSpace(board, boardsize);
    initSpace(board2, boardsize);

    m = placeMarker(board, boardsize, row, col, index);
    ans = ans && m == NULL && boardEquals(board, board2, boardsize);

	return ans;
}

bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
