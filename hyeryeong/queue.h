#pragma once
#include "deque.h"

class queue
{
public:
	queue();
	~queue();
	void push(int iData);
	void pop();
	bool empty();
	int size();
	int front();
	int back();


private:
	Deque cQueue;
};

queue::queue()
{
}

queue::~queue()
{
}

void queue::push(int iData) {
	cQueue.push_front(iData);
}

void queue::pop() {
	cQueue.pop_back();
}

bool queue::empty() {
	return cQueue.empty();
}
int queue::size() {
	return cQueue.size();
}

int queue::front() {
	return cQueue.front();
}

int queue::back() {
	return cQueue.back();
}