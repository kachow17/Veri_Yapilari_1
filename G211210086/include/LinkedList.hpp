#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include<iostream>
#include "LinkedListNode.hpp"
using namespace std;

class LinkedList
{
     public:
        LinkedListNode* head;
        int length;      
        LinkedListNode* findPrevByPosition(int position);
        void clear();
        LinkedList();
        bool isEmpty() const;
        void insert(int index,int data);
        void add(int data);
        void removeAt(int index);
        LinkedListNode* getNode(int index);
        int dugumsayisi();
        ~LinkedList();
};


#endif