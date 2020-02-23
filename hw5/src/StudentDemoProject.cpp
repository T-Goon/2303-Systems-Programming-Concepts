//============================================================================
// Name        : StudentDemoProject.cpp
// Author      : me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "Student.h"

// Finds the students with the GPA < 1
std::vector<Student> find_failing_students(const std::vector<Student> &students) {
    std::vector<Student> failing_students;

    for(auto student : students){
        if(student.gpa() < 1){
            failing_students.push_back(student);
        }
    }

    return failing_students;
}

/**
 * Allows the user to enter information for multiple students, then
 * find those students whose GPA is below 1.0 and prints them to the
 * screen.
 */
int main() {

  	std::string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    std::vector<Student> students;

    do {

        std::cout << "Enter student's first name: ";
        std::cin >> first_name;
        std::cout << "Enter student's last name: ";
        std::cin >> last_name;
        gpa = -1;

        while (gpa < 0 || gpa > 4) {
            std::cout << "Enter student's GPA (0.0-4.0): ";
            std::cin >> gpa;
        }
        std::cout << "Enter student's ID: ";
        std::cin >> id;

        students.emplace_back(Student(first_name, last_name, gpa, id));
        std::cout << "Add another student to database (Y/N)? ";
        std::cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    printf("Failing Students:\n");
    std::vector<Student> failing = find_failing_students(students);
    for(auto student : failing){
        student.print_info();
    }
    printf("\n");

    return 0;
}
