#pragma once

#include "Point.h"

class Rectangle {
public:
	Rectangle(const float x, const float y, const int width, const int height);
	virtual ~Rectangle() = default;

	bool Contain(point_t& point) const;
	bool Intersect(const Rectangle& other) const;


	float GetX() const;
	float GetY() const;
	int GetWidth() const;
	int GetHeight() const;

protected:
	point_t mCenter;
	int mWidth;
	int mHeight;
};