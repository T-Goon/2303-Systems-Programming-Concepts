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
#include <time.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"
#include "marker.h"
#include "LinkedList.h"
#include "space.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW2  !!!"); /* prints !!!Hello World!!! */

	int boardsize = 20;
	//MemoryAllOCation for a square Board  (of integers)
	int* theSpaceP = (int*) malloc(boardsize*boardsize*sizeof(int));

    //Initialize
	bool okInit = initSpace(theSpaceP, 20);

	puts("Board initialized");

	DLLNode* classDLL = makeEmptyLinkedList();

	//----------------------------------------------------------------------------------

//	printHistory(classDLL);
//
//	int numMarkers = 5;
//	int markerRow;
//	int markerCol;
//
//	int* theBoardP = (int*) malloc(boardsize*boardsize*sizeof(int));
//	Marker* markerP = (Marker*) malloc (sizeof(Marker));
//
//	DLLNode* boardDLL = makeEmptyLinkedList();
//
//	srand(time(0));
//
//	for (int markdrop = 1; markdrop <= numMarkers; markdrop++)
//	{
//
//		markerRow = rand()%numMarkers;
//		markerCol = rand()%numMarkers;
//
//		markerP->index = markdrop;
//		markerP->row = markerRow;
//		markerP->col = markerCol;
//
////		printf("index %d row %d column %d \n", markdrop, markerRow, markerCol);
////        printf("index %d row %d column %d \n", markerP->index, markerP->row, markerP->col);
//
//        savePayload(boardDLL, markerP);
//
//		savePayload(classDLL, markerP);
//
//		//Classic error here.  Each new added node is really the old node
//		//with updated information
//
//		//When you understand the error here, you GET pointers.
//		printHistory(classDLL);
//
//		//Now...how do we fix it?
//
//	}
//
//	int firstPayload = boardDLL->payP->index;
////	printf("first index is %d\n", firstPayload);
//
//
//
//	printHistory(classDLL);
//
//	printHistory(boardDLL);
//
//    Marker* tempMarker;
//
//	while(!isEmpty(boardDLL))
//	{
//		tempMarker =  dequeueLIFO(boardDLL);
////		printf ("\nindex %d row %d column %d\n", tempMarker->index, tempMarker->row, tempMarker->col);
//	}
//
//
//
//
//
//
//
//
//

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
