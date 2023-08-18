#include "MyQueue.h"
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
    mQueue[mBack] = num;
    mBack = (mBack + 1) % mCapacity;
    ++mSize;
}

int MyQueue::dequeue() {
    int num = mQueue[mFront];
    --mSize;
    mFront = (mFront + 1) % mCapacity;
    return num;
}

bool MyQueue::isEmpty() {
    return mSize == 0;
}