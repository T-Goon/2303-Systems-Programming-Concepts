//
// Created by Timothy Goon on 2/9/2020.
//

#include "adjacencyMatrix.h"

// Adjacency Matrix: Square array with 1s in a position if the nodes are adjacent.
int* matrix = NULL;

int numRooms = -1;

int* getMatrix(){
    // If the matrix doesn't exists yet read it in from file.
    if(matrix == NULL){
        FILE* file = fopen("adjacencyMatrix.txt", "r");

        // Create array for adjacency matrix
        fscanf(file, "%d", &numRooms);
        matrix = (int*)calloc(numRooms*numRooms, sizeof(int));

        for(int i=0; i<numRooms; i++){
            for(int j=0; j<numRooms; j++){
                fscanf(file, "%d", (matrix + i*numRooms + j));
            }
        }

        fclose(file);
    }

    return matrix;
}

// Get the number of rooms in the matrix.
// numRooms will be -1 before getMatrix is called.
int getNumRooms(){
    return numRooms;
}