#include "MyHash.h"

MyHash* MyHash::mInstance = nullptr;

MyHash::~MyHash() {
    delete mInstance;
    mInstance = nullptr;
}

MyHash* MyHash::GetInstance() {
    if (mInstance == nullptr) {
        mInstance = new MyHash();
    }
    return mInstance;
}

unsigned int MyHash::hash_FNV32(const char* str, unsigned int len) {
    unsigned int hash = FNV_OFFSET_32;
    for (unsigned int i = 0; i < len; ++i) {
        hash ^= str[i];
        hash *= FNV_PRIME_32;
    }
    return hash;
}

unsigned int MyHash::hash_65599(const char* str, unsigned int len) {
    unsigned int hash = 0;
    for (unsigned int i = 0; i < len; ++i) {
        hash = 65599 * hash + str[i];
    }
    return hash ^ (hash >> 16);
}