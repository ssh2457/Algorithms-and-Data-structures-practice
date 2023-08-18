#pragma once

#include <cstddef>

class MyStack {
   public:
    MyStack();
    MyStack(size_t capacity);
    ~MyStack();

    virtual void push(int num);
    virtual int pop();
    virtual bool search(int num);
    virtual void clear();
    virtual bool isEmpty();

    virtual size_t getSize() const;
    virtual size_t getCapacity() const;

    virtual void printInfo();

   private:
    size_t mSize;
    size_t mCapacity;
    int* mStack;
};
