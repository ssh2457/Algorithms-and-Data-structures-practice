#pragma once

#include <cstdlib>
#include <cstring>

#include "Node.h"

class BST {
   public:
    BST();
    BST(int data);
    virtual ~BST();

    void Insert(int data);

    node_t* GetNodeOrNull(int data);

   private:
    node_t* mRoot;

    void InsertRecursive(node_t* node, int data);
    node_t* GetNodeOrNullRecursive(node_t* node, int data);
};
