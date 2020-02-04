/*
 * tests.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "tests.h"
#include "production.h"
#include "marker.h"
#include "space.h"
#include "LinkedList.h"
bool tests();

bool testReadFile();
bool testGotAdjacencyMatrix();
bool testPlaceMarker();
bool testEmptyLinkedList();
bool testAddToLinkedList();
bool testDisplaySpace();
bool testMoveMarker1();
bool testMoveMarker2();
bool testMoveMarker3();
int lengthOfList(DLLNode* lp);

#endif /* TESTS_H_ */
