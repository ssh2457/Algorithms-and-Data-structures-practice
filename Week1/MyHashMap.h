#pragma once

#include <cstddef>
#include <cstring>
#include <memory>

#include "Node.h"

using namespace std;

class MyHashMap {
   public:
    MyHashMap();
    ~MyHashMap() = default;

    virtual void Add(const char* key, int value);
    virtual int Get(const char* key);
    virtual void Print() const;

   private:
    static constexpr int MAX_SIZE = 10;
    shared_ptr<Node> mArray[MAX_SIZE];

    size_t Hash_65599(const void* str, size_t len);
};
