#include "MyHashMap.h"

#include <iostream>

void MyHashMap::Add(const char* key, int value) {
    shared_ptr<Node> newNode = make_shared<Node>(key, value);
    size_t hash = Hash_65599(key, strlen(key));
    int index = hash % MAX_SIZE;

    if (mArray[index] == nullptr) {
        mArray[index] = newNode;
        return;
    }

    shared_ptr<Node> current = mArray[index];
    // If key of newNode is the same as current's one, overwrite.
    if (current->GetKey() == key) {
        newNode->SetNext(current->GetNext());
        mArray[index] = newNode;
        return;
    }

    while (current->GetNext() != nullptr) {
        if (current->GetNext()->GetKey() == key) {
            newNode->SetNext(current->GetNext()->GetNext());
            current->SetNext(newNode);
            return;
        }
        current = current->GetNext();
    }
    current->SetNext(newNode);
}

int MyHashMap::Get(const char* key) {
    size_t hash = Hash_65599(key, strlen(key));
    int index = hash % MAX_SIZE;
    if (mArray[index] == nullptr) {
        return -1;
    }

    shared_ptr<Node> current = mArray[index];
    while (current != nullptr) {
        if (current->GetKey() == key) {
            return current->GetData();
        }
        current = current->GetNext();
    }

    return -1;
}

void MyHashMap::Print() const {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (mArray[i] != nullptr) {
            shared_ptr<Node> current = mArray[i];
            while (current != nullptr) {
                cout << "Key: " << current->GetKey() << ", Value: " << current->GetData() << endl;
                current = current->GetNext();
            }
        }
    }
}

size_t MyHashMap::Hash_65599(const char* str, size_t len) {
    size_t hash = 0;
    for (size_t i = 0; i < len; ++i) {
        hash = 65599 * hash + str[i];
    }

    return hash ^ (hash >> 16);
}