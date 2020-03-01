//
// Created by Timothy Goon, Patrick Houlihan on 2/29/2020.
//

#ifndef NEWSIE_H
#define NEWSIE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "Student.h"
#include "Assignment.h"
#include "enums.h"

class Newsie : public Student{
public:
    Newsie() = default;
    Newsie(std::string first, std::string last, float gpa, int id, position title,
            article primary, article secondary, article tertiary, int term_goal, int term_kount, int terms,
            std::string non_de_plume);

    virtual ~Newsie();

protected:
    position title_;

    article primary_;
    article secondary_;
    article tertiary_;

    int term_goal_;
    int term_kount_;
    int terms_;

    std::string non_de_plume_;

    Assignment* current_priority_;
    Assignment* current_extra_;
    Assignment* current_emergency_;
};

#endif //NEWSIE_H
