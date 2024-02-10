#include "include/Rectangle.h"

Rectangle::Rectangle(const float x, const float y, const int width, const int height)
	: mWidth(width)
	, mHeight(height)
{
	mCenter.x = x;
	mCenter.y = y;
}

bool Rectangle::Contain(point_t& point) const
{
	return (point.x > mCenter.x - mWidth / 2 &&
			point.x < mCenter.x + mWidth / 2 &&
			point.y > mCenter.y - mHeight / 2 &&
			point.y < mCenter.y + mHeight / 2);
}

bool Rectangle::Intersect(const Rectangle& other) const
{
	return !(other.mCenter.x - other.mWidth / 2 > mCenter.x + mWidth / 2 ||
		other.mCenter.x + other.mWidth / 2 < mCenter.x - mWidth / 2 ||
		other.mCenter.y - other.mHeight / 2 > mCenter.y + mHeight / 2 ||
		other.mCenter.y + other.mHeight / 2 < mCenter.y - mHeight / 2);
}

float Rectangle::GetX() const
{
	return mCenter.x;
}

float Rectangle::GetY() const
{
	return mCenter.y;
}

int Rectangle::GetWidth() const
{
	return mWidth;
}

int Rectangle::GetHeight() const
{
	return mHeight;
}

