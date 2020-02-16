//
// Created by Timothy Goon, Patrick Houlihan on 2/15/2020.
//

#include "LinkedList.h"

// Constructor for a new node
LinkedList::Node::Node(){

}

// Used to set the next Node of a linked list node.
void LinkedList::Node::setNext(class Node* node) {
    _next = node;
}

// Used to set the previous Node of a linked list node.
void LinkedList::Node::setPrev(class Node * prev) {
    _prev = prev;
}

// Used to set the payload of a linked list node.
void LinkedList::Node::setPayload(Payload *payload) {
    _payload = payload;
}

// Gets the next node of a linked list node.
LinkedList::Node* LinkedList::Node::getNext() {
    return _next;
}

// Gets the previous node of a linked list node.
LinkedList::Node* LinkedList::Node::getPrev() {
    return _prev;
}

// Gets the payload of a linked list node.
Payload* LinkedList::Node::getPayload() {
    return _payload;
}

// Linked list constructor.
LinkedList::LinkedList(){
    _head = new Node();
}

// Returns the payload of the head of the linked list.
Payload* LinkedList::getFirst() {
    return _head->getPayload();
}

// Returns a pointer to a Payload at an index away from the head
// of the linked list. If the index is greater than the length of
// linked list then return the Payload of the last Node.
Payload* LinkedList::get(int index) {
    Node* current = _head;

    for(int i=0; i<=index; i++){
        if(current->getNext() != nullptr) {
            current = current->getNext();
        }
    }

    return current->getPayload();
}

// Removes a node from the linked list that has a specific payload.
bool LinkedList::removeFromList(Payload* payload) {
    // Check if linked list is empty
    if(isEmpty()){
        return false;
    }

    // Find the room with the specified Payload
    Node* current = _head;
    while(current->getPayload() != payload){
        current = current->getNext();

        // Node with payload does not exist
        if(current == nullptr){
            return false;
        }
    }

    // Node to remove is the head
    if(current == _head){
        // List of length 1
        if(_head->getNext() == nullptr){
            _head->setPayload(nullptr);
        }
        else{
            printf("monkey\n");
            _head = _head->getNext();
            _head->setPrev(nullptr);
        }

        return true;
    }// Node to remove is in middle of list
    else{
        Node* prev = current->getPrev();
        Node* next = current->getNext();

        prev->setNext(next);
        // Node to remove is at the end of the list
        if(next != nullptr){
            next->setPrev(prev);
        }

        return true;
    }
}

// Inserts a payload at the end of the list.
void LinkedList::savePayload(Payload * payload) {
    if(isEmpty()){
        _head->setPayload(payload);
        return;
    }

    // Find the end of the list
    Node* current = _head;
    while(current->getNext() != nullptr){
        current = current->getNext();
    }

    // Create new node and add to the end of list
    Node* newNode = new Node();
    current->setNext(newNode);
    newNode->setPrev(current);
    newNode->setPayload(payload);
}

// Checks if the linked list is empty.
bool LinkedList::isEmpty() {
    return _head->getPayload() == nullptr;
}

// Prints out the linked list.
void LinkedList::printHistory() {
    printf("Printing History\n");
    if(isEmpty()){
        printf("Empty List");
    }

    // Loop through the list and print out the list
    Node* current = _head;
    while(current != nullptr){

        int roomNum = current->getPayload()->getRoomNum();
        std::string roomName = *current->getPayload()->getRoomName();
        int numClues = current->getPayload()->getNumClues();

        std::cout << "The Room was number " << roomNum << ", " << roomName << ", with "<<
        numClues << " clues." << std::endl;

        current = current->getNext();
    }
}

// Prints out the linked list into a file.
void LinkedList::fPrintHistory() {
    FILE* file = fopen("history.txt", "w");

    printf("Printing History to file.\n");
    if(isEmpty()){
       printf("Empty List\n");
    }

    // Loop through the list and print
    Node* current = _head;
    while(current != nullptr){

        int roomNum = current->getPayload()->getRoomNum();
        std::string roomName = *current->getPayload()->getRoomName();
        int numClues = current->getPayload()->getNumClues();

        fprintf(file, "The Room was number %d,  %s, with %d clues.\n", roomNum, roomName.c_str(), numClues);

        current = current->getNext();
    }

    fclose(file);
}

// Removes the head of the linked list.
// Returns the payload of the node removed.
Payload* LinkedList::dequeueFIFO() {
    if(isEmpty()){
        return nullptr;
    }
    else if(_head->getNext() == nullptr){
        Payload* deqed = _head->getPayload();
        _head->setPayload(nullptr);

        return deqed;
    }
    else{
        Payload* deqed = _head->getPayload();
        _head = _head->getNext();
        _head->setPrev(nullptr);

        return deqed;
    }
}