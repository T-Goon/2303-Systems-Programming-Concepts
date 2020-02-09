/*
 ============================================================================
 Name        : FridayClass_Feb7.c
 Author      : me
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "LinkedList.h"

//void setRoomName(Room* currentRoom, char* currentRoomName);
int volBoxVal(int length, int width, int height);

int volBoxRef(int* lengthP, int* widthP, int* heightP);

int main(void) {
	puts("Friday, just a passing reference"); /* prints !!!Hello World!!! */


    puts("Agenda:\n\n");
    puts("-0.  Technichords Saturday night at 7pm in Alden Great Hall");
    puts("+0.  Questions");
    puts("1.  HW3 questions");
    puts("2.  Pass By Value vs. Pass By Reference (Again...and a bit more)");
    puts("3.  free (Again...some things to investigate/notice)");
    puts("?.  Double Pointer Stuff (Monday)");
    puts("4.  Important Issue! (Again, but this time it's different.)");
    puts("5.  Midterm Issue!");
    puts("6.  Midterm Evaluation Forms!");
    puts("7.  Quiz 6\n\n\n\n");

    //puts("0.  Technichords Saturday night at 7pm in Alden Great Hall");
    //puts("1.  HW3 File I/O:");
    //puts("    a. Adjacency Matrix and fprintf");
    //
    //You need to make the adjacency matrix readable by fscanf
    //
    //Either Create it with fprintf (excellent practice!) or use a text editor
    //
    //puts("    b. Persnickety functions (fprintf/fscanf)");
    //
    //fscanf and fprintf are temperamental.  They require pactience and practice.
    //THE ARGUMENTS FOR SCANF AND FSCANF MUST MUST MUST BE POINTERS!!!
    //
    //puts("    c. Put files to be read in correct place\n");
    //
    //Make sure your files to be read are one level up from the src folder.
    //I neglected to mention this earlier this week.  (I did mention rather a lot.)

/*

    puts("2.  Pass By Value vs. Pass By Reference");

    int length = 6;
    int width  = 5;
    int height = 8;

    int* lengthP = &length;
    int* widthP  = &width;
    int* heightP = &height;



    int volumeBYvalue = volBoxVal(length, width, height);

    printf("\nvolume of %d by %d by %d box is %d\n", length, width, height, volumeBYvalue);

    int volumeBYreference = volBoxRef(lengthP, widthP, heightP);

    printf("\nvolume of %d by %d by %d box is %d\n", length, width, height, volumeBYreference);






        FILE *MansionRoomsFP;
        	     MansionRoomsFP = fopen("MansionRoomsNoDots.txt", "w");

        	     int sentinel;

        	     int number;
        	     char name[50];
        	     int clues;



        	     Room* RoomP;
        	     DLLNode* roomsDLLNode = makeEmptyLinkedList();

        	     MansionRoomsFP = fopen("MansionRooms.txt", "r");

        	     fscanf(MansionRoomsFP, "%d", &sentinel);
        	     printf("\nRetrieving Room Info\n");



        	     for (int kount = 1; kount <= sentinel;kount++)
        	     {

        	    	 RoomP = (Room*) malloc(sizeof(Room));

        	    	 fscanf(MansionRoomsFP, "%d %s %d", &number, name, &clues);
        	    	 printf("\n %d %s %d", number, name, clues);

        	    	 RoomP->roomNum = number;

        	    	 //RoomP->roomName = &name;
        	    	 //setRoomName(RoomP, name);
        	    	 for (int letter = 0; letter < 50; letter++)
        	    	 {
        	    		 RoomP->roomName[letter] = name[letter];
        	    	 }

        	    	 RoomP->numClues = clues;

        	    	 printf("\n %d %s %d", RoomP->roomNum, RoomP->roomName, RoomP->numClues);

        	    	 savePayload(roomsDLLNode, RoomP);

        	     }


        	     fclose(MansionRoomsFP);

        	     printf("\nEmpty List? %d\n", isEmpty(roomsDLLNode));




        	     printHistory(roomsDLLNode);
        	     //fflush(stdout);

        	     printf("\nLength of list: %d\n",lengthDLL(roomsDLLNode));

        	     //Pass by Value vs. Pass by Reference
        	     //THIS (above) IS A HUGE TOPIC.  YOU MAY NEVER PROGRAM IN C AGAIN
        	     //BUT THIS IDEA IS A MUST.  IT IS THE DIFFERENCE BETWEEN A CODER AND A SCIENTIST

        	     puts("\n\n3.  malloc and calloc\n\n");


        	     int* intP  = (int*) malloc(12* (sizeof(int)));
        	     int* intCP = (int*) calloc(12, (sizeof(int)));

        	     puts("We have reserved 2 for 12-integer arrays\n");
        	     puts("Here they are just after allocation\n");
        	     puts("Note: the second (calloc) is guaranteed to be initialized to 0\n\n");

        	     for (int loop = 0; loop < 12; loop++)
        	     {
        	    	 	 printf("intP = %d and intCP = %d\n", *intP, *intCP);
        	    	     intP++;
        	    	     intCP++;
        	     }

        	     //This loop resets the pointers to the arrays back to their start
        	     //How?!?  WHY?!?
        	     for (int loop = 0; loop < 12; loop++)
        	     {
        	    	 	 intP--;
        	    	 	 intCP--;
        	     }

        	     puts("\nHere they are with first as evens and second as multiples of 6\n");
        	     for (int loop = 0; loop < 12; loop++)
        	     {
        	    	 	 *intP = 2*loop;
        	    	 	 *intCP = *intP*3;
        	    	 	 printf("intP = %d and intCP = %d\n", *intP, *intCP);
        	    	 	 intP++;
        	    	 	 intCP++;
        	     }

        	     puts("\nAnd here we walk backwards and print them in reverse as we go.\n");

        	     for (int loop = 11; loop >= 0; loop--)
        	     {
        	         printf("intP = %d and intCP = %d\n", *intP, *intCP);
        	         intP--;
        	         intCP--;
        	     }


        	     puts("\nCan you explain the glitches in this last set?\n");
        	     puts("Why do they print the zeroes first and not last?\n");


        	     puts("4.  free");

        	     free(intP);
        	     free(intCP);



        	     puts("\nHere they are after being freed:\n");
        	     for (int loop = 0; loop < 12; loop++)
        	     {

        	         printf("intP = %d and intCP = %d\n", *intP, *intCP);
        	         intP++;
        	         intCP++;
        	     }

        	     puts("Let's malloc & alloc with fresh pointers and check the originals");

        	     int* intTweedledeeP  = (int*) malloc(12* (sizeof(int)));
        	     int* intTweedledumCP = (int*) calloc(12, (sizeof(int)));

        	     puts("\nHere they are after being Tweedle:\n");
        	     for (int loop = 0; loop < 12; loop++)
        	     {

        	         printf("intP = %d and intCP = %d\n", *intP, *intCP);
        	         intP++;
        	         intCP++;
        	     }

        	     puts("These results are (at least sometimes) FANTASTIC!!!");
        	     puts("Except not.  We blundered.  OK, I blundered.  How?");
        	     puts("But this blunder revealed TREMENDOUS information.  What?");

//And this from the Gospel of Ritchie:
//Section 7.8 page 167:
//"[I]t is a ghastly error to free something not obtained by calling calloc or malloc.


        	     //This loop resets the pointers to the arrays back to their start
        	             	     //How?!?  WHY?!?
        	             	     for (int loop = 0; loop < 24; loop++)
        	             	     {
        	             	    	 	 intP--;
        	             	    	 	 intCP--;
        	             	     }

        	             	     puts("\nHere they are after the TWEEDLE allocs:\n");
        	             	     for (int loop = 0; loop < 12; loop++)
        	             	     {
        	             	    	 	 //*intP = 2*loop;
        	             	    	 	 //*intCP = *intP*3;
        	             	    	 	 printf("intP = %d and intCP = %d\n", *intP, *intCP);
        	             	    	 	 intP++;
        	             	    	 	 intCP++;
        	             	     }





        	     puts("5.  Double Pointer Stuff := Tomorrow");

        	     puts("6.  Important Issue!");

        	     puts("7.  Quiz 6");




        	     printf("\nnumber %d name %s clues %d\n", RoomP->roomNum, RoomP->roomName, RoomP->numClues);

        	     RoomP->roomName[0] = name[0];

        	     printf("\nnumber %d name %s clues %d\n", RoomP->roomNum, RoomP->roomName, RoomP->numClues);

*/


/*
	char write_file_name[100];

	printf("What shall we name our save file?\n");
	scanf("%s", write_file_name);

	printf("write_file_name is:%s", write_file_name);



	// Pointer to the file
	     FILE *NomanisanFP;
	     FILE *writeFileFP;
	     // Character variable to read the content of file


	     // Opening a file in r mode
	     NomanisanFP = fopen("AnnabelLee.txt", "r");
	     writeFileFP = fopen(write_file_name, "w");


	     if (NomanisanFP == NULL)
	     {
	    	 printf("Can't find file");
	     }


	     char c = fgetc(NomanisanFP);//Reads a character from the file

	     while(c!=EOF)
	     {

	    	    printf("%c", c);
	    	    putc(c, writeFileFP);

	        c = fgetc(NomanisanFP);





	     }

	     putc(c, writeFileFP);//What is this?  Why is this here? FIX ME!


	     fclose(NomanisanFP);
	     fclose(writeFileFP);

	     printf("\n\nDing Dong...Ding Dong\n");





	     FILE *MansionRoomsFP;
	     MansionRoomsFP = fopen("MansionRoomsNoDots.txt", "w");

	     int sentinel = 2;

	     sentinel = 2;

	     int rooms = sentinel;

	     int roomNum;
	     char roomName[50];
	     int numClues;

	     char tempkey[1] = "e";

	     fprintf(MansionRoomsFP, "%d\n", sentinel);

	     for (int kount = 1; kount <= rooms; kount++)
	     {
	    	 printf("Enter a roomNum, roomName, and int numClues:\n");
	    	 //all args of scanf MUST be pointers
	    	 scanf("%d %s %d", &roomNum, roomName, &numClues);
	    	 printf("You entered %d, %s, %d\n\n", roomNum, roomName, numClues);
	    	 fprintf(MansionRoomsFP, "%d %s %d\n", roomNum, roomName, numClues);
	    	 fflush(stdout);


	    	 printf("Hit a key and Enter to continue");
	    	 scanf("%s", tempkey);
	    	 //printf("\n\n%s",tempkey);
	    	 //fflush(stdout);



	     }


	     fclose(MansionRoomsFP);

	     MansionRoomsFP = fopen("MansionRooms.txt", "r");

	     fscanf(MansionRoomsFP, "%d", &sentinel);
	     printf("\nRetrieving Room Info\n");
	     for (int kount = 1; kount <= rooms;kount++)
	     {

	    	 fscanf(MansionRoomsFP, "%d %s %d", &roomNum, roomName, &numClues);
	    	 printf("\n %d %s %d\n", numClues, roomName, roomNum);

	     }

	     fclose(MansionRoomsFP);



*/

	return EXIT_SUCCESS;
}


int  volBoxVal(int length, int width, int height)
{
	int volume = length * width * height;

	length = 0;
	width = 0;
	height = 0;

	return volume;

}

int  volBoxRef(int* lengthP, int* widthP, int* heightP)
{

	int volume = (*lengthP) * (*widthP) * (*heightP);

	*lengthP = -1;
	*widthP = -22;
	*heightP = -333;

	//free(lengthP);
	//free(widthP);
	//free(heightP);


	return volume;
}




/*
void setRoomName(Room* currentRoom, char* currentRoomName)
{
	for (int letter = 1; letter<50; letter++)//Ugh Hardcoded 50 -- what is wrong with me
	{
		currentRoom->roomName[letter] = currentRoomName[letter];
	}

	//return 0;

}
*/
