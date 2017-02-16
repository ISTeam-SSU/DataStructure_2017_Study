#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
	int data;
	Node * leftNode;
	Node * rightNode;
} Node;

class myTree_L{
	private:
		Node * root;
		Node * thisNode;
		int thisNodeNumber;
	
	public:
		myTree_L()
		{
			root = NULL;
			thisNode = NULL;
			thisNodeNumber = 0;
		}

		~myTree_L()
		{
			free(root);
			free(thisNode);
		}

		bool insert(int data)
		{
			Node * newNode = (Node *) malloc(sizeof(Node));
			newNode -> data = data;
			newNode -> rightNode = NULL;
			newNode -> leftNode = NULL;

			if(root == NULL)
			{
				root = newNode;
				thisNodeNumber = 1;
			}
			else
			{
				thisNode = root;
				thisNodeNumber = 1;
				Node * p = searchNode(thisNode, data);

				if(p == NULL)
				{
					if(data < thisNode -> data)
						thisNode -> leftNode = newNode;
					else
						thisNode -> rightNode = newNode;
					return true;
				}
				else 
					return false;
			}
		}

		int getNodeNumber()
		{
			return thisNodeNumber;
		}

		Node * searchNode(Node * p, int data)
		{
			if(p == NULL)
				return p;

			thisNode = p;

			if(data < p -> data)
			{
				thisNodeNumber = thisNodeNumber * 2;
				return searchNode(p -> leftNode, data);
			}
			else if(data > p -> data)
			{
				thisNodeNumber = thisNodeNumber * 2 + 1;
				return searchNode(p -> rightNode, data);
			}
			else
				return p;
		}
};

int main(void)
{
	myTree_L t;
	int num;

	while(1)
	{
		cin >> num;
		t.insert(num);
		cout << "NodeNumber : " << t.getNodeNumber() << endl;
	}
	return 0;
}
