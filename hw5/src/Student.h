/*
 * Student.h
 *
 *  Created on: Feb 21, 2020
 *      Author: michaelengling
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using namespace std;

class Student {

// Google style guide suggests trailing underscores for private members.
private:
    string first_;
    string last_;
    float gpa_;
    int id_;

public:
    Student();

	Student(
	        const string &first_name, const string &last_name, float gpa, int id):
	            first_(first_name), last_(last_name), gpa_(gpa), id_(id) { }





	virtual ~Student();
};

#endif /* STUDENT_H_ */
