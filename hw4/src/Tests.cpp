/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include "Room.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;
	answer &= testRoom();
	printf("Test Room Pass: %d\n", answer);

	return answer;
}

// Tests for the Room object
bool Tests::testRoom(){
    printf("Starting room test\n");
    bool answer = true;

    // Test Room creation
    std::string rName = "roomA";
    Room* room = new Room(0, &rName, 22);
    answer &= room != nullptr;

    // Test getters
    answer &= room->getNumClues() == 22;
    answer &= room->getRoomName() == &rName;
    answer &= room->getRoomNum() == 0;
    // discovered and searched both initialized to false
    answer &= !room->getDiscovered();
    answer &= !room->getSearched();

    // Test setters
    room->setDiscovered(true);
    room->setSearched(true);
    answer &= room->getDiscovered();
    answer &= room->getSearched();

    return answer;
}
