#include "BST.h"

BST::BST()
    : mRoot(nullptr) {
}

BST::BST(int data)
    : mRoot(nullptr) {
    mRoot = static_cast<node_t*>(malloc(sizeof(node_t)));
    memset(mRoot, 0, sizeof(node_t));
    mRoot->mData = data;
}

BST::~BST() {
}

void BST::Insert(int data) {
    InsertRecursive(mRoot, data);
}

node_t* BST::InsertRecursive(node_t* node, int data) {
    if (node == nullptr) {
        node = static_cast<node_t*>(malloc(sizeof(node_t)));
        memset(node, 0, sizeof(node_t));
        node->mData = data;
        return node;
    }

    if (node->mData > data) {
        node->left = InsertRecursive(node->left, data);
    } else {
        node->right = InsertRecursive(node->right, data);
    }

    return node;
}

node_t* BST::GetNodeOrNull(int data) {
    return GetNodeOrNullRecursive(mRoot, data);
}

node_t* BST::GetNodeOrNullRecursive(node_t* node, int data) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->mData == data) {
        return node;
    }

    if (node->mData > data) {
        return GetNodeOrNullRecursive(node->left, data);
    }
    return GetNodeOrNullRecursive(node->right, data);
}