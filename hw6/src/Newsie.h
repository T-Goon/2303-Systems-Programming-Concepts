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

    position getTitle();
    article getPrimary();
    article getSecondary();
    article getTertiary();

    int getTerm_goal();
    int getTerm_count();
    int getTerms();

    std::string getNon_de_plume();
    Assignment* getCurrent_priority();
    Assignment* getCurrent_extra();
    Assignment* getCurrent_emergency();

    void setCurrent_priority(Assignment* prio);
    void setCurrent_extra(Assignment* prio);
    void setCurrent_emergency(Assignment* prio);

    bool getAndComparePrimary(article primary);
    bool getAndCompareSecondary(article secondary);
    bool getAndCompareTertiary(article tertiary);

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
