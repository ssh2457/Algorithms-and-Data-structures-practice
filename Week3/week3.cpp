#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

namespace Sort {

void bubbleSort(vector<int>& vec) {
    if (vec.size() == 0) return;

    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
}

size_t FindMinIndex(vector<int>& vec, size_t startIdx) {
    size_t minIdx = startIdx;
    for (size_t i = startIdx + 1; i < vec.size(); ++i) {
        if (vec[minIdx] > vec[i]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void Swap(vector<int>& vec, size_t idx1, size_t idx2) {
    int tmp = vec[idx1];
    vec[idx1] = vec[idx2];
    vec[idx2] = tmp;
}

void SelectionSort(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        size_t minIdx = FindMinIndex(vec, i);
        Swap(vec, i, minIdx);
    }
}

size_t Partition(vector<int>& vec, size_t left, size_t right) {
    size_t i = (left - 1);
    for (size_t j = left; j < right; ++j) {
        if (vec[j] < vec[right]) {
            ++i;
            Swap(vec, i, j);
        }
    }

    size_t pivot = i + 1;
    Swap(vec, pivot, right);
    return pivot;
};

void QuickSortRecursive(vector<int>& vec, size_t left, size_t right) {
    if (left >= right || right >= vec.size()) {
        return;
    }

    size_t pivot = Partition(vec, left, right);

    QuickSortRecursive(vec, left, pivot - 1);
    QuickSortRecursive(vec, pivot + 1, right);
}

void QuickSort(vector<int>& vec) {
    QuickSortRecursive(vec, 0, vec.size() - 1);
}

}  // namespace Sort

int main(void) {
    vector<int> test1;
    test1.reserve(10);

    test1.push_back(5);
    test1.push_back(4);
    test1.push_back(3);
    test1.push_back(2);
    test1.push_back(1);
    test1.push_back(0);
    test1.push_back(6);
    test1.push_back(8);
    test1.push_back(7);
    test1.push_back(9);

    // Sort::bubbleSort(test1);
    // Sort::SelectionSort(test1);
    Sort::QuickSort(test1);

    return 0;
}
