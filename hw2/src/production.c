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

bool production(int argc, char* argv[])
{
	bool answer = true;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		int maxRooms;
		int maxTreasure;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
			switch(i)
			{
			case 1:
				//this is filename
				printf("The length of the filename is %d.\n",strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 2:
				//this is maximum number of rooms

				aL= strtol(argv[i], &eptr, 10);
				maxRooms = (int) aL;
				if(maxRooms <0)
				{
					answer = false;
				}
				printf("Number of rooms is %d\n",maxRooms);fflush(stdout);
				break;
			case 3:
				//this is maximum amount of treasure

				aL= strtol(argv[i], &eptr, 10);
				maxTreasure = (int) aL;
				if(maxTreasure <0)
				{
					answer = false;
				}
				printf("Amount of treasure is %d\n",maxTreasure);fflush(stdout);
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);

	}//end of command line arguments

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

	return answer;
}
