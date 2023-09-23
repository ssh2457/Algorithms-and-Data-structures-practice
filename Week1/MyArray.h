#pragma once

#include <iostream>

#include "MyHeapAllocation.h"

using namespace std;

class MyArray : public MyHeapAllocation {
   public:
    MyArray();
    MyArray(size_t capacity);
    virtual ~MyArray();

    virtual void insertAt(size_t index, int num);
    virtual size_t findIndex(int num);
    virtual void removeAt(size_t index);

    virtual void printInfo() override;

   private:
};