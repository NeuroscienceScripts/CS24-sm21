// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using std::cout;
using std::swap;


// copy constructor
IntList::IntList(const IntList& source){
    Node* current= source.first;
    first = 0;
    while (current){
        append(current->info);
        current = current->next;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (&source != this)
    {
        Node* current= source.first;
        first = 0;
        while (current){
            append(current->info);
            current = current->next;
        }
    }
    return *this;
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* previousNode = first;
    Node* currentNode = first->next;
    while(currentNode){
        delete previousNode;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    delete currentNode;
    delete previousNode;
    previousNode = nullptr;
    currentNode = nullptr;
}

// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* currentNode = first;
    while(currentNode){
        sum +=currentNode->info;
        currentNode = currentNode->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* currentNode = first;
    while(currentNode){
        if(currentNode->info == value)
            return true;
        currentNode = currentNode->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {

    if(!first)
        return 0;
    int max = INT_MIN;

    Node* currentNode = first;
    while(currentNode){
        if(currentNode->info > max)
            max = currentNode->info;
        currentNode = currentNode->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double sum = 0.0;
    int count = 0;

    Node* currentNode = first;
    while(currentNode){
        sum += currentNode->info;
        currentNode = currentNode->next;
        count++;
    }

    return count>0 ? sum/(double) count : 0.0; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {

    if(first) {
        Node *second = new Node;
        second->info = first->info;
        second->next = first->next;
        first->info = value;
        first->next = second;
    }
    else{append(value);}
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
