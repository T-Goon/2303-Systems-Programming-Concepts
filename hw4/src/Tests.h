/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Room.h"
#include "LinkedList.h"
#include "AdjacencyMatrix.h"
#include "Production.h"

class Tests {
public:
	static bool tests();

private:
    static bool testRoom();
    static bool testLinkedList();
    static bool testAdjacencyMatrix();
    static bool testCreateRoomsList();
    static bool testSearch();
    static bool testSpecificRoom();
    static bool testGetNumRooms();
};

#endif /* TESTS_H_ */
