#pragma once
#include "deque.h"

class stack
{
public:
	stack();
	~stack();
	void push(int iData);
	void pop();
	bool empty();
	int size();
	int top();


private:
	Deque cStack;
};

stack::stack()
{
}

stack::~stack()
{
}

void stack::push(int iData) {
	cStack.push_back(iData);
}

void stack::pop() {
	cStack.pop_back();
}

int stack::top() {
	return cStack.back();
}

bool stack::empty() {
	return cStack.empty();
}
int stack::size() {
	return cStack.size();
}
