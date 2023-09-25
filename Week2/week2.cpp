#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int fibanocciRecursive(int num) {
    if (num <= 1) {
        return num;
    }
    return fibanocciRecursive(num - 1) + fibanocciRecursive(num - 2);
}

int factorialRecursive(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * factorialRecursive(num - 1);
}

int sumRecursive(int num) {
    if (num <= 1) {
        return num;
    }

    return num + sumRecursive(num - 1);
}

int binarySearchRecursive(vector<int>& vec, int leftIndex, int rightIndex, int value) {
    if (leftIndex > rightIndex) {
        return -1;
    }

    int mid = (leftIndex + rightIndex) / 2;

    if (vec[mid] == value) {
        return mid;
    }

    if (vec[mid] < value) {
        return binarySearchRecursive(vec, mid + 1, rightIndex, value);
    } else {
        return binarySearchRecursive(vec, leftIndex, mid - 1, value);
    }
}

int main(void) {
    int fibonacciResult = fibanocciRecursive(5);
    int factorialReulst = factorialRecursive(5);
    int sumReuslt = sumRecursive(10);

    cout << "Fibonacci result: " << fibonacciResult << endl;
    cout << "Factorial result: " << factorialReulst << endl;
    cout << "Sum result: " << sumReuslt << endl;

    vector<int> vec1;
    vec1.reserve(16);
    cout << "vec1 size: " << vec1.size() << endl;
    cout << "vec1 capacity: " << vec1.capacity() << endl;

    vec1.push_back(2);
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(10);
    vec1.push_back(15);
    vec1.push_back(21);
    vec1.push_back(32);
    vec1.push_back(35);
    vec1.push_back(39);
    vec1.push_back(43);
    vec1.push_back(44);
    vec1.push_back(47);
    vec1.push_back(99);

    sort(vec1.begin(), vec1.end());

    int indexResult = binarySearchRecursive(vec1, 0, vec1.size() - 1, 11);
    cout << indexResult << endl;

    return 0;
}