#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

#include<iostream>
using namespace std;



struct LinkedListNode
{
    public:
        LinkedListNode* next;
        int data;
        LinkedListNode(int data,LinkedListNode* next); 
        ~LinkedListNode();     
};
#endif