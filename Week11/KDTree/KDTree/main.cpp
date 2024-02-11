#include "include/KDTree.h"

#include <iostream>

using namespace std;

int main(void) {

	point2D_t p1 = { 3.f, 6.f };
	point2D_t p2 = { 17.f, 15.f };
	point2D_t p3 = { 13.f, 15.f };
	point2D_t p4 = { 6.f, 12.f };
	point2D_t p5 = { 9.f, 1.f };
	point2D_t p6 = { 2.f, 7.f };
	point2D_t p7 = { 10.f, 19.f };

	KDTree kd_tree(p1);

	//kd_tree.Insert(p1);
	kd_tree.Insert(p2);
	kd_tree.Insert(p3);
	kd_tree.Insert(p4);
	kd_tree.Insert(p5);
	kd_tree.Insert(p6);
	kd_tree.Insert(p7);

	kd_tree.PrintByDFS();

	point2D_t p8 = {15.f, 15.f };
	point2D_t* nearest = kd_tree.NeareastNeighborOrNull(p8);

	if (nearest) {
		cout << "nearest: " << nearest->coords[0] << ", " << nearest->coords[1] << endl;
	}
	else {
		cout << "not found." << endl;
	}
	
	return 0;
}