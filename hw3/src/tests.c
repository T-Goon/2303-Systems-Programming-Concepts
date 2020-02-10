/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "adjacencyMatrix.h"


bool tests()
{
	bool answer = false;
	bool ok1 =  testReadFile();
	printf("Test Read File Pass: %d\n\n", ok1);

	bool ok2 = testGotAdjacencyMatrix();
	printf("Test Got Adjacency Matrix Pass: %d\n\n", ok2);

	bool ok3 = testCreateRoomList();
	printf("Test Create Room List Pass: %d\n\n", ok3);

	bool ok4 = testRemoveFromList();
    testToDoListHelper();
    testToDoListCompleter();
	//bool ok5 = testRoomSearchFull();
	//printf("\n roomSearch pass: ", ok5);
	answer = ok1 && ok2 && ok3 && ok4;
	return answer;
}

bool testReadFile()
{
	bool ok = true;
	puts("starting testReadFile");fflush(stdout);

	FILE* mansionRooms = fopen("MansionRooms.txt", "r");
	ok = ok && mansionRooms != NULL;

	FILE* adjacencyMatrix = fopen("adjacencyMatrix.txt", "r");
	ok = ok && adjacencyMatrix != NULL;

	return ok;
}

bool testGotAdjacencyMatrix()
{
    puts("starting testGotAdjacencyMatrix");
	bool ok = true;

	// Test create the matrix from the file.
	int* matrix = getMatrix();
	ok = ok && matrix != NULL;

	// Test the same matrix is given back after it has been created.
    int* matrix2 = getMatrix();
    ok = ok && matrix == matrix2;

    int numRooms = getNumRooms();

    // 2 values in matrix to make sure it is correct.
    ok = ok && *(matrix + 11*numRooms + 10) == 1;
    ok = ok && *(matrix + 2*numRooms + 6) == 1;

	return ok;
}

bool testCreateRoomList()
{
    puts("starting testCreateRoomList");
	bool ok = true;

	// Test list has been created.
	DLLNode* head = NULL;
	head = createRoomsList();
	ok = ok && head != NULL;
	// Test list is correct length
	int length = lengthDLL(head);
	ok = ok && length == getNumRooms();

	return ok;
}

void testToDoListHelper() {
    toDoListHelper(2);
}
void testToDoListCompleter() {
    search(getMatrix(), toDoListHelper(2), 12);
}
/*
bool testRoomSearchFull() {
    int numRooms = 12;
    int startRoom = 0;
    int* matrix = getMatrix();
    DLLNode* todoList = makeEmptyLinkedList();
    DLLNode* roomList = createRoomsList();
    DLLNode* temp = dequeueFIFO(roomList);
    for (int i = 0; i < numRooms - 1; i++) {
        if(temp->RoomP->roomNum == startRoom) {
            savePayload(todoList, temp);
        }
        else {
            temp = temp->next;
        }
    }
    int numClues = roomSearchFull(matrix, startRoom, numRooms, todoList);
    return (167 == numClues);
}
*/

bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
