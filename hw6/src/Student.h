/*
 * Student.h
 *
 *  Created on: Feb 21, 2020
 *      Author: michaelengling
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <utility>

class Student {

// Google style guide suggests trailing underscores for private members.
protected:
    std::string first_;
    std::string last_;
    float gpa_;
    int id_;

public:
    Student();

	Student(
	        std::string first_name, std::string last_name, float gpa, int id):
	            first_(std::move(first_name)), last_(std::move(last_name)), gpa_(gpa), id_(id) { }
    std::string first_name();
    std::string last_name();
	virtual ~Student();
	std::string full_name();
	int id();
	float gpa();
	void print_info();
};

#endif /* STUDENT_H_ */
