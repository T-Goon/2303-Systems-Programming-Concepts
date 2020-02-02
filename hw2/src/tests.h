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
bool tests();

bool testReadFile();
bool testGotAdjacencyMatrix();
bool testPlaceMarker();
bool testRemoveFromList();
bool testDisplaySpace();
bool testMoveMarker();

#endif /* TESTS_H_ */
