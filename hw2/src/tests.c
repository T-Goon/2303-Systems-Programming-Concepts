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
	bool ok1 = testBoardIsFull();
	printf("test board is full pass: %d\n", ok1);

	bool ok3 = testPlaceMarker();
    printf("place marker test pass: %d\n", ok3);

	bool ok4 = testEmptyLinkedList();
    printf("empty linked list test pass: %d\n", ok4);
    bool ok5 = testAddToLinkedList();
    printf("add to linked list test pass: %d\n", ok5);

	bool ok6 = testDisplaySpace();
    printf("display space test pass: %d\n", ok6);
  
    bool ok7 = testMoveMarker1();
    printf("move marker test pass: %d\n", ok7);

    bool ok8 = testMoveMarker2();
    printf("move marker test pass: %d\n", ok8);

    bool ok9 = testMoveMarker3();
    printf("move marker test pass: %d\n", ok9);

    /*TODO Test that the list you produce matches the list your code prints.
    There should be several test cases. Length zero, length 1, length greater than 1.*/

	answer = ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;

	return answer;
}


/// Tests moveMarker() in production.c.
bool testMoveMarker1()
{
    //TODO a test function that checks the length of your marker path.
    bool ans = false;
    int boardSize = 20;
    int numMarkers = 0;
    int* board = (int*) malloc(boardSize*boardSize*sizeof(int));
    initSpace(board, boardSize);
    DLLNode* head = makeEmptyLinkedList();
    moveMarker(board, boardSize, numMarkers, head);
    ans = (numMarkers == countLength(head));
    return ans;
}
bool testMoveMarker2()
{
    //TODO a test function that checks the length of your marker path.
    bool ans = false;
    int boardSize = 20;
    int numMarkers = 1;
    int* board = (int*) malloc(boardSize*boardSize*sizeof(int));
    initSpace(board, boardSize);
    DLLNode* head = makeEmptyLinkedList();
    moveMarker(board, boardSize, numMarkers, head);
    ans = (numMarkers == countLength(head));
    return ans;
}

bool testMoveMarker3()
{
    //TODO a test function that checks the length of your marker path.
    bool ans = false;
    int boardSize = 20;
    int numMarkers = 100;
    int* board = (int*) malloc(boardSize*boardSize*sizeof(int));
    initSpace(board, boardSize);
    DLLNode* head = makeEmptyLinkedList();
    moveMarker(board, boardSize, numMarkers, head);
    ans = (numMarkers == countLength(head));
    return ans;
}


/// Helper for testPlaceMarker(). Checks if 2 boards of a certain size contain all the same values.
bool boardEquals(int* board1, int* board2, int size)
{
    bool isSame = true;

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(*(board1 + i*size + j) != *(board2 + i*size + j))
            {
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
    for(int i=0; i< boardsize; i++)
    {
        *(board + i*boardsize + i) = 2;
    }

    displaySpace(board, boardsize);

    return ans;
}

bool testBoardIsFull(){
    bool ans = true;
    int boardSize = 20;
    // empty board test
    // Should return false
    int* board = (int*)malloc(boardSize*boardSize* sizeof(int));
    initSpace(board, boardSize);
    ans = ans && !isFull(board, boardSize);

    // Fill board with 1s
    for(int i=0; i<boardSize; i++){
        for(int j=0; j<boardSize;j++){
            *(board + i*boardSize + j) = 1;
        }
    }

    ans = ans && isFull(board, boardSize);

    return ans;
}
