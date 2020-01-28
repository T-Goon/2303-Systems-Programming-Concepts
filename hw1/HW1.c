/*
 ============================================================================
 Name        : HW1.c
 Author      : Timothy Goon, Patrick Houlihan
 Version     :
 Copyright   : Your copyright notice
 Description : HW1 C file which runs tests and command line args when executing production
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"
#include "TimothyGoon.h"
#include "PatrickHoulihan.h"
#include "Search.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW1!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("About to run production.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
