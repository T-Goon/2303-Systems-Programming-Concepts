//
// Created by Timothy Goon, Patrick Houlihan on 2/29/2020.
//

#include "Assignment.h"

// Constructor
Assignment::Assignment(article desk, std::string tempTitle){
    _desk = desk;
    _tempTitle = tempTitle;
    _assigned = false;
    _assignedNewsie = nullptr;
}

// deconstructor
Assignment::~Assignment(){

}

// getter for desk
article Assignment::getDesk() {
    return _desk;
}

// getter for tempTitle
std::string Assignment::getTempTitle() {
    return _tempTitle;
}

// getter for assigned boolean
bool Assignment::getAssigned() {
    return _assigned;
}

// getter for assignedNewsie
Student* Assignment::getAssignedNewsie() {
    return _assignedNewsie;
}

// setter for assignedNewsie
void Assignment::setAssignedNewsie(Student *newsie) {
    _assignedNewsie = newsie;
}

// setter for assigned boolean
void Assignment::setAssigned(bool assigned) {
    _assigned = assigned;
}

// prints out the info for the assignment
void Assignment::print() {
    printf("%d, %s, %d\n",_desk, _tempTitle.c_str(), _assigned);
}