#pragma once

#include <memory>
#include <string>

using namespace std;

class Node {
   public:
    Node() = delete;
    Node(const char* key, int data);
    virtual ~Node() = default;

    virtual void SetNext(shared_ptr<Node> const next);
    shared_ptr<Node> GetNext() const;
    int GetData() const;
    const string& GetKey() const;

   private:
    string mKey;
    int mData;
    shared_ptr<Node> mNext;
};
