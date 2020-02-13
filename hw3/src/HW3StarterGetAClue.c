/*
 ============================================================================
 Name        : FridayClass_Feb7.c
 Author      : me
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "LinkedList.h"
#include "tests.h"
#include "production.h"

int main(int argc , char* argv[]) {

    //Make sure your files to be read are one level up from the src folder.
    //I neglected to mention this earlier this week.  (I did mention rather a lot.)

    int exitCode = 1;
    if(tests()){
        printf("All Tests Passed. Running Production.\n"
               "----------------------------------------------------------------------------\n\n");
        exitCode = production(argc, argv);
    }
    else
        printf("Tests did not pass!!!\n\n");

	return exitCode;
}
