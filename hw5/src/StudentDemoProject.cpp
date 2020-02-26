//============================================================================
// Name        : StudentDemoProject.cpp
// Author      : Timothy Goon, Patrick Houlihan
// Version     : 1
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

    // TODO
    /*
     * ADDITIONALLY
1
: Please add the Newsies textfile to this project and read
them all in–this will facilitate grading for us.  That is, after the loop that
allows data entry,  copy/paste the code that opens the data file,  reads it
and closes it again.  IMPORTANT: also copy/paste the line that loads the
newly-read Students into the students vector.  You might need to do a lit-
tle editing on the scanf
2
arguments, or swap the newly-read data into the
variables the vector push-back uses.  Just make sure the vector gets loaded
with the 26 Newsies.  (You just ignore all the extra info.)  Again, this will
help us grade things very quickly
     */
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
