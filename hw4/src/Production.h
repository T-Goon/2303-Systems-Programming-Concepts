/*
 * Production.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <cstdio>
#include <climits>
#include <cstring>
#include "LinkedList.h"

#define FILENAMELENGTHALLOWANCE 50

class Production {
public:
	static bool prod(int argc, char* argv[]);
    static LinkedList* createRoomsList();
    static int search (int numRooms, int startRoom, int roomLimit, int clueLimit);
    static int getNumRooms();
    static int specificRoomSearch (LinkedList* roomList, int numRoom);
};

#endif /* PRODUCTION_H_ */
