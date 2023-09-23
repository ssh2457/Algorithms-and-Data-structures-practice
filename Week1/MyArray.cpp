#include "MyArray.h"

MyArray::MyArray()
    : MyHeapAllocation() {
}

MyArray::MyArray(size_t capacity)
    : MyHeapAllocation(capacity) {
}

MyArray::~MyArray() {
}

void MyArray::insertAt(size_t index, int num) {
    if (mSize == mCapacity) {
        increaseCapacity();
    }

    if (index <= mSize) {
        for (int i = mSize; i > index; --i) {
            mHeap[i] = mHeap[i - 1];
        }
        mHeap[index] = num;
        ++mSize;
    }
}

size_t MyArray::findIndex(int num) {
    for (int i = 0; i < mSize; ++i) {
        if (mHeap[i] == num) {
            return i;
        }
    }
    return -1;
}

void MyArray::removeAt(size_t index) {
    if (index < mSize) {
        mHeap[index] = mHeap[--mSize];
        /*
        for (int i = index; i < mSize; ++i) {
            mHeap[i] = mHeap[i + 1];
        }

        --mSize;
        */
    }
}

void MyArray::printInfo() {
    cout << endl
         << "mSize: " << mSize << endl;
    cout << "mCapacity: " << mCapacity << endl;
    cout << "heap: ";
    for (size_t i = 0; i < mSize; ++i) {
        cout << mHeap[i] << " ";
    }
    cout << endl
         << endl;
}