#pragma once

#include "MyHeapAllocation.h"

class MyQueue : public MyHeapAllocation {
   public:
    MyQueue();
    MyQueue(size_t capacity);
    virtual ~MyQueue();

    virtual void enqueue(int num);
    virtual int dequeue();
    virtual bool search(int num);

    virtual bool isEmpty();
    virtual void printInfo() override;

   private:
    size_t mFront;
    size_t mBack;
};