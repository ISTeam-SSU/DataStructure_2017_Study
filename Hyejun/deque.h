#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct deqNode{
	int data = 0;
	deqNode *f_Node = NULL;
	deqNode *b_Node = NULL;
} deqNode;

class myDeque{
	private:
		deqNode *f_dqNode;
		deqNode *b_dqNode;
		int dqSize;

	public:
		myDeque()
		{
			this -> f_dqNode = NULL;
			this -> b_dqNode = NULL;
			dqSize = 0;
		}

		~myDeque()
		{
		}

		int at(int num)
		{
			if(num < 0 || num >= dqSize)
			{
				cout << "오류: 해당 " << num << "번째 값을 불러올 수 없습니다." << endl;
				return -1;
			}
			else{
				deqNode * p_Node = f_dqNode;
				for(int i = 0; i < num; i++)
					p_Node = p_Node->b_Node;

				return p_Node -> data;
			}
		}

		int back()
		{
			if(b_dqNode == NULL)
			{
				cout << "출력할 값이 없습니다." << endl;
				return -1;
			}
			else
				return b_dqNode -> data;
		}

		int front()
		{
			if(f_dqNode == NULL)
			{
				cout << "출력할 값이 없습니다." << endl;
				return -1;
			}
			else
				return f_dqNode -> data;
		}

		void clear()
		{
			for(int i = 0; i < dqSize-1; i++)
			{
				f_dqNode = f_dqNode -> b_Node;
				free (f_dqNode -> f_Node);
			}

			free(b_dqNode);

			f_dqNode = NULL;
			b_dqNode = NULL;
			dqSize = 0;
		}

		void pop_back()
		{
			if(b_dqNode == NULL)
				cout << "삭제할 값이 없습니다." << endl;
			else
			{
				if(dqSize == 1)
					clear();
				else{
					b_dqNode = b_dqNode -> f_Node;
					free (b_dqNode -> b_Node);
					b_dqNode -> b_Node = NULL;
					dqSize--;
				}
			}
		}

		void pop_front()
		{
			if(f_dqNode == NULL)
				cout << "삭제할 값이 없습니다." << endl;
			else
			{
				if(dqSize == 1)
					clear();
				else{
					f_dqNode = f_dqNode -> b_Node;
					free (f_dqNode -> f_Node);
					f_dqNode -> f_Node = NULL;
					dqSize--;
				}
			}
		}

		void push_back(int num)
		{
			deqNode *newNode;
			newNode = (deqNode *) malloc(sizeof(deqNode));
			newNode->data = num;
			newNode->b_Node = NULL;

			if(dqSize)
			{
				newNode->f_Node = b_dqNode;
				b_dqNode -> b_Node = newNode;
			}
			else
			{
				newNode->f_Node = NULL;
				f_dqNode = newNode;
			}

			b_dqNode = newNode;
			dqSize++;
		}

		void push_front(int num)
		{
			deqNode *newNode;
			newNode = (deqNode *) malloc(sizeof(deqNode));
			newNode->data = num;
			newNode->f_Node = NULL;

			if(dqSize)
			{
				newNode->b_Node = f_dqNode;
				f_dqNode -> f_Node = newNode;
			}
			else
			{
				newNode->b_Node = NULL;
				b_dqNode = newNode;
			}

			f_dqNode = newNode;
			dqSize++;
		}

		void insert(int num, int data)
		{

			if( num < 0 || num > dqSize)
				cout << "오류: 해당 " << num << "번째에 값을 저장할 수 없습니다." << endl;
			else
			{
				deqNode * newNode = (deqNode *) malloc(sizeof(deqNode));
				newNode -> data = data;

				if(num == 0)
					push_front(data);
				else if(num == dqSize)
					push_back(data);
				else
				{
					deqNode * p_Node = f_dqNode;
					for(int i = 0; i < num; i++)
						p_Node = p_Node->b_Node;

					newNode -> b_Node = p_Node;
					p_Node -> f_Node -> b_Node = newNode;
					newNode -> f_Node = p_Node -> f_Node;
					p_Node -> f_Node = newNode;
					dqSize ++;
				}
			}
		}

		int size()
		{
			return dqSize;
		}

		bool empty()
		{
			return (dqSize == 0);
		}

};
