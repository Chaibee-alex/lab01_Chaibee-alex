// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    Node* curr = source.head;
    while (curr)
    {
        push_back(curr->info);
        curr = curr -> next;
    }
    
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next; 
        delete cur;             
        cur = next;             
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = head;

    while (curr)
    {
        sum += curr -> info;
        curr = curr -> next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr)
    {
        if (curr -> info == value)
            return true;
        curr = curr -> next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* curr = head;
    int maxNum = head -> info;
    while (curr)
    {
        if (maxNum < curr -> info)
            maxNum = curr -> info;
        curr = curr -> next;
    }
    return maxNum; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!head)
        return 0.0;
    double averageNum = sum()*1.0 / count()*1.0;
    
    return averageNum; 
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* n = new Node{value, head};
    head = n;

    if (tail == nullptr) {
        tail = head;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* n = new Node{value, nullptr};

    if (head == nullptr) {      
        head = tail = n;
    } else {                  
        tail->next = n;
        tail = n;
    }
 
}

// return count of values
int IntList::count() const {
    int count = 0;
    Node* curr = head;
    while (curr)
    {
    count ++;
    curr = curr -> next;
    }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this; 

    Node* cur = head;
    while (cur) {
        Node* next = cur->next; 
        delete cur;             
        cur = next;            
    }
    head = nullptr;
    tail = nullptr;

    Node* curr = source.head;
    while (curr) 
    {
        push_back(curr->info);
        curr = curr->next;
    }    
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;

}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

