#include <iostream>

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

int main(void) {
    int fibonacciResult = fibanocciRecursive(5);
    int factorialReulst = factorialRecursive(5);
    int sumReuslt = sumRecursive(10);

    cout << "Fibonacci result: " << fibonacciResult << endl;
    cout << "Factorial result: " << factorialReulst << endl;
    cout << "Sum result: " << sumReuslt << endl;

    return 0;
}