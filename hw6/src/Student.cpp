/*
 * Student.cpp
 *
 *  Created on: Feb 21, 2020
 *      Author: michaelengling
 */

#include "Student.h"

Student::Student() {
	// TODO Auto-generated constructor stub

}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

// Returns the student's full name
std::string Student::full_name(){
    return first_ + " " + last_;
}
// Returns the student's first name
std::string Student::first_name(){
    return first_;
}
// Returns the student's full name
std::string Student::last_name(){
    return last_;
}

// returns the student's id
int Student::id(){
    return id_;
}

// returns the student's gpa
float Student::gpa(){
    return gpa_;
}

// prints all of the student's info to the terminal
void Student::print_info() {
    printf("%s %s, GPA: %.2f, ID: %d\n",first_.c_str(), last_.c_str(), gpa_, id_);
}