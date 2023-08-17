#include <cstddef>

class MyStack {
	public:
	MyStack();
	MyStack(size_t stackSize);
	~MyStack();
	virtual void push(int num);
	virtual int pop();
	virtual bool search(int num);
	virtual void clear();
	
	private:
	size_t mStackCount;
	size_t mStackSize;
	int* mStack;
	
	bool isEmpty();
};
