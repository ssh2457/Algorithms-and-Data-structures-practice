#include <iostream>

#include "BST.h"

using namespace std;

int main(void) {
    BST* bst = new BST(6);
    bst->Insert(4);
    bst->Insert(10);
    bst->Insert(2);
    bst->Insert(1);
    bst->Insert(3);

    bst->Insert(5);

    node_t* found = bst->GetNodeOrNull(5);
    cout << found->mData << endl;

    delete bst;
    bst = nullptr;
    return 0;
}