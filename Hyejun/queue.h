#pragma once
#include "deque.h"

class myQueue{
	private:
		myDeque d;

	public:
		myQueue() { }

		~myQueue() { }

		bool empty()
		{
			return d.empty();
		}

		int size()
		{
			return d.size();
		}

		int front()
		{
			return d.front();
		}

		int back()
		{
			return d.back();
		}

		void push(int data)
		{
			d.push_back(data);
		}

		void pop()
		{
			d.pop_front();
		}
};
