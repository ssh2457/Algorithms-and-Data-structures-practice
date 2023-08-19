#pragma once

#include <cstddef>

class MyQueue {
   public:
    MyQueue();
    MyQueue(size_t capacity);
    ~MyQueue();

    virtual void enqueue(int num);
    virtual int dequeue();
    virtual bool search(int num);

    virtual bool isEmpty();
    virtual void printInfo();

   private:
    size_t mSize;
    size_t mCapacity;
    size_t mFront;
    size_t mBack;
    int* mQueue;

    void increaseCapacity();
};