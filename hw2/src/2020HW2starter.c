/*
 ============================================================================
 Name        : HW2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"
#include "marker.h"
#include "LinkedList.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW2  !!!"); /* prints !!!Hello World!!! */

	/*

	int boardsize = 20;
	//MemoryAllOCation for a square Board  (of integers)
	int* theSpaceP = (int*) malloc(boardsize*boardsize*sizeof(int));

    //Initialize
	bool okInit = initSpace(theSpaceP, 20);

	printf("\n %d \n", theSpaceP);
	printf("\n %d \n", theSpaceP+1);
	printf("\n %d \n", *theSpaceP);
	printf("\n %d \n", *(theSpaceP+1));


	puts("Board initialized");

	Marker marker1;
	Marker marker2;

	Marker* mP1 = &marker1;
	Marker* mP2 = &marker2;

	marker1.index = 1;
	marker1.row = 11;
	marker1.col = 111;

	mP2->index = 2;
	mP2->row = 22;
	mP2->col = 222;

	printf("\n %d \n", mP1->row);
	printf("\n %d \n", mP2->row);

	DLLNode* classDLL = makeEmptyLinkedList();

	bool empty = isEmpty(classDLL);
	printf("\n isEmpty? %d \n \n", empty);

	puts("Pushing marker1 to DoublyLinkedList");
	savePayload(classDLL, mP1);
	printf("\n isEmpty? %d \n \n", isEmpty(classDLL));

	puts("Pushing marker2 to DoublyLinkedList \n \n");
	savePayload(classDLL, mP2);

	printHistory(classDLL);

	Marker marker3;
	Marker* mP3 = &marker3;

	marker3.index = 3;
	mP3->row = 33;
	mP3->col = 333;

	puts("Pushing marker3 to DoublyLinkedList \n \n");
    savePayload(classDLL, mP3);


	printHistory(classDLL);



	int numMarkers = 5;
	int markerRow;
	int markerCol;

	int* theBoardP = (int*) malloc(boardsize*boardsize*sizeof(int));
	Marker* markerP = (Marker*) malloc (sizeof(Marker));

	DLLNode* boardDLL = makeEmptyLinkedList();

	srand(time(0));

	for (int markdrop = 1; markdrop <= numMarkers; markdrop++)
	{

		markerRow = rand()%numMarkers;
		markerCol = rand()%numMarkers;

		markerP->index = markdrop;
		markerP->row = markerRow;
		markerP->col = markerCol;

		printf("index %d row %d column %d \n", markdrop, markerRow, markerCol);
        printf("index %d row %d column %d \n", markerP->index, markerP->row, markerP->col);

        savePayload(boardDLL, markerP);

		savePayload(classDLL, markerP);

		//Classic error here.  Each new added node is really the old node
		//with updated information

		//When you understand the error here, you GET pointers.
		printHistory(classDLL);

		//Now...how do we fix it?

	}

	puts("here");

	int firstPayload = boardDLL->payP->index;
	printf("first index is %d\n", firstPayload);



	printHistory(classDLL);

	printHistory(boardDLL);

    Marker* tempMarker;

	while(!isEmpty(boardDLL))
	{
		tempMarker =  dequeueLIFO(boardDLL);
		printf ("\nindex %d row %d column %d\n", tempMarker->index, tempMarker->row, tempMarker->col);
	}




*/





	if(tests())
	{
		puts("About to run production.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
