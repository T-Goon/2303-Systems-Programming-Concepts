/*
 * marker.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#ifndef MARKER_H_
#define MARKER_H_


//Creates a struct called Marker with three data fields
typedef struct
{
   int index;
   int row;
   int col;
}Marker;

#include <stdbool.h>

Marker* placeMarker(int* board, int bSize,int row, int col, int index);

#endif /* MARKER_H_ */
