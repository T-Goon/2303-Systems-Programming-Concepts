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
#include "LinkedList.h"

#define FILENAMELENGTHALLOWANCE 50

DLLNode* toDoListHelper(int startRoom);

DLLNode* toDoListCompleter(int* matrix, DLLNode* workingList, int numRooms);

bool production(int argc, char* argv[]);

DLLNode* createRoomsList();

#endif /* PRODUCTION_H_ */
