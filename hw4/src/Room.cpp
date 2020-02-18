//
// Created by Timothy Goon, Patrick Houlihan on 2/15/2020.
//

#include "Room.h"

// Constructor
Room::Room(int roomNum, std::string* roomName, int numClues){
    _roomNum = roomNum;
    _roomName = roomName;
    _numClues = numClues;
}

// Destructor
Room::~Room() {
    free(_roomName);
}

// Getter for _RoomNum
int Room::getRoomNum(){
    return _roomNum;
}

// Getter for _RoomName
std::string* Room::getRoomName(){
    return _roomName;
}

// Getter for _numClues
int Room::getNumClues() {
    return _numClues;
}

// Getter for _searched
bool Room::getSearched(){
    return _searched;
}

// Getter for _discovered
bool Room:: getDiscovered(){
    return _discovered;
}

// Setter for _searched
void Room::setSearched(bool s){
    _searched = s;
}

// Setter for _searched
void Room::setDiscovered(bool d) {
    _discovered = d;
}