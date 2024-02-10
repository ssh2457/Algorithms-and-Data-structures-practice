#pragma once

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#include "Node.h"

class BST {
   public:
    BST();
    BST(int data);
    BST(const BST& bst);
    virtual ~BST();

    void Insert(int data);

    node_t* GetNodeOrNull(int data);

    void Delete(int data);

    void PrintByDFS(void);
    void PrintByBFS(void);

   private:
    node_t* mRoot;

    node_t* InsertRecursive(node_t* node, int data, int depth);
    node_t* GetNodeOrNullRecursive(node_t* node, int data);

    node_t* GetPredecessorRecursive(node_t* node);

    node_t* GetParentNode(node_t* node);
    node_t* GetParentNodeRecursive(node_t* root, node_t* finding);

    node_t* DeepCopyRecursive(node_t* node);

    void ClearBSTRecursive(node_t* node);
};
