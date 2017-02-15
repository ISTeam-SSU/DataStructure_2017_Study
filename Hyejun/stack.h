#pragma once
#include "deque.h"

class myStack{
	private:
		myDeque d;

	public:
		myStack()
		{
		
		}

		~myStack()
		{

		}

		bool empty()
		{
			return d.empty();
		}

		int size()
		{
			return d.size();
		}

		int top()
		{
			return d.back();
		}

		void push(int data)
		{
			d.push_back(data);
		}

		void pop()
		{
			d.pop_back();
		}
};
