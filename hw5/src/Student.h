/*
 * Student.h
 *
 *  Created on: Feb 21, 2020
 *      Author: michaelengling
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student {

// Google style guide suggests trailing underscores for private members.
private:
    std::string first_;
    std::string last_;
    float gpa_;
    int id_;

public:
    Student();

	Student(
	        const std::string &first_name, const std::string &last_name, float gpa, int id):
	            first_(first_name), last_(last_name), gpa_(gpa), id_(id) { }





	virtual ~Student();
	std::string full_name();
	int id();
	float gpa();
	void print_info();
};

#endif /* STUDENT_H_ */
