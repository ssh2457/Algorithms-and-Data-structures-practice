#include <iostream>
#include <string>

#include "MyHashMap.h"

using namespace std;

int main(void) {
    
    MyHashMap map;
    string test1 = "test1";
    string test2 = "test2";
    string test3 = "test3";
    string test4 = "test4";
    string test5 = "test5";
    string test6 = "test6";
    
    map.Add(test1, 1);
    map.Add(test2, 2);
    map.Add(test3, 3);
    map.Add(test4, 4);
    map.Add(test5, 5);
    map.Add(test6, 6);

    map.Print();
    
    return 0;
}