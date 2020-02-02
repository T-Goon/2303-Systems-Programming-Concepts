/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"

bool tests()
{
	bool answer = false;
	bool ok1 =  testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testPlaceMarker();
    printf("place marker test pass: %d\n", ok3);

	bool ok4 = testEmptyLinkedList();
    printf("empty linked list test pass: %d\n", ok4);
    bool ok5 = testAddToLinkedList();
    printf("add to linked list test pass: %d\n", ok5);

	bool ok6 = testDisplaySpace();
    printf("display space test pass: %d\n", ok6);

	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
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

/// Test creation of empty linked list
bool testEmptyLinkedList()
{
	bool ans = true;
	// Manually create a linked list node to compare to
    DLLNode* node = (DLLNode*) malloc(sizeof(DLLNode));
    node->next = NULL;
    node->prev = NULL;
    node->payP = NULL;
    DLLNode* empty = makeEmptyLinkedList();

	ans = ans && empty->next == node->next
	        && empty->prev == node->prev
	        && empty->payP == node->payP;

	return ans;
}

///Test creation of linked list of length 1
bool testAddToLinkedList(){
    bool ans = true;
    DLLNode* node = makeEmptyLinkedList();
    Payload* load = (Payload*) malloc (sizeof(Marker));

    // add payload to linked list
    savePayload(node, load);

    ans = ans && node->payP == load;

    // add second payload to linked list
    // should increase length of list
    Payload* load2 = (Payload*) malloc (sizeof(Marker));
    savePayload(node, load2);
    DLLNode* node2 = (DLLNode*)node->next;

    ans = ans && node2->payP == load2;

    return ans;
}

/// Test for dipplaySpace() in space.c.
bool testDisplaySpace(){
    bool ans = true;

    // 5 by 5 board with main diagonal filled with 2s
    int boardsize = 5;
    int* board = (int*) malloc(boardsize*boardsize*sizeof(int));
    initSpace(board, boardsize);
    for(int i=0; i< boardsize; i++){
        *(board + i*boardsize + i) = 2;
    }

    displaySpace(board, boardsize);

    return ans;
}
