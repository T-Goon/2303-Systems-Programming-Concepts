//============================================================================
// Name        : Newsie.cpp
// Author      : Timothy Goon, Patrick Houlihan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Newsie.h"

//These are done C style with char array strings
//When you port this to C++, you are ENCOURAGED to use strings
//Though you might want to keep char array stuff for fscanf input
//Do investigate how C++ works with char array strings.  Easy conversion?

// Newsie constructor
Newsie::Newsie(std::string first, std::string last, float gpa, int id, position title,
article primary, article secondary, article tertiary, int term_goal, int term_kount, int terms,
        std::string non_de_plume){
first_ = first;
last_ = last;
gpa_ = gpa;
id_ = id;
title_ = title;
primary_ = primary;
secondary_ = secondary;
tertiary_ = tertiary;
term_goal_ = term_goal;
term_kount_ = term_kount;
terms_ = terms;
non_de_plume_ = non_de_plume;
current_priority_ = nullptr;
current_extra_ = nullptr;
current_emergency_ = nullptr;
}

// Deconstructor
Newsie::~Newsie(){

}

int main() {
	puts("Some terminal and file I/O!"); /* prints !!!Hello World!!! */


	// Pointer to the file
     FILE *NewsiesFP;

     // Opening a file in r mode
     NewsiesFP = fopen("NewsiesStaff.txt", "r");

     if (NewsiesFP == NULL)
     {
         printf("Can't find file");
     }

     char firstname_[30];
     char lastname_[30];
     float gpa_;
     int IDnum_;

     position title_;

     article primary_;
     article secondary_;
     article tertiary_;

     int term_goal_;
     int term_kount_;
     int terms_;

     char non_de_plume_[30];

     // Get the file sentinel
     int sentinel = 0;
     fscanf(NewsiesFP, "%d", &sentinel);
     printf("\nNewsie Staff Info\n");

     // Read in all newsies in the file and create a vector of newsie objects
     std::vector<Newsie> newsies;
     for (int kount = 1; kount <= sentinel;kount++){

        fscanf(NewsiesFP, "%s %s %f %d %d %d %d %d %d %d %d %s", firstname_, lastname_, &gpa_, &IDnum_, &title_, &primary_, &secondary_,
                &tertiary_, &term_goal_, &term_kount_, &terms_, non_de_plume_ );

        // Convert char* to std::string
        std::string fName = std::string(firstname_);
        std::string lName = std::string(lastname_);
        std::string NDP = std::string(non_de_plume_);

        newsies.emplace_back(Newsie(fName, lName, gpa_, IDnum_, title_, primary_, secondary_, tertiary_, term_goal_, term_kount_, terms_, NDP));
     }

     fclose(NewsiesFP);

     // display the info for all of the newsies
     for(auto student : newsies){
         student.print_info();
     }

     // Pointer to the file
     FILE *AssignmentDeskFP;

     // Opening a file in r mode
     AssignmentDeskFP = fopen("AssignmentEditorTxt.txt", "r");

     if (AssignmentDeskFP == NULL)
     {
         printf("Can't find file");
     }

     article desk;
     char temptitle[80];

     fscanf(AssignmentDeskFP, "%d", &sentinel);

    printf("\nAssignment Desk\n");

    std::vector<Assignment> assignments;
    for (int kount = 1; kount <= sentinel;kount++){

        fscanf(AssignmentDeskFP, "%d %s", &desk, temptitle);

        std::string tempTitle = std::string(temptitle);
        assignments.emplace_back(Assignment(desk, tempTitle));
     }

     fclose(AssignmentDeskFP);

    for(auto assignment : assignments){
        assignment.print();
    }

    // TODO
    /*
     * Gompei's task is to make sure each prospective newspaper story is
        assigned to a writer. There are only two constraints:
        First: No article can be assigned to a writer who does not work the corre-
        sponding desk. That is, Skye Svenson writes Entertainment, Sports, and
        Humor so must not be assigned a News story.
        Second: No writer can take on more
     */

     printf("\n\nA Newsie takes up %d bytes.\nWhy so much?\n\n", sizeof(Newsie));








	return 0;
}
