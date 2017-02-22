#include <iostream>
#include <cstdlib>

using namespace std;

class myTree_a{
	private:
		int * data;  //0번째는 비워둠
		int size;
		bool maxMin;

	public:
		myTree_a()
		{
			data = (int *) calloc (20, sizeof(int));
			size = 0;
			maxMin = false;
		}

		~myTree_a()
		{
			free(data);
		}

		void insert(int inputData)
		{
			data[++size] = inputData;
			int newDataIndex = size;
			int temp;

			for(int i = size / 2; i != 0; i/=2)
			{
				if(data[newDataIndex] < data[i])
				{
					temp = data[i];
					data[i] = data[newDataIndex];
					data[newDataIndex] = temp;

					newDataIndex = i;
				}
				else
					break;
			}
		}

		void pop()
		{
			int i = 1, temp, leafDataNum;
			data[1] = data[size];
			size--;

			while(i <= size)
			{
				if(data[i*2] < data[i*2+1])
					leafDataNum = i * 2;
				else
					leafDataNum = i * 2 + 1;

				if(data[i] > data[leafDataNum] && leafDataNum <= size)
				{
					temp = data[i];
					data[i] = data[leafDataNum];
					data[leafDataNum] = temp;
					i = leafDataNum;
				}
				else
					break;
			}
		}

		void output()
		{
			for(int i = 1; i <= size; i++)
				cout << "data[" << i << "]: " << data[i] << endl;
		}
};

int main(void)
{
	myTree_a t;
	int menu, num;

	while(1)
	{
		cout << "1. insert  2. pop  3.output: ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cin >> num;
				t.insert(num);
				break;

			case 2:
			  t.pop();
				break;

			case 3:
				t.output();
				break;

			default:
				exit(1);
		}
	}
	return 0;
}
