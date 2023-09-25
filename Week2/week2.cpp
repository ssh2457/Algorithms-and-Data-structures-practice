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

int indexOfRotatedArray(int* array, int start, int end, int num) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (array[mid] == num) {
        return mid;
    }

    if (array[start] <= array[mid]) {
        if (array[start] <= num && num <= array[mid]) {
            return indexOfRotatedArray(array, start, mid - 1, num);
        }
        return indexOfRotatedArray(array, mid + 1, end, num);
    }

    if (array[mid] <= num && num <= array[end]) {
        return indexOfRotatedArray(array, mid + 1, end, num);
    }
    return indexOfRotatedArray(array, start, mid - 1, num);
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

    int arr[] = {20, 25, 26, 29, 33, 1, 3, 5, 6, 10, 11, 19};
    int index = indexOfRotatedArray(arr, 0, sizeof(arr) / sizeof(int), 0);
    cout << index << endl;
    return 0;
}