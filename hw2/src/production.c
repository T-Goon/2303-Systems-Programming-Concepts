/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "space.h"
#include "marker.h"
#include "LinkedList.h"
#include <time.h>
DLLNode* moveMarker(int* board, int bSize, int numMarkers, DLLNode* listHead)
{
    DLLNode* initialList = listHead;
    int row;
    int col;

    srand(time(0));
    for (int i = 0; i < numMarkers; i++)
    {
        row = rand() % bSize;
        col = rand() % bSize;
        savePayload(initialList, placeMarker(board, bSize, row, col, i));
    }

    return initialList;
}

void production(int argc, char* argv[])
{
	//obtain space for 20x20 of integers

	int boardSize = 20;
	int* theSpaceP = (int*) malloc(boardSize*boardSize*sizeof(int));
    bool okInit = initSpace(theSpaceP, boardSize);
    DLLNode* head = makeEmptyLinkedList();
    head = moveMarker(theSpaceP, boardSize, 15, head);

    printHistory(head);

    // resize the board smaller
    boardSize = 5;
    // reset the board and list
    initSpace(theSpaceP, boardSize);
    head = makeEmptyLinkedList();

    // keep adding to the board until it is full
    while(!isFull(theSpaceP, boardSize)){
        head = moveMarker(theSpaceP, boardSize, 5, head);
    }

    displaySpace(theSpaceP, boardSize);

}
