//
// Created by Timothy Goon, Patrick Houlihan on 2/29/2020.
//

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "enums.h"
#include <iostream>
#include <cstdint>
#include "Student.h"


class Assignment {
public:
    Assignment() = default;
    Assignment(article desk, std::string tempTitle);
    virtual ~Assignment();

    article getDesk();
    std::string getTempTitle();
    bool getAssigned();
    void setAssigned(bool assigned);
    Student* getAssignedNewsie();
    void setAssignedNewsie(Student* newsie);
    void print();

private:
    article _desk;
    std::string _tempTitle;
    bool _assigned;
    Student* _assignedNewsie;
};


#endif //ASSIGNMENT_H
