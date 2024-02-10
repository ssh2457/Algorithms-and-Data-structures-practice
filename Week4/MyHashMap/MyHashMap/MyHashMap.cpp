#include "MyHashMap.h"

MyHashMap::MyHashMap() : mHashGenerator(nullptr)
{
	mHashGenerator = MyHash::GetInstance();
	for (int i = 0; i < MAX_SIZE; ++i) {
		mArray[i] = nullptr;
	}
}

MyHashMap::~MyHashMap()
{
	delete mHashGenerator; mHashGenerator = nullptr;
	for (size_t i = 0; i < MAX_SIZE; ++i) {
		delete mArray[i]; mArray[i] = nullptr;
	}
}

void MyHashMap::Add(const std::string key, const int value)
{
	unsigned long hash = mHashGenerator->hash_65599(key.c_str(), sizeof(unsigned int));
	size_t index = hash % MAX_SIZE;

	Node* newNode = new Node(key, value);

	if (mArray[index] == nullptr) {
		mArray[index] = newNode;
		return;
	}

	Node* current = mArray[index];
	if (current->GetKey() == key) {
		newNode->SetNext(current->GetNext());
		mArray[index] = newNode;
		return;
	}

	while(current->GetNext() != nullptr) {
		Node* next = current->GetNext();
		if (next->GetKey() == key) {
			newNode->SetNext(next->GetNext());
			current->SetNext(newNode);
			return;
		}
		current = next;
	}
	current->SetNext(newNode);
}

int MyHashMap::Get(const std::string key) const
{
	unsigned long hash = mHashGenerator->hash_65599(key.c_str(), sizeof(unsigned int));
	size_t index = hash % MAX_SIZE;

	if (mArray[index] == nullptr) {
		return -1;
	}

	Node* current = mArray[index];
	while (current != nullptr) {
		if (current->GetKey() == key) {
			return current->GetData();
		}

		current->GetNext();
	}

	return -1;
}

void MyHashMap::Print() const
{
	for (size_t i = 0; i < MAX_SIZE; ++i) {
		std::cout << "index: " << i << std::endl;
		if (mArray[i] != nullptr) {
			Node* current = mArray[i];
			while (current != nullptr) {
				std::cout << "key: " << current->GetKey() << ", Data: " << current->GetData() << std::endl;
				current = current->GetNext();
			}
		}

		std::cout << std::endl << std::endl;
	}

}
