//
// Created by Timothy Goon, Patrick Houlihan on 2/15/2020.
//

#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room {
public:
    Room(int roomNum, std::string* roomName, int numClues);
    ~Room();

    int getRoomNum();
    std::string* getRoomName();
    int getNumClues();

    bool getSearched();
    void setSearched(bool s);

    bool getDiscovered();
    void setDiscovered(bool d);

private:
    int _roomNum;
    std::string* _roomName;
    int _numClues;
    bool _searched = false;
    bool _discovered = false;
};


#endif //ROOM_H
