/*
 ============================================================================
 Name        : test.c
 Author      : Timothy Goon, Patrick Houlihan
 Version     :
 Copyright   : Your copyright notice
 Description : The tests which we will eventually apply to a project
 ============================================================================
*/
#include "tests.h"
#include "production.h"


bool tests()
{
	bool answer = false;
	bool ok1 =  testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testSomethingElse();
	bool ok4 = testRemoveFromList();
	answer = ok1 && ok2 && ok3 && ok4;
	return answer;
}

bool testReadFile()
{
	bool ok = false;
	puts("starting testReadFile");fflush(stdout);
	//what are the criteria for success for
	//test case 1:
	//test case 2:

    if(ok)
    {
    	puts("test read file passed.");
    }
    else
    {
    	puts("test read file did not pass.");
    }
	return ok;
}

bool testGotAdjacencyMatrix()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}

bool testSomethingElse()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}
bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
