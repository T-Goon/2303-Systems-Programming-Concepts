/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"

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
        list->savePayload(new Room(roomNum, &name, numClues));
    }

    fclose(file);

    return list;
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;

    char breadth[20];
    int startingRoom = 0;
    int numRooms = INT_MAX;
    int clueLimit = INT_MAX;
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


	return answer;

}

