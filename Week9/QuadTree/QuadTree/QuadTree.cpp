#include "include/QuadTree.h"

#include <memory>
#include <iostream>

QuadTree::QuadTree(Rectangle& boundary, const size_t capacity)
	: Rectangle(boundary.GetX(), boundary.GetY(), boundary.GetWidth(), boundary.GetHeight())
	, mCapacity(capacity)
	, mPoints(nullptr)
	, mSize(0)
	, mNorthWest(nullptr)
	, mNorthEast(nullptr)
	, mSouthWest(nullptr)
	, mSouthEast(nullptr)
	, mDivided(false)
{
	mPoints = new point_t[mCapacity];
}

QuadTree::~QuadTree()
{
	delete[] mPoints; mPoints = nullptr;

	delete mNorthEast; mNorthEast = nullptr;
	delete mNorthWest; mNorthWest = nullptr;
	delete mSouthEast; mSouthEast = nullptr;
	delete mSouthWest; mSouthWest = nullptr;
}

bool QuadTree::Insert(point_t& point)
{
	if (!Contain(point)) {
		return false;
	}

	if (mSize < mCapacity) {
		mPoints[mSize].x = point.x;
		mPoints[mSize].y = point.y;

		++mSize;

		return true;
	}
	else {
		if (!mDivided) {
			SubDivide();
		}
		
		if (mNorthEast->Insert(point)) {
			return true;
		}
		else if (mNorthWest->Insert(point)) {
			return true;
		}
		else if (mSouthEast->Insert(point)) {
			return true;
		}
		else if (mSouthWest->Insert(point)) {
			return true;
		}
	}
}

void QuadTree::Query(std::vector<point_t*>& o_found, const Rectangle& range)
{
	
	if (!range.Intersect(*this)) {
		return;
	}

	for (size_t i = 0; i < mSize; ++i) {
		if (range.Contain(mPoints[i])) {
			o_found.push_back(&mPoints[i]);
		}
	}

	if (mDivided) {
		mNorthEast->Query(o_found, range);
		mNorthWest->Query(o_found, range);
		mSouthEast->Query(o_found, range);
		mSouthWest->Query(o_found, range);
	}
}

void QuadTree::Print() const
{
	std::cout << "tree: " << std::endl;
	for (size_t i = 0; i < mSize; ++i) {
		std::cout << "x: " << mPoints[i].x << ", y: " << mPoints[i].y << std::endl;
	}

	if (mNorthEast) {
		mNorthEast->Print();
	}

	if (mNorthWest) {
		mNorthWest->Print();
	}

	if (mSouthEast) {
		mSouthEast->Print();
	}

	if (mSouthWest) {
		mSouthWest->Print();
	}
}

void QuadTree::SubDivide()
{
	float x = mCenter.x;
	float y = mCenter.y;
	int w = mWidth;
	int h = mHeight;

	Rectangle ne(x + w / 4, y + h / 4, w / 2, h / 2);
	Rectangle nw(x - w / 4, y + h / 4, w / 2, h / 2);
	Rectangle se(x + w / 4, y - h / 4, w / 2, h / 2);
	Rectangle sw(x - w / 4, y - h / 4, w / 2, h / 2);


	mNorthEast = new QuadTree(ne, mCapacity);
	mNorthWest = new QuadTree(nw, mCapacity);
	mSouthEast = new QuadTree(se, mCapacity);
	mSouthWest = new QuadTree(sw, mCapacity);

	mDivided = true;
}
