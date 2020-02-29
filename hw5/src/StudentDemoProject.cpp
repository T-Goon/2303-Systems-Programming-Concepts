//============================================================================
// Name        : StudentDemoProject.cpp
// Author      : Timothy Goon, Patrick Houlihan
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdio>

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

// Prints out the info for all the students in the vector
void print_students(const std::vector<Student> &students){
    for(auto student : students){
        student.print_info();
    }
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
    FILE* file = fopen("NewsiesStaff.txt", "r");
    int numStudents;
    fscanf(file, "%d", &numStudents);


    char first[50];
    char last[50]; float grade; int ID;
    int temp1, temp2, temp3, temp4, temp5, temp6, temp7;
    char temp8[50];
    for(int i=0; i< numStudents; i++){

        fscanf(file, "%s %s %f %d %d %d %d %d %d %d %d %s", first, last, &grade, &ID, &temp1, &temp2, &temp3, &temp4, &temp5, &temp6, &temp7, temp8);
        std::string firstS = std::string(first);
        std::string lastS = std::string(last);

        students.emplace_back(Student(firstS, lastS, grade, ID));
    }

    fclose(file);

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

    printf("Students:\n");
    print_students(students);

    printf("\n");
    printf("Failing Students:\n");
    std::vector<Student> failing = find_failing_students(students);
    print_students(failing);
    printf("\n");

    return 0;
}
