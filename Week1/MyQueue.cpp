#include "MyQueue.h"

#include <iostream>

using namespace std;

MyQueue::MyQueue()
    : MyHeapAllocation(), mFront(0), mBack(0) {
}

MyQueue::MyQueue(size_t capacity)
    : MyHeapAllocation(capacity), mFront(0), mBack(0) {
}

MyQueue::~MyQueue() {
}

void MyQueue::enqueue(int num) {
    if (mSize < mCapacity) {
        mHeap[mBack] = num;
        ++mSize;
        if (mSize == mCapacity) {
            increaseCapacity();
        }
        mBack = (mBack + 1) % mCapacity;
        return;
    }
    cout << "queue is full" << endl;
}

int MyQueue::dequeue() {
    int num = mHeap[mFront];
    --mSize;
    mFront = (mFront + 1) % mCapacity;
    return num;
}

bool MyQueue::search(int num) {
    bool hasNum = false;
    MyQueue tmpQueue;
    while (!isEmpty()) {
        int value = dequeue();
        if (num == value) {
            hasNum = true;
        }
        tmpQueue.enqueue(value);
    }

    while (!tmpQueue.isEmpty()) {
        int value = tmpQueue.dequeue();
        enqueue(value);
    }
    cout << "search result(" << num << "): " << hasNum << endl;
    return hasNum;
}

bool MyQueue::isEmpty() {
    return mSize == 0;
}

void MyQueue::printInfo() {
    cout << endl
         << "mSize: " << mSize << endl;
    cout << "mCapacity: " << mCapacity << endl;
    cout << "front: " << mFront << endl;
    cout << "back: " << mBack << endl;

    cout << "queue: ";
    for (size_t i = 0; i < mSize; ++i) {
        cout << mHeap[(mFront + i) % mCapacity] << " ";
    }
    cout << endl
         << endl;
}