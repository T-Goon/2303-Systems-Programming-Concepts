/*
 * marker.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#include "marker.h"

/// Creates a new marker at specified location with specified index.
/// Also updates the board.
Marker* placeMarker(int* board, int bSize, int row, int col, int index)
{

    // Create new marker and fill with the correct values.
	Marker* mP = (Marker*) malloc (sizeof(Marker));

    // If a marker is placed outside the board return NULL.
    if(row >= bSize || col >= bSize || row < 0 || col < 0){
        return NULL;
    }

	mP -> row = row;
	mP -> col = col;
	mP -> index = index;

	// Put the index number in the location of the marker on the board.
    *(board + row*bSize + col) = index;

	return mP;
}
