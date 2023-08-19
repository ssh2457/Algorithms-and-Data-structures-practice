#include "MyQueue.h"

#include <iostream>

using namespace std;

MyQueue::MyQueue()
    : mSize(0), mCapacity(8), mFront(0), mBack(0), mQueue(nullptr) {
    mQueue = new int[mCapacity];
}

MyQueue::MyQueue(size_t capacity)
    : mSize(0), mCapacity(capacity), mFront(0), mBack(0), mQueue(nullptr) {
    mQueue = new int[mCapacity];
}

MyQueue::~MyQueue() {
    delete[] mQueue;
    mQueue = nullptr;
}

void MyQueue::enqueue(int num) {
    if (mSize < mCapacity) {
        mQueue[mBack] = num;
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
    int num = mQueue[mFront];
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
        cout << mQueue[(mFront + i) % mCapacity] << " ";
    }
    cout << endl
         << endl;
}

void MyQueue::increaseCapacity() {
    int* backup_p = mQueue;
    if (nullptr == (mQueue = static_cast<int*>(realloc(mQueue, 2 * sizeof(int) * mCapacity)))) {
        mQueue = backup_p;
        cout << "Stack size can not be extended." << endl;
    } else {
        mCapacity *= 2;
    }
}