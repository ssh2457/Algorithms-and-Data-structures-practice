#include "MyLinkedList.h"

#include <iostream>

using namespace std;

MyLinkedList::MyLinkedList()
    : mHead(nullptr) {
}

MyLinkedList::~MyLinkedList() {
    destroy();
}

void MyLinkedList::destroy() {
    node_t* p = mHead;
    while (p != nullptr) {
        node_t* next = p->next;
        free(p);
        p = next;
    }
    mHead = nullptr;
}

void MyLinkedList::insertFront(int num) {
    node_t* newNode;
    newNode = (node_t*)malloc(sizeof(node_t));

    newNode->value = num;
    newNode->next = mHead;
    mHead = newNode;
}

void MyLinkedList::printNode() {
    node_t* p = mHead;
    cout << "value: ";
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

void MyLinkedList::remove(int num) {
    node_t* p = mHead;
    node_t* pre = mHead;
    while (p != nullptr) {
        if (p->value == num) {
            if (p == mHead) {
                mHead = p->next;
            } else {
                pre->next = p->next;
            }

            free(p);
            break;
        }
        pre = p;
        p = p->next;
    }
}