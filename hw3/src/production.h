/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include <limits.h>
#include "LinkedList.h"
#include "adjacencyMatrix.h"

#define FILENAMELENGTHALLOWANCE 50

bool allDiscovered (DLLNode* rooms);

int search(int* matrix, int numRooms, int startRoom, int roomLimit, int clueLimit);

bool production(int argc, char* argv[]);

DLLNode* createRoomsList();

#endif /* PRODUCTION_H_ */
