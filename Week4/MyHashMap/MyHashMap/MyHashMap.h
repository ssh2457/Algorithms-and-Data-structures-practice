#pragma once

#include <string>
#include <iostream>

#include "Node.h"
#include "MyHash.h"

class MyHashMap {
public:
	MyHashMap();
	virtual ~MyHashMap();

	void Add(const std::string key, const int value);

	int Get(const std::string key) const;

	void Print() const;

private:
	MyHash* mHashGenerator;
	static constexpr int MAX_SIZE = 10;
	Node* mArray[MAX_SIZE];
};