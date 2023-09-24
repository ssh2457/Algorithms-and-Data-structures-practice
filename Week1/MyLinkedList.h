#pragma once

typedef struct node {
    int value;
    node* next;
} node_t;

class MyLinkedList {
   public:
    MyLinkedList();
    virtual ~MyLinkedList();

    virtual void printNode();
    virtual void insertFront(int num);
    virtual void destroy();
    virtual void remove(int num);

   private:
    node_t* mHead;
};