//
// Created by Buddy on 2/16/2020.
//

#include "AdjacencyMatrix.h"

// Constructor for adjacencyMatrix
AdjacencyMatrix::AdjacencyMatrix(){
    FILE* file = fopen("adjacencyMatrix.txt", "r");

    // Create array for adjacency matrix
    fscanf(file, "%d", &_numRooms);
    _matrix = (int*)calloc(_numRooms*_numRooms, sizeof(int));

    for(int i=0; i<_numRooms; i++){
        for(int j=0; j<_numRooms; j++){
            fscanf(file, "%d", (_matrix + i*_numRooms + j));
        }
    }

    fclose(file);
}

// Returns pointer to adjacency matrix.
int* AdjacencyMatrix::getMatrix() {
    return _matrix;
}

// Returns the number of rooms in the matrix.
int AdjacencyMatrix::getNumRooms() {
    return _numRooms;
}