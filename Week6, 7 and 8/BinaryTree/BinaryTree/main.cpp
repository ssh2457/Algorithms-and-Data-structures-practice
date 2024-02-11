#include <iostream>

#include "BST.h"

using namespace std;

int main(void) {
    //BST* bst = new BST(6);
    BST* bst = new BST();
    bst->Insert(6);
    bst->Insert(4);
    bst->Insert(10);
    bst->Insert(2);
    bst->Insert(1);
    bst->Insert(3);

    BST* bstCopy = new BST(*bst);
    bstCopy->GetNodeOrNull(10);

    bst->Insert(5);

    bst->Insert(8);
    bst->Insert(15);

    bst->Insert(7);
    bst->Insert(9);

    bst->Insert(12);
    bst->PrintByDFS();
    bst->Delete(10);

    node_t* found = bst->GetNodeOrNull(9);
    if (found) {
        cout << found->mData << endl;
    }

    bst->PrintByDFS();
    bst->PrintByBFS();

    delete bst;
    bst = nullptr;

    delete bstCopy;
    bstCopy = nullptr;

    return 0;
}