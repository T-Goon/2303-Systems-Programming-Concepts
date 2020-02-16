//
// Created by Timothy Goon, Patrick Houlihan on 2/15/2020.
//

#include "LinkedList.h"

LinkedList::Node::Node(){

}

void LinkedList::Node::setNext(class Node* node) {
    _next = node;
}

void LinkedList::Node::setPrev(class Node * prev) {
    _prev = prev;
}

void LinkedList::Node::setPayload(Payload *payload) {
    _payload = payload;
}

LinkedList::Node* LinkedList::Node::getNext() {
    return _next;
}

LinkedList::Node* LinkedList::Node::getPrev() {
    return _prev;
}

Payload* LinkedList::Node::getPayload() {
    return _payload;
}

LinkedList::LinkedList(){
    _head = new Node();
}

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

void LinkedList::savePayload(Payload * payload) {
    if(isEmpty()){
        _head->setPayload(payload);
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

bool LinkedList::isEmpty() {
    return _head->getPayload() == nullptr;
}

void LinkedList::printHistory() {
    printf("Printing History\n");
    if(isEmpty()){
        printf("Empty List");
    }

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