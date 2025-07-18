/** 
* @file LinkedListNode.cpp 
* @description Bağlı liste dugumu 
* @course 1-b
* @assignment 1
* @date 24.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*/

#include "LinkedListNode.hpp"


LinkedListNode::LinkedListNode(int data,LinkedListNode* next)
{
    this->data = data;
    this->next = next;
};


LinkedListNode::~LinkedListNode()
{}