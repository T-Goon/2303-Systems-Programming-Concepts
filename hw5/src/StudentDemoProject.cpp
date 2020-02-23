//============================================================================
// Name        : StudentDemoProject.cpp
// Author      : me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
//#include <string>

#include "Student.h"

using namespace std;

typedef struct{
	double x0;
	double x1;
	double x2;
	double x3;
	double x4;
	double x5;
	double x6;
	double x7;
	double x8;
	double x9;
} XdoubleX;


/**
 * Allows the user to enter information for multiple students, then
 * find those students whose GPA is below 1.0 and prints them to the
 * screen.
 */
int main() {
	cout << "!!!Welcome, Students!!!" << endl; // prints !!!Hello World!!!

	string demo = "0";

	for (int kount = 0; kount < 10 ; kount++)
	{
		demo += demo;        //string operator (self-concatenation here)
		demo.push_back('X'); //string function (character append)
		cout << kount << "  " << demo.length() << "  " << demo << endl;
	}

	////string two = "two";
	////string test = "one" + two;


	string first = "first";

	string second = "second";

	demo = first + second;

	demo = first + "second";

	demo = "firstsecond";//doesn't like this one

	//cout <<  demo << endl;

	demo.append("third");

	cout <<  demo << endl;



	vector<double> primes;  //vector of ints

	cout << "primes has " << primes.size() << " elements" << endl;

	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(11);
	primes.push_back(13);
	primes.push_back(17);
	primes.push_back(2);
		primes.push_back(3);
		primes.push_back(5);
		primes.push_back(7);
		primes.push_back(11);
		primes.push_back(13);
		primes.push_back(17);



	cout << "primes has " << primes.size() << " elements" << endl;




	primes[2] = 55;

	cout << "primes has " << primes.size() << " elements"
			<< " and capacity " << primes.capacity()
			<< " and max size " << primes.max_size() << endl;

	//max_size is 2^62 - 1.  I'd love to know why.

	int temp;
	for (int kount = 0; kount < primes.size() + 190; kount++)//change 0 to 1, 2, 3
	{
		temp = primes[kount];
		//temp = kount;
		cout << temp << endl;
	}

	std::vector<double>::iterator forwardmarch = primes.begin();

	while(forwardmarch != primes.end())
	{
		forwardmarch++;
		cout << "forward march! "  << *forwardmarch << endl;

	}


	std::vector<double> vec(1000) ; // vector of 1000 doubles

	    std::cout << "\nobject 'vec' takes up " << sizeof(vec) << " bytes "
	              << "at address " << std::addressof(vec)
	              << "\nit has an automatic storage duration (typically placed on the runtime-stack)\n" ;

	    std::cout << "\nthe " << vec.size() << " objects of type double are dynamically allocated\n"
	              << "they take up " << vec.size() * sizeof(double) << " bytes of memory "
	              << "starting at address " << std::addressof( vec.front() )
	              << "\nthe standard allocator allocates this memory from the free store (heap)\n" ;


	    std::vector<XdoubleX> vecX(10000) ; // vector of 10000 XdoubleXs

	    	    std::cout << "\nobject 'vecX' takes up " << sizeof(vecX) << " bytes "
	    	              << "at address " << std::addressof(vecX)
	    	              << "\nit has an automatic storage duration (typically placed on the runtime-stack)\n" ;

	    	    std::cout << "\nthe " << vecX.size() << " objects of type XdoubleX are dynamically allocated\n"
	    	              << "they take up " << vecX.size() * sizeof(XdoubleX) << " bytes of memory "
	    	              << "starting at address " << std::addressof( vecX.front() )
	    	              << "\nthe standard allocator allocates this memory from the free store (heap)\n" ;



  	string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;

    Student loopentry;



    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;

        //Setup for initializer list in the Student constructor:
        //CONSTRUCTOR: Here for demo purposes
        //  Student(
        //      const string &first_name, const string &last_name, float gpa, int id):
        //          first_{first_name}, last_{last_name}, gpa_{gpa}, id_{id} { }

        //students.push_back(Student(first_name, last_name, gpa, id));
        students.push_back(loopentry);
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    /*

    cout << endl << "All students:" << endl;
    //print_students(students);

    cout << endl << "Failing students:";
    // TODO
    // Print a space and the word 'None' on the same line if no students are
    // failing.
    // Otherwise, print each failing student on a separate line.

*/

    return 0;
}
