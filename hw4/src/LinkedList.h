//
// Created by Timothy Goon, Patrick Houlihan on 2/15/2020.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Room.h"

typedef Room Payload;

class LinkedList {
private:
    // Doubly linked list node object.
    class Node{
    public:
        Node();
        void setNext(Node* next);
        void setPrev(Node* prev);
        void setPayload(Payload* payload);
        Node* getNext();
        Node* getPrev();
        Payload* getPayload();

    private:
        Node* _prev = nullptr;
        Node* _next = nullptr;
        Payload* _payload = nullptr;
    };

public:
    LinkedList();
    Payload* getFirst();
    Payload* get(int index);
    bool removeFromList(Payload* payload);
    void savePayload(Payload* payload);
    bool isEmpty();
    void printHistory();
    void fPrintHistory();
    Payload* dequeueFIFO();

private:
    Node* _head;

};




#endif //LINKEDLIST_H
