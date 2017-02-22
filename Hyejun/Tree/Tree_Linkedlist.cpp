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
		Node * parentNode;
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

		Node * searchNode(Node * p, int data)
		{
			if(p == NULL)
				return p;

			thisNode = p;

			if(data < p -> data)
			{
				thisNodeNumber = thisNodeNumber * 2;
				parentNode = thisNode;
				return searchNode(p -> leftNode, data);
			}
			else if(data > p -> data)
			{
				thisNodeNumber = thisNodeNumber * 2 + 1;
				parentNode = thisNode;
				return searchNode(p -> rightNode, data);
			}
			else
				return p;
		}

		int getNodeNumber()
		{
			return thisNodeNumber;
		}

		void deleteNode(int data)
		{
			parentNode = NULL;
			thisNode = root;
			Node * p = searchNode(thisNode, data);

			if(p)
			{
				if(thisNode -> rightNode == NULL && thisNode -> leftNode == NULL)
				{
					if(parentNode)
					{
						if(parentNode -> leftNode -> data == thisNode -> data)
							parentNode -> leftNode == NULL;
						else
							parentNode -> rightNode == NULL;
					}

					free(thisNode);
				}
				else if(thisNode -> rightNode == NULL)
				{
					if(parentNode)
					{
						if(parentNode -> leftNode -> data == thisNode -> data)
							parentNode -> leftNode = thisNode -> leftNode;
						else
							parentNode -> rightNode = thisNode -> leftNode;
					}
					else
						root = thisNode -> leftNode;

					free(thisNode);
				}
				else if(thisNode -> leftNode == NULL)
				{
					if(parentNode)
					{
						if(parentNode -> leftNode -> data == thisNode -> data)
							parentNode -> leftNode = thisNode -> rightNode;
						else
							parentNode -> rightNode = thisNode -> rightNode;
					}
					else
						root = thisNode -> rightNode;

					free(thisNode);
				}
				else
				{
					Node * leftDataNode = thisNode -> leftNode;
					Node * rightDataNode = thisNode -> rightNode;
					int leftlevel = 0, rightlevel = 0, temp;

					while(leftDataNode -> rightNode != NULL)
					{
						leftDataNode = leftDataNode -> rightNode;
						leftlevel++;
					}

					while(rightDataNode -> leftNode != NULL)
					{
						rightDataNode = rightDataNode -> leftNode;
						rightlevel++;
					}

					if(leftlevel > rightlevel)
					{
						Node * originThisNode = thisNode;
						Node * p = searchNode(root, leftDataNode -> data);
						if(leftDataNode -> leftNode != NULL)
						{
							temp = leftDataNode -> data;
							leftDataNode -> data = leftDataNode -> leftNode -> data;
							originThisNode -> data = temp;

							free(leftDataNode -> leftNode);
							leftDataNode -> leftNode = NULL;
						}
						else
						{
							temp = leftDataNode -> data;
							leftDataNode -> data = originThisNode -> data;
							originThisNode -> data = temp;

							parentNode -> rightNode = NULL;

							free(leftDataNode);
						}
					}
					else
					{
						Node * originThisNode = thisNode;
						Node * p = searchNode(root, rightDataNode -> data);
						if(rightDataNode -> rightNode != NULL)
						{
							temp = rightDataNode -> data;
							rightDataNode -> data = rightDataNode -> rightNode -> data;
							originThisNode -> data = temp;

							free(rightDataNode -> rightNode);
							rightDataNode -> rightNode = NULL;
						}
						else
						{
							temp = rightDataNode -> data;
							rightDataNode -> data = originThisNode -> data;
							originThisNode -> data = temp;

							parentNode -> leftNode = NULL;

							free(rightDataNode);
						}
					}
				}
			}
			else
				cout << "해당 데이터가 존재하지 않습니다." << endl;
		}
};

int main(void)
{
	myTree_L t;
	int menu, num;

	while(1)
	{
		cout << "1. insert  2. delete :";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cin >> num;
				t.insert(num);
				cout << "NodeNumber : " << t.getNodeNumber() << endl;
				break;
			case 2:
				cin >> num;
				t.deleteNode(num);
				break;
			default:
				exit(1);
		}
	}
	return 0;
}
