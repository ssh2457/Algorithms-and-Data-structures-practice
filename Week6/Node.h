#pragma once

typedef struct Node {
    int mData;
    Node* left;
    Node* right;
    int mDepth;
} node_t;