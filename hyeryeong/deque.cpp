#include<iostream>
using namespace std;

typedef struct _DEQUENODE {
	int iData;
	struct _DEQUENODE* spPrevious;
	struct _DEQUENODE* spNext;
}SDequeNode;

class Deque
{
public:
	Deque();
	~Deque();
	int at(int iNum);
	int front();
	int back();
	void clear();
	void erase(int iData);
	void insert(int iNum, int iData);
	void pop_back();
	void pop_front();
	void push_back(int iData);
	void push_front(int iData); //size up
	int size();
	bool empty();

private:
	SDequeNode* spFrontNode = NULL;
	SDequeNode* spBackNode = NULL;
	int iSize = 0;
};

Deque::Deque()
{
	this->spFrontNode = NULL;
	this->spBackNode = NULL;
	this->iSize = 0;
}


Deque::~Deque()
{

}

bool Deque::empty()
{
	return iSize == 0;
}

int Deque::at(int iNum) {
	SDequeNode* spIterator;
	spIterator = spFrontNode;
	for (int i = 0; i < iNum; ++i) {
		spIterator = spIterator->spNext;
	}
	return spIterator->iData;
}

void Deque::clear() {
	int iSize = this->iSize;
	for (int i = 0; i < iSize; ++i) {
		pop_front();
	}
}

void Deque::erase(int iNum) {
	SDequeNode* spIterator;
	spIterator = spFrontNode;
	for (int i = 0; i < iNum; ++i) {
		spIterator = spIterator->spNext;
	}
	spIterator->spPrevious->spNext = spIterator->spNext;
	spIterator->spNext->spPrevious = spIterator->spPrevious;

	spIterator->spPrevious = NULL;
	spIterator->spNext = NULL;
	free(spIterator);
	--iSize;
}

void Deque::insert(int iNum, int iData) {
	SDequeNode* spIterator;
	SDequeNode* spNewNode;
	spNewNode = (SDequeNode*)malloc(sizeof(SDequeNode));
	spNewNode->iData = iData;
	if (iNum >= iSize || iNum <0) {
		cout << "error\n" << endl;
	}
	else {
		spIterator = spFrontNode;
		for (int i = 0; i < iNum; ++i) {
			spIterator = spIterator->spNext;
		}
		spNewNode->spNext = spIterator;
		spNewNode->spPrevious = spIterator->spPrevious;
		spNewNode->spPrevious->spNext = spNewNode;
		spIterator->spPrevious = spNewNode;
		++iSize;
	}
}
void Deque::push_front(int iData) {
	SDequeNode* spNewNode;
	spNewNode = (SDequeNode*)malloc(sizeof(SDequeNode));
	spNewNode->iData = iData;
	if (iSize != 0)
	{
		spFrontNode->spPrevious = spNewNode;
		spNewNode->spNext = spFrontNode;
		spFrontNode = spNewNode;
	}
	else
	{
		spFrontNode = spNewNode;
		spBackNode = spNewNode;
	}
	++iSize;
}

void Deque::push_back(int iData) {
	SDequeNode* spNewNode;
	spNewNode = (SDequeNode*)malloc(sizeof(SDequeNode));
	spNewNode->iData = iData;
	if (iSize != 0)
	{
		spBackNode->spNext = spNewNode;
		spNewNode->spPrevious = spBackNode;
		spBackNode = spNewNode;
	}
	else
	{
		spFrontNode = spNewNode;
		spBackNode = spNewNode;
	}
	++iSize;
}

void Deque::pop_front() {
	if (iSize == 0) {
		return;
	}
	SDequeNode* spDeletedNode;
	spDeletedNode = spFrontNode;
	spFrontNode = spFrontNode->spNext;
	if (iSize != 1) {
		spFrontNode->spPrevious = NULL;
	}
	free(spDeletedNode);
	--iSize;
}

void Deque::pop_back() {
	SDequeNode* spDeletedNode;
	spDeletedNode = spBackNode;
	spBackNode = spBackNode->spPrevious;
	spBackNode->spNext = NULL;
	free(spDeletedNode);
	--iSize;
}

int Deque::front() {
	return spFrontNode->iData;
}

int Deque::back() {
	return spBackNode->iData;
}


int Deque::size() {
	return iSize;
}

