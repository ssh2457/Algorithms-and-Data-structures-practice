#include "MyHeapAllocation.h"

#include "iostream"

using namespace std;

MyHeapAllocation::MyHeapAllocation()
    : mSize(0), mCapacity(8), mHeap(nullptr) {
    mHeap = new int[mCapacity];
}

MyHeapAllocation::MyHeapAllocation(size_t capacity)
    : mSize(0), mCapacity(capacity), mHeap(nullptr) {
    mHeap = new int[mCapacity];
}

MyHeapAllocation::~MyHeapAllocation() {
    delete[] mHeap;
    mHeap = nullptr;
}

void MyHeapAllocation::increaseCapacity() {
    int* backup_p = mHeap;
    if (nullptr == (mHeap = static_cast<int*>(realloc(mHeap, 2 * sizeof(int) * mCapacity)))) {
        mHeap = backup_p;
        cout << "Stack size can not be extended." << endl;
    } else {
        mCapacity *= 2;
    }
}

void MyHeapAllocation::printInfo() {
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