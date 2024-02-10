#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Top-down method
/// </summary>
/// <param name="num"></param>
/// <param name="cache"></param>
/// <returns></returns>
int FibonacciRecursive(int num, vector<int>& cache) {
	if (num <= 1) {
		return num;
	}

	if (cache[num] != 0) {
		return cache[num];
	}

	int result = FibonacciRecursive(num - 2, cache) +
				FibonacciRecursive(num - 1, cache);

	cache[num] = result;
	return result;
}

/// <summary>
/// Tabulation
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
int Fibonacci(int num) {
	if (num == 0) {
		return 0;
	}

	if (num == 1) {
		return 1;
	}

	int prePreVal = 0;
	int preVal = 1;
	int result = 0;
	for (int i = 2; i <= num; ++i) {
		result = prePreVal + preVal;
		prePreVal = preVal;
		preVal = result;
	}
	return result;
}

typedef struct Item {
	int price;
	int space;
} item_t;

int GetMaxValue(int numSpace, vector<Item>& items) {
	int numItems = items.size();
	
	int* cache = new int[numSpace * numItems];
	memset(cache, 0, numSpace * numItems);
	for (int i = 0; i < numSpace; ++i) {
		if (items[0].space > i + 1) {
			continue;
		}
		cache[i] = items[0].price;
	}
	
	for (int i = 1; i < numItems; ++i) {
		for (int j = 0; j < numSpace; ++j) {
			if (items[i].space > j + 1) {
				cache[numSpace * i + j] = cache[numSpace * (i - 1) + j];
				continue;
			}

			int remainingSpace = j + 1 - items[i].space;
			int remainingMaxValue = cache[numSpace * (i - 1) + remainingSpace];

			int choice1 = cache[numSpace * (i - 1) + j];
			int choice2 = items[i].price + remainingMaxValue;
			cache[numSpace * i + j] = max(choice1, choice2);
		}
	}

	int result = cache[numSpace * numItems - 1];
	delete[] cache; cache = nullptr;
	return result;
}

int main(void) {
	vector<int> cache;
	int num = 6;
	cache.resize(num + 1);
	int result = FibonacciRecursive(num, cache);
	cout << "Fibonacci top down method result: " << result << endl;

	result = Fibonacci(num);
	cout << "Fibonacci tabulation method result: " << result << endl;


	Item item1 = { 3, 5 };
	Item item2 = { 9, 12 };
	Item item3 = { 1, 2 };
	Item item4 = { 5, 4 };
	Item item5 = { 7, 9 };

	vector<Item> items;
	items.push_back(item1);
	items.push_back(item2);
	items.push_back(item3);
	items.push_back(item4);
	items.push_back(item5);
	int bagSpace = 15;
	int maxValue = GetMaxValue(bagSpace, items);

	cout << "max value: " << maxValue << endl;

	return 0;
}
