/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include "Room.h"
#include "LinkedList.h"
#include "AdjacencyMatrix.h"

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
	printf("Test Room Pass: %d\n\n", answer);

	answer &= testLinkedList();
    printf("Test Linked List Pass: %d\n\n", answer);

    answer &= testAdjacencyMatrix();
    printf("Test Adjacency Matrix Pass: %d\n\n", answer);

	return answer;
}

// Tests for the Room object
bool Tests::testRoom(){
    printf("Starting room test\n");
    bool answer = true;

    // Test Room creation
    std::string rName = "roomA";
    auto room = new Room(0, &rName, 22);
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

// Tests for the Linked List object.
bool Tests::testLinkedList() {
    printf("Starting Linked List test\n");
    bool answer = true;

    auto list = new LinkedList();
    answer &= list != nullptr;

    // Test isEmpty() and savePayload()
    answer &= list->isEmpty();
    std::string rName = "abc";
    auto room = new Room(0, &rName, 12);
    list->savePayload(room);
    answer &= !list->isEmpty();

    // Test getFirst() and get()
    answer &= list->getFirst() == room;
    answer &= list->get(0) == room;

    // Test removeFromList() and dequeueFIFO()
    answer &= list->removeFromList(room);
    answer &= list->isEmpty();

    list->savePayload(room);
    answer &= list->dequeueFIFO() == room;

    list->savePayload(room);

    // Test printHistory() and fprintHistory()
    list->printHistory();
    list->fPrintHistory();
    FILE* file = fopen("history.txt", "r");
    answer &= file != nullptr;

    return answer;
}

bool Tests::testAdjacencyMatrix() {
    printf("Starting Adjacency Matrix test\n");
    bool answer = true;

    // Test object creation
    auto matrix = new AdjacencyMatrix();
    answer &= matrix != nullptr;

    // Test matrix creation
    answer &= matrix->getMatrix() != nullptr;

    // Test getNumRooms()
    FILE* file = fopen("adjacencyMatrix.txt", "r");
    int numRooms;
    fscanf(file, "%d", &numRooms);

    answer &= matrix->getNumRooms() == numRooms;

    return answer;
}