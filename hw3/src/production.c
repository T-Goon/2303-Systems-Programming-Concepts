/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"

bool allDiscovered(DLLNode* rooms)
{
    if (rooms->RoomP->discovered == false) {
        return false;
    }
    else {
        while (rooms->next) {
            printf("%d\n", rooms->RoomP->roomNum);
            if (rooms->RoomP->discovered == false) {
                return false;
            }
            rooms = (DLLNode *) rooms->next;
        }
    }
    return true;
}

int search (int* matrix, int numRooms, int startRoom, int roomLimit, int clueLimit)
{
    //initializing Lists and their heads
    int numRoomsDiscovered = 0;
    DLLNode* queue = makeEmptyLinkedList();
    DLLNode* printQueue = queue;
    DLLNode* allRooms = createRoomsList();
    DLLNode* allRoomsCopy = allRooms;
    //return value
    int clues = 0;
    //searches the list for the startRoom room and appends it to the queue
    while (allRooms)
    {
        if(allRooms->RoomP->roomNum == startRoom)
        {
            allRooms->RoomP->discovered = true;
            savePayload(queue, allRooms->RoomP);
            clues+= allRooms->RoomP->numClues;
            allRooms->RoomP->searched = true;
            numRoomsDiscovered++;
        }
        allRooms = (DLLNode *) allRooms->next;
    }
    //resets allRooms to head
    allRooms = allRoomsCopy;
    //really big loop
    //allDiscovered is a helper function which returns a bool
    //false: not all rooms have been discovered, the queue can continue
    //true: all rooms have been discovered, no more work needed
    while (!allDiscovered(allRooms))
    {
        //This for loop handles
        for (int i = 0; i < numRooms; i++)
        {
            //finds where in the adjacency matrix an addable room is
            if (*(matrix + queue->RoomP->roomNum * numRooms + i) == 1)
            {
                //finds where the roomnum in allrooms matches the position in the adj matrix
                while(allRooms)
                {
                    if (allRooms->RoomP->roomNum == i && allRooms->RoomP->discovered == false)
                    {
                        //used for testing
                        //printf( "%s\n","Added to queue");
                        //saves payload if its a new node
                        if (numRoomsDiscovered == roomLimit) {
                            queue = printQueue;
                            printHistory(queue);
                            return clues;
                        }
                        else if (clues >= clueLimit) {
                            queue = printQueue;
                            printHistory(queue);
                            return clues;
                        }
                        numRoomsDiscovered++;
                        savePayload(queue, allRooms->RoomP);
                        allRooms->RoomP->discovered = true;
                        clues += allRooms->RoomP->numClues;
                        queue->RoomP->searched = true;
                        if(allDiscovered(allRoomsCopy)) {
                            queue = printQueue;
                            printHistory(queue);
                            return clues;
                        }

                    }
                    allRooms = (DLLNode *) allRooms->next;
                }
            }
            //reset allRooms to head
            allRooms = allRoomsCopy;
        }
        //prints history as it is built
        queue = (DLLNode *) queue->next;
    }
    //resets to head for counting
    queue = printQueue;
    while(queue) {
        queue->RoomP->searched = true;
        queue = (DLLNode *) queue->next;
    }
    //resets head for printing
    queue = printQueue;
    fPrintHistory(queue);
    //returns total clues
    return clues;
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
    int numRooms = INT_MAX;
    int clueLimit = INT_MAX;
    printf("Inspector Gompei:\n\tDo you want to do a thorough examination of the entire mansion, \n"
                              "\ta local search of a set number of rooms, or until you have found \n"
                              "\ta certain number of clues?(through/local/clues)\n\nAnswer: ");
    scanf("%s", breadth);
    if(strcmp(breadth, "thorough") == 0){
        printf("%s", breadth);
    }
    else if(strcmp(breadth, "local") == 0) {
        printf("%s", breadth);
        printf("Inspector Gompei:\n\tHow many rooms do you want to search?(1-12)"
               "\n\nAnswer: ");
        scanf("%d", &numRooms);

    }
    else if(strcmp(breadth, "clues") == 0){
        printf("%s",breadth);
        printf("Inspector Gompei:\n\tAfter how many clues would you like to stop your search?"
               "\n\nAnswer: ");
        scanf("%d", &clueLimit);

    }
    else{
        printf("Invalid Input.");
        return 0;
    }

    printf("Inspector Gompei:\n\tWhere do you want to start your search?(RoomNumber 0-11)"
           "\n\nAnswer: ");
    scanf("%d", &startingRoom);
    int clues = search(getMatrix(), lengthDLL(createRoomsList()), startingRoom, numRooms, clueLimit);
    printf("%s\n", "number of clues found: ");
    printf("%d\n", clues);
    return 0;
}
