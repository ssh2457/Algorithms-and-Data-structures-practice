#pragma once

#include <cstddef>

#define FNV_PRIME_32 (16777619)
#define FNV_OFFSET_32 (2166136261U)

class MyHash {
   public:
    virtual ~MyHash();

    static MyHash* GetInstance();

    unsigned long hash_FNV32(const char* str, unsigned int len);
    unsigned long hash_65599(const char* str, unsigned int len);

   private:
    MyHash() = default;
    static MyHash* mInstance;
};
