/*
 * Room.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Hercule Poirot
 */

#include "Room.h"

// Returns a pointer to a room with the given parameters.
Room* makeRoom(int roomNum, char* roomName, int numClues){
    Room* room = (Room*)calloc(1, sizeof(Room));

    room->roomNum = roomNum;
    room->roomName = roomName;
    room->numClues = numClues;
    room->discovered = false;
    room->searched = false;

    return room;
}
