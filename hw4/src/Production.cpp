/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include "AdjacencyMatrix.h"

// Creates a linked list of rooms.
LinkedList* Production::createRoomsList(){
    // Open file with room data and make new linked list.
    FILE* file = fopen("MansionRooms.txt", "r");
    auto list = new LinkedList();

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

        std::string name = roomName;
        list->savePayload(new Room(roomNum, name, numClues));
    }

    fclose(file);

    return list;
}

int Production::specificRoomSearch (LinkedList* roomList, int numRoom) {
    for (int i = 0; i < roomList->size(); i++) {
        if (roomList->get(i)->getRoomNum() == numRoom) {
            return i;
        }
    }
    return -1;
}

int Production::search (int numRooms, int startRoom, int roomLimit, int clueLimit)
{
    auto matrix = new AdjacencyMatrix();
    int* matrixPointer = matrix->getMatrix();
    auto queue = new LinkedList;
    auto printQueue = new LinkedList;
    auto allRooms = Production::createRoomsList();
    int numRoomsDiscovered = 0;
    int clues = 0;
    queue->savePayload(allRooms->get(specificRoomSearch(allRooms, startRoom)));
    numRoomsDiscovered++;
    while (!queue->isEmpty())
    {
        allRooms->get(specificRoomSearch(allRooms, queue->getFirst()->getRoomNum()))->setDiscovered(true);
        clues+= queue->getFirst()->getNumClues();
        numRoomsDiscovered++;
        printQueue->savePayload(allRooms->get(specificRoomSearch(allRooms, queue->getFirst()->getRoomNum())));
        if (numRoomsDiscovered > roomLimit) {
            printQueue->printHistory();
            printQueue->fPrintHistory();
            return clues;
        }
        if (clues >= clueLimit) {
            printQueue->printHistory();
            printQueue->fPrintHistory();
            return clues;
        }
        allRooms->get(specificRoomSearch(allRooms, queue->getFirst()->getRoomNum()))->setSearched(true);
        for (int i = 0; i < numRooms; i++)
        {
            if ((*(matrixPointer + queue->getFirst()->getRoomNum() *allRooms->size() + i) == 1) &&
                    !(allRooms->get(specificRoomSearch(allRooms, i)))->getDiscovered())
            {
                queue->savePayload(allRooms->get(specificRoomSearch(allRooms, i)));
                //printQueue->savePayload(allRooms->get(specificRoomSearch(allRooms, i)));
                allRooms->get(specificRoomSearch(allRooms, i))->setDiscovered(true);
            }
        }
        queue->dequeueFIFO();
    }
    printQueue->printHistory();
    printQueue->fPrintHistory();
    return clues;
}

int Production::getNumRooms() {
    FILE* file = fopen("MansionRooms.txt", "r");
    int numRooms;
    fscanf(file,"%d", &numRooms);
    return numRooms;
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;
    char breadth[20];
    int startingRoom = 0;
    int numRooms = INT_MAX;
    int clueLimit = INT_MAX;
    int totalRooms = getNumRooms();
    printf("Inspector Gompei:\n\tDo you want to do a thorough examination of the entire mansion, \n"
           "\ta local search of a set number of rooms, or until you have found \n"
           "\ta certain number of clues?(thorough/local/clues)\n\nAnswer: ");
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
    search(totalRooms, startingRoom, numRooms, clueLimit);
	return answer;

}

