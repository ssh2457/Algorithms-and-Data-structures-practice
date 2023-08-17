#include "MyStack.h"

#include <iostream>

using namespace std;

MyStack::MyStack()
    : mStackCount(0), mStackSize(8), mStack(nullptr) {
    mStack = new int[mStackSize];
}

MyStack::MyStack(size_t stackSize)
    : mStackCount(0), mStackSize(stackSize), mStack(nullptr) {
    mStack = new int[mStackSize];
}

MyStack::~MyStack() {
    if (mStack) delete[] mStack;
    mStack = nullptr;

    cout << "Destructor is called" << endl;
}

void MyStack::push(int num) {
    mStack[mStackCount] = num;
    ++mStackCount;

    cout << "mStackCount: " << mStackCount << endl;

    if (mStackCount == mStackSize) {
        int* backup_p = mStack;
        if (nullptr == (mStack = static_cast<int*>(realloc(mStack, 2 * sizeof(int) * mStackSize)))) {
            mStack = backup_p;
            cout << "Stack size can not be extended." << endl;
        } else {
            mStackSize *= 2;
        }
    }

    cout << "mStackSize: " << mStackSize << endl;
    cout << "push result: ";
    for (size_t i = 0; i < mStackCount; ++i) {
        cout << mStack[i] << " ";
    }
    cout << endl
         << endl;
}

int MyStack::pop() {
    if (!isEmpty()) --mStackCount;

    cout << "mStackCount: " << mStackCount << endl;
    cout << "mStackSize: " << mStackSize << endl;
    cout << "pop result: ";

    for (size_t i = 0; i < mStackCount; ++i) {
        cout << mStack[i] << " ";
    }
    cout << endl
         << endl;

    return mStack[mStackCount];
}

bool MyStack::search(int num) {
    cout << "search starts" << endl;
    bool isFound = false;

    int* tmp = new int[mStackCount];
    size_t tmpCount = 0;

    size_t idx = mStackCount - 1;
    while (idx < mStackCount) {
        int popNum = pop();
        if (popNum == num) {
            isFound = true;
            push(popNum);
            break;
        } else {
            tmp[tmpCount] = popNum;
            ++tmpCount;
            --idx;
        }
    }

    for (size_t i = tmpCount - 1; i < tmpCount; --i) {
        push(tmp[i]);
    }

    delete[] tmp;
    tmp = nullptr;

    cout << "search result(" << num << "): " << isFound << endl;
    cout << "mStackCount: " << mStackCount << endl;
    cout << "mStackSize: " << mStackSize << endl;
    cout << "search ends" << endl
         << endl;

    return isFound;
}

void MyStack::clear() {
    mStackCount = 0;
    cout << "clear all elements in stack" << endl;
    cout << "mStackCount: " << mStackCount << endl;
    cout << "mStackSize: " << mStackSize << endl
         << endl;
}

bool MyStack::isEmpty() {
    return mStackCount == 0;
}
