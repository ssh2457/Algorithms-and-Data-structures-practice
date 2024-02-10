#pragma once

#include <string>


class Node {
public:
	Node() = delete;
	Node(const std::string key, const int data);
	virtual ~Node();

	void SetNext(Node* const next);
	Node* GetNext();
	int GetData() const;
	const std::string& GetKey() const;

private:
	std::string mKey;
	int mData;
	Node* mNext;
};