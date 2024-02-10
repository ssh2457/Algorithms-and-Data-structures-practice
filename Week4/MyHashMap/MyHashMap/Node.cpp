#include "Node.h"

Node::Node(const std::string key, const int data) : mKey(key), mData(data), mNext(nullptr)
{

}

Node::~Node()
{
	Node* next = this->GetNext();
	if (next != nullptr) {
		delete next; next = nullptr;
	}
}

void Node::SetNext(Node* const next)
{
	mNext = next;
}

Node* Node::GetNext()
{
	return mNext;
}

int Node::GetData() const
{
	return mData;
}

const std::string& Node::GetKey() const
{
	return mKey;
}
