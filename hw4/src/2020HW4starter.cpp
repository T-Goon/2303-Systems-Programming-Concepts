//============================================================================
// Name        : 2020HW4starter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;
#include "Tests.h"
#include "Production.h"

int main(int argc, char* argv[]) {

	if(Tests::tests())
	{
	    printf("Tests Passed. Running Production.\n"
            "----------------------------------------------------------------------\n");
        if(Production::prod(argc, argv))
        {
        	cout <<"Production passed." << endl;
        }
	}
	else
	{
		cout <<"Not all tests passed." << endl;
	}

	return 0;
}
