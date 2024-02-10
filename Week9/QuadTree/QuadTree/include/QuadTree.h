#pragma once

#include <vector>

#include "Rectangle.h"

class QuadTree : public Rectangle {
public:
	QuadTree(Rectangle& boundary, const size_t capacity);
	virtual ~QuadTree();

	bool Insert(point_t& point);
	void Query(std::vector<point_t*>& o_found, const Rectangle& range);

	void Print() const;

private:
	size_t mCapacity;
	size_t mSize;
	point_t* mPoints;

	QuadTree* mNorthWest;
	QuadTree* mNorthEast;
	QuadTree* mSouthWest;
	QuadTree* mSouthEast;

	bool mDivided;

	void SubDivide();
};