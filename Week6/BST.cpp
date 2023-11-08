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

void BST::InsertRecursive(node_t* node, int data) {
    if (node == nullptr) {
        node = static_cast<node_t*>(malloc(sizeof(node_t)));
        memset(node, 0, sizeof(node_t));
        node->mData = data;
        return;
    }

    if (node->mData <= data && node->right == nullptr) {
        node->right = static_cast<node_t*>(malloc(sizeof(node_t)));
        memset(node->right, 0, sizeof(node_t));
        node->right->mData = data;
        return;
    }

    if (node->mData > data && node->left == nullptr) {
        node->left = static_cast<node_t*>(malloc(sizeof(node_t)));
        memset(node->left, 0, sizeof(node_t));
        node->left->mData = data;
        return;
    }

    if (node->mData > data) {
        InsertRecursive(node->left, data);
    }
    InsertRecursive(node->right, data);
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