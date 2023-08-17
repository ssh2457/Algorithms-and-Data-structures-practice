#include <iostream>

#include "MyStack.h"

using namespace std;

int main(void) {
    MyStack stack1;

    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);
    stack1.push(60);
    stack1.push(70);
    stack1.push(80);
    stack1.push(90);
    stack1.push(100);

    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();

    stack1.search(10);
    stack1.search(70);

    stack1.clear();

    return 0;
}
