#pragma once

#include <cstddef>

class MyHeapAllocation {
   public:
    MyHeapAllocation();
    MyHeapAllocation(size_t capacity);
    virtual ~MyHeapAllocation();

    virtual void printInfo();

   protected:
    size_t mSize;
    size_t mCapacity;
    int* mHeap;
    void increaseCapacity();
};
