#include <iostream>

#include "MyQueue.h"
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
    stack1.printInfo();

    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.printInfo();

    stack1.search(10);
    stack1.printInfo();

    stack1.search(70);
    stack1.printInfo();

    stack1.clear();
    stack1.printInfo();

    MyQueue queue1;
    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);
    queue1.enqueue(40);
    queue1.enqueue(50);
    queue1.enqueue(60);
    queue1.enqueue(70);
    queue1.printInfo();
    queue1.enqueue(80);
    queue1.printInfo();

    if (!queue1.isEmpty()) queue1.dequeue();
    queue1.printInfo();

    queue1.enqueue(90);
    queue1.printInfo();
    queue1.enqueue(100);
    queue1.printInfo();

    queue1.search(100);
    queue1.search(20);
    queue1.search(10);
    return 0;
}
