#include <iostream>

#include "MyArray.h"
#include "MyHashMap.h"
#include "MyLinkedList.h"
#include "MyQueue.h"
#include "MyStack.h"

using namespace std;

int main(void) {
    MyHashMap map;
    map.Add("test1", 1);
    map.Add("test2", 2);
    map.Add("test3", 3);
    map.Add("test4", 4);
    map.Add("test5", 5);
    map.Print();

    map.Add("test1", 10);
    map.Add("test5", 100);
    map.Print();

    cout << map.Get("test2") << endl;
    cout << map.Get("nokey") << endl;

    /*
    MyLinkedList list;
    list.insertFront(3);
    list.insertFront(5);
    list.insertFront(2);
    list.insertFront(0);
    list.printNode();
    list.remove(3);
    list.printNode();
    */

    MyArray array1;
    array1.insertAt(0, 0);
    array1.insertAt(0, 1);
    array1.insertAt(0, 2);
    array1.insertAt(0, 3);
    array1.insertAt(0, 4);
    array1.insertAt(0, 5);
    array1.insertAt(0, 6);
    array1.insertAt(0, 7);
    array1.insertAt(7, 8);

    array1.printInfo();

    array1.removeAt(7);
    array1.removeAt(0);
    array1.removeAt(0);
    array1.removeAt(5);
    array1.printInfo();

    cout << "index: " << array1.findIndex(20) << endl;
    /*
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
    */
    return 0;
}
