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
    node_t* node = mHead;
    while (node != nullptr) {
        node_t* next = node->next;
        free(node);
        node = next;
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
    node_t* node = mHead;
    cout << "value: ";
    while (node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void MyLinkedList::remove(int num) {
    node_t* node = mHead;
    node_t* preNode = mHead;

    while (node != nullptr) {
        if (node->value == num) {
            if (node == mHead) {
                mHead = node->next;
            } else {
                preNode->next = node->next;
            }

            free(node);
            break;
        }
        preNode = node;
        node = node->next;
    }
}