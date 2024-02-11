#include "BST.h"

BST::BST()
    : mRoot(nullptr) {
}

BST::BST(int data)
    : mRoot(nullptr) {
    mRoot = static_cast<node_t*>(malloc(sizeof(node_t)));
    memset(mRoot, 0, sizeof(node_t));
    mRoot->mData = data;
    mRoot->mDepth = 0;
}

BST::BST(const BST& bst)
    : mRoot(nullptr) {
    mRoot = DeepCopyRecursive(bst.mRoot);
}

BST::~BST() {
    ClearBSTRecursive(mRoot);
    mRoot = nullptr;
}

void BST::ClearBSTRecursive(node_t* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        free(node);
        memset(node, 0, sizeof(node_t));
        node = nullptr;
        return;
    }

    ClearBSTRecursive(node->left);
    ClearBSTRecursive(node->right);
    node->left = nullptr;
    node->right = nullptr;
    ClearBSTRecursive(node);
}

void BST::Insert(int data) {
    if (mRoot == nullptr) {
        mRoot = static_cast<node_t*>(malloc(sizeof(node_t)));
        memset(mRoot, 0, sizeof(node_t));
        mRoot->mData = data;
        mRoot->mDepth = 0;
        return;
    }

    InsertRecursive(mRoot, data, 0);
}

node_t* BST::InsertRecursive(node_t* node, int data, int depth) {
    if (node == nullptr) {
        node = static_cast<node_t*>(malloc(sizeof(node_t)));
        memset(node, 0, sizeof(node_t));
        node->mData = data;
        node->mDepth = depth;
        return node;
    }

    if (node->mData > data) {
        node->left = InsertRecursive(node->left, data, depth + 1);
    } else {
        node->right = InsertRecursive(node->right, data, depth + 1);
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

void BST::Delete(int data) {
    node_t* node = GetNodeOrNull(data);
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        free(node);
        node = nullptr;
        return;
    }

    // Find a node containing the previous value in the left-subtruee
    if (node->left) {
        node_t* predecessor = GetPredecessorRecursive(node->left);
        node_t* parent = GetParentNode(predecessor);

        int tmp = node->mData;
        node->mData = predecessor->mData;
        predecessor->mData = tmp;

        free(predecessor);
        memset(predecessor, 0, sizeof(node_t));
        predecessor = nullptr;

        parent->right = nullptr;

        return;
    }

    // Otherwise, find its parent node
    node_t* parentNode = GetParentNode(node);
    if (parentNode->left == node) {
        parentNode->left = node->right;
    } else {
        parentNode->right = node->right;
    }

    free(node);
    memset(node, 0, sizeof(node_t));
    node = nullptr;
}

node_t* BST::GetPredecessorRecursive(node_t* node) {
    if (node->right == nullptr) {
        return node;
    }
    return GetPredecessorRecursive(node->right);
}

node_t* BST::GetParentNode(node_t* node) {
    return GetParentNodeRecursive(mRoot, node);
}

node_t* BST::GetParentNodeRecursive(node_t* node, node_t* finding) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == finding || node->right == finding) {
        return node;
    }

    if (node->mData > finding->mData) {
        return GetParentNodeRecursive(node->left, finding);
    }
    return GetParentNodeRecursive(node->right, finding);
}

node_t* BST::DeepCopyRecursive(node_t* node) {
    if (node == nullptr) {
        return nullptr;
    }
    node_t* newNode = static_cast<node_t*>(malloc(sizeof(node_t)));
    newNode->mData = node->mData;
    newNode->mDepth = node->mDepth;
    newNode->left = DeepCopyRecursive(node->left);
    newNode->right = DeepCopyRecursive(node->right);

    return newNode;
}

void BST::PrintByDFS(void) {
    if (mRoot == nullptr) {
        return;
    }

    std::cout << "Print by DFS\n";

    std::stack<node_t*> nodeStack;
    nodeStack.push(mRoot);

    while (!nodeStack.empty()) {
        node_t* next = nodeStack.top();
        nodeStack.pop();

        for (int i = 0; i < next->mDepth; ++i) {
            std::cout << ' ';
        }
        std::cout << '-' << next->mData << '\n';

        if (next->left != nullptr) {
            nodeStack.push(next->left);
        }

        if (next->right != nullptr) {
            nodeStack.push(next->right);
        }
    }

    std::cout << "Print by DFS end\n";
}

void BST::PrintByBFS(void) {
    if (mRoot == nullptr) {
        return;
    }

    std::cout << "Print by BFS\n";

    std::queue<node_t*> nodeQueue;
    nodeQueue.push(mRoot);

    while (!nodeQueue.empty()) {
        node_t* next = nodeQueue.front();
        nodeQueue.pop();

        for (int i = 0; i < next->mDepth; ++i) {
            std::cout << ' ';
        }
        std::cout << '-' << next->mData << '\n';

        if (next->left != nullptr) {
            nodeQueue.push(next->left);
        }

        if (next->right != nullptr) {
            nodeQueue.push(next->right);
        }
    }
    std::cout << "Print by BFS end\n";
}