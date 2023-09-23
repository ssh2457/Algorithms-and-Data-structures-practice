#include "MyStack.h"

#include <iostream>

using namespace std;

MyStack::MyStack()
    : MyHeapAllocation() {
}

MyStack::MyStack(size_t capacity)
    : MyHeapAllocation(capacity) {
}

MyStack::~MyStack() {
    cout << "Destructor is called" << endl;
}

size_t MyStack::getCapacity() const {
    return mCapacity;
}

size_t MyStack::getSize() const {
    return mSize;
}

void MyStack::push(int num) {
    if (mSize < mCapacity) {
        mHeap[mSize] = num;
        ++mSize;
        if (mSize == mCapacity) {
            increaseCapacity();
        }
    }
}

int MyStack::pop() {
    int num = mHeap[mSize - 1];
    --mSize;
    return num;
}

bool MyStack::search(int num) {
    bool hasNum = false;

    MyStack tmpStack;

    size_t idx = mSize - 1;
    while (idx < mSize) {
        int popNum = pop();
        if (popNum == num) {
            hasNum = true;
            push(popNum);
            break;
        } else {
            tmpStack.push(popNum);
            --idx;
        }
    }

    for (size_t i = tmpStack.getSize() - 1; i < tmpStack.getSize(); --i) {
        push(tmpStack.pop());
    }

    cout << "search result(" << num << "): " << hasNum << endl;
    return hasNum;
}

void MyStack::clear() {
    mSize = 0;
    cout << "clear all elements in stack" << endl;
}

bool MyStack::isEmpty() {
    return mSize == 0;
}

void MyStack::printInfo() {
    cout << endl
         << "mSize: " << mSize << endl;
    cout << "mCapacity: " << mCapacity << endl;
    cout << "stack: ";
    for (size_t i = 0; i < mSize; ++i) {
        cout << mHeap[i] << " ";
    }
    cout << endl
         << endl;
}
