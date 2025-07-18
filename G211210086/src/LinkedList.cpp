/** 
* @file LinkedList.cpp 
* @description Bağlı liste görevi
* @course 1-b
* @assignment 1
* @date 24.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*/
#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head= NULL;
    length = 0;
}

LinkedListNode* LinkedList::findPrevByPosition(int position) 
{
    if(position<0 || position>length) throw "index out of range";
    LinkedListNode* prev = head;
    int index = 1;
   
    for(LinkedListNode* itr=head;itr->next!=NULL && index!=position;itr=itr->next,index++)
    {
        prev = prev->next;
    }
    return prev;
}

bool LinkedList::isEmpty() const
{
    return length==0;
}


void LinkedList::insert(int index,int data)
{
    if(index<0  || index>length) throw "index out of range";

    if(index == 0)
    {
        head = new LinkedListNode(data,head);
    }
    else{
        LinkedListNode* prev = findPrevByPosition(index);
        prev->next = new LinkedListNode(data,prev->next);
    }						
    length++;
}



void LinkedList::add(int data)
{   
    insert(length,data);
}




void LinkedList::removeAt(int index)
{
    if(length == 0) throw "Empty list"; 
    LinkedListNode *del;
    if(index == 0)
    { 
        del = head; head = head->next; 
    } 
     else
    { 
        LinkedListNode *prev = findPrevByPosition(index);
        del = prev->next; prev->next = prev->next->next; 
    } 
    delete del; length--;
}


LinkedListNode* LinkedList::getNode(int index)
{
    if(index<0 || index>=length) return NULL;
  
    LinkedListNode* itr = head;
    for(int i=0;itr!=0;itr=itr->next,i++)
    {
        if(i == index )
            return itr;
    }
}


int LinkedList::dugumsayisi()
{
    return length;
}


void LinkedList::clear()
{
    while(!isEmpty())
        removeAt(0);
}

LinkedList::~LinkedList() 
{
    clear();
    delete head;
}