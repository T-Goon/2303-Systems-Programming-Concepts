/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"


DLLNode* toDoListHelper(int startRoom) {
    //goal is to return the correct room as a DLLNode* so the breadth first search can work.
    DLLNode* todoList = makeEmptyLinkedList();
    DLLNode* roomList = createRoomsList();
    DLLNode* temp = roomList;
    while(temp) {
        if (temp->RoomP->roomNum == startRoom) {
            printf("\n%d", temp->RoomP->roomNum);
            return temp;
        }
        else {
            temp = (DLLNode *) temp->next;
        }
    }
    printf("\n", "bad input");
}

DLLNode* toDoListCompleter (int* matrix, DLLNode* workingList, int numRooms) {
    DLLNode* temp = workingList;
    DLLNode* fullToDoList = makeEmptyLinkedList();
    while(workingList) {
        for(int i=0; i<numRooms; i++){
            for(int j=0; j<numRooms; j++){
                if (*(matrix + i*numRooms + j) == 1 && temp->RoomP->discovered == 0) {
                    savePayload(fullToDoList, temp->RoomP);
                    savePayload(workingList, temp);
                    temp->RoomP->discovered = 1;
                    removeFromList(workingList, temp);
                }
            }
        }
    }
    printHistory(fullToDoList);
    return fullToDoList;

}

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
   char breadth[20];
   int startingRoom = 0;
    printf("Inspector Gompei:\n\tDo you want to do a thorough examination of the entire mansion, \n"
                              "\ta local search of a set number of rooms, or until you have found \n"
                              "\ta certain number of clues?(through/local/clues)\n\nAnswer: ");
    scanf("%s", breadth);
    if(strcmp(breadth, "thorough") == 0){
        printf("%s", breadth);
        //TODO search entire mansion
    }
    else if(strcmp(breadth, "local") == 0) {
        printf("%s", breadth);
        int numRooms = 0;
        printf("Inspector Gompei:\n\tHow many rooms do you want to search?(0-11)"
               "\n\nAnswer: ");
        scanf("%d", &numRooms);
        //TODO search set number of rooms
    }
    else if(strcmp(breadth, "clues") == 0){
        printf("%s",breadth);
        int numClues = 0;
        printf("Inspector Gompei:\n\tHow many clues do you want to find?"
               "\n\nAnswer: ");
        scanf("%d", &numClues);
        //TODO search until you find a certain number of clues.
    }
    else{
        printf("Invalid Input.");
        return 0;
    }

    printf("Inspector Gompei:\n\tWhere do you want to start your search?(RoomNumber 0-11)"
           "\n\nAnswer: ");
    scanf("%d", &startingRoom);


	return 0;
}
