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
	printf("Test Read File Pass: %d\n", ok1);

	bool ok2 = testGotAdjacencyMatrix();
	printf("Test Got Adjacency Matrix Pass: %d\n", ok2);

	bool ok3 = testSomethingElse();
	bool ok4 = testRemoveFromList();
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
	bool ok = true;
	// Test create the matrix from the file.
	int* matrix = getMatrix();
	ok = ok && matrix != NULL;

	// Test the same matrix is given back after it has been created.
    int* matrix2 = getMatrix();
    ok = ok && matrix == matrix2;

    // 2 values in matrix to make sure it is correct.
    ok = ok && *(matrix + 11*12 + 10) == 1;
    ok = ok && *(matrix + 2*12 + 6);

	return ok;
}

bool testSomethingElse()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}
bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
