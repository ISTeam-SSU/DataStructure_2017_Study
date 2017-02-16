#include<iostream>

using namespace std;

//insert, search

typedef struct _SNODE {
	int iData;
	struct _SNODE* spLeft;
	struct _SNODE* spRight;
}SNode;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	SNode* CreateNode(int iData);
	bool InsertNode(int iData);
	SNode* SearchNode(SNode* spIterator, int iNum);
	int SearchNum(int iNum);
	bool DeleteNode(int iNum);

private:
	SNode* spRoot;
	SNode* spCurrentNode;
	bool bleftRight;
};

BinaryTree::BinaryTree()
{
	spRoot = CreateNode(0);
	spCurrentNode = NULL;
}

BinaryTree::~BinaryTree()
{
	free(spRoot);
	free(spCurrentNode);
}

SNode* BinaryTree::CreateNode(int iData)
{
	SNode* spNewNode = (SNode*)malloc(1 * sizeof(SNode));
	spNewNode->iData = iData;
	spNewNode->spLeft = NULL;
	spNewNode->spRight = NULL;
	return spNewNode;
}

bool BinaryTree::InsertNode(int iData)
{
	SNode* spTmp;
	
	if (spRoot != NULL) 
	{
		spTmp = SearchNode(spRoot, iData);

			if (bleftRight)
			{
				spCurrentNode->spRight = CreateNode(iData);
			}

			else
			{
				spCurrentNode->spLeft = CreateNode(iData);
			}
		return true;
	}

	else
	{
		spTmp = CreateNode(iData);
		spRoot->spLeft = spTmp;
		spRoot->spRight = spTmp;
		return true;
	}
	return false;
}

SNode* BinaryTree::SearchNode(SNode* spIterator, int iNum)
{
	if (spIterator == NULL)
	{
		return spIterator;
	}

	if (iNum > spIterator->iData)
	{
		spCurrentNode = spIterator;
		bleftRight = true;
		return SearchNode(spIterator->spRight, iNum);
	}
	else if (iNum < spIterator->iData)
	{
		spCurrentNode = spIterator;
		bleftRight = false;
		return SearchNode(spIterator->spLeft, iNum);
	}
	else
	{
		return spIterator;
	}
}

int BinaryTree::SearchNum(int iNum)
{
	return SearchNode(spRoot, iNum)->iData;
}

bool BinaryTree::DeleteNode(int iNum)
{
	free(SearchNode(spRoot, iNum));
	return true;
}

int main()
{
	BinaryTree cTree;
	int  iOption;
	int iNum;
	while (true)
	{
		cout << "1. Insert Number 2.Search Number 3.Delete Node\n"  << endl;
		cin >> iOption;
		switch (iOption)
		{
		case 1:
			cout << "Input Number\n" << endl;
			cin >> iNum;
			if (cTree.InsertNode(iNum))
			{
				cout << "true\n" << endl;
			}
			else
			{
				cout << "fail\n" << endl;
			}
			break;
		case 2:
			cout << "Input Number\n" << endl;
			cin >> iNum;
			cout << cTree.SearchNum(iNum) << "\n" << endl;
			break;
		case 3:
			cout << "Input Number\n" << endl;
			cin >> iNum;
			if (cTree.DeleteNode(iNum))
			{
				cout << "true\n" << endl;
			}
			else
			{
				cout << "fail\n" << endl;
			}
			break;
		}
	}
	return 0;
}