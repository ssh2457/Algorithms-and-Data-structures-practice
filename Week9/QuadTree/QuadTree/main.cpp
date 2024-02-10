#include <iostream>
#include <cstdlib>
#include <vector>

#include "include/QuadTree.h";
#include "include/Rectangle.h";

using namespace std;

int main(void) {
	Rectangle boundary(100.f, 100.f, 200, 200);
	size_t capacity = 4;

	QuadTree qtree(boundary, capacity);

	for (size_t i = 0; i < 10; ++i) {
		float x = rand() % 200;
		float y = rand() % 200;
		point_t point = { x, y };

		qtree.Insert(point);
	}

	qtree.Print();

	Rectangle range(150.f, 100.f, 50, 50);
	vector<point_t*> queryResults;
	qtree.Query(queryResults, range);

	cout << "query result: " << endl;
	for (size_t i = 0; i < queryResults.size(); ++i) {
		cout << "x: " << queryResults[i]->x << ", y: " << queryResults[i]->y << endl;
	}

	return 0;
}