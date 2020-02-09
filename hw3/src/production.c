/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"

// Creates a linked list of rooms.
DLLNode* createRoomsList(){
    // Open file with room data and make new linked list.
    FILE* file = fopen("MansionRooms.txt", "r");
    DLLNode* head = makeEmptyLinkedList();

    int numRooms;
    fscanf(file,"%d", &numRooms);

    // Add all of the rooms to the list.
    for(int i=0; i<numRooms; i++){
        int roomNum = 0;
        char roomName[FILENAMELENGTHALLOWANCE];
        int numClues = 0;

        fscanf(file, "%d", &roomNum);
        fscanf(file, "%s", roomName);
        fscanf(file, "%d", &numClues);

        savePayload(head, makeRoom(roomNum, roomName, numClues));
    }

    fclose(file);
    return head;
}

bool production(int argc, char* argv[])
{  //You can consider this your real main() -- executed after tests() passes
   //If you wan the command line arguments version, you can look in
   //HW2 starter or other HW3 starter (morning section) on Canvas


	return 0;
}
