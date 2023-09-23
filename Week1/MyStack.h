#pragma once

#include "MyHeapAllocation.h"

class MyStack : public MyHeapAllocation {
   public:
    MyStack();
    MyStack(size_t capacity);
    virtual ~MyStack();

    virtual void push(int num);
    virtual int pop();
    virtual bool search(int num);
    virtual void clear();
    virtual bool isEmpty();

    virtual size_t getSize() const;
    virtual size_t getCapacity() const;

    virtual void printInfo() override;

   private:
};
