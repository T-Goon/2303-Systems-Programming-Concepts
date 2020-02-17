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
};

#endif /* PRODUCTION_H_ */
