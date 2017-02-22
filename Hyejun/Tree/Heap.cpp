#include <iostream>
#include <cstdlib>

using namespace std;

class Heap{
	private:
		int * data;  //0번째는 비워둠
		int size;
		bool maxMin;

	public:
		Heap()
		{
			data = (int *) calloc (20, sizeof(int));
			size = 0;
			maxMin = true;
		}

		~Heap()
		{
			free(data);
		}

		void isMin(bool input)
		{
			maxMin = input;
		}

		void insert(int inputData)
		{
			resize();

			data[++size] = inputData;
			int newDataIndex = size;
			int temp;

			for(int i = size / 2; i != 0; i /= 2)
			{
				if(maxMin)
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
				else
				{
					if(!(data[newDataIndex] < data[i]))
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
		}

		void pop()
		{
			int i = 1, temp, leafDataNum;
			data[1] = data[size];
			size--;

			while(i <= size)
			{
				if(maxMin)
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
				else
				{
					if(!(data[i*2] < data[i*2+1]))
						leafDataNum = i * 2;
					else
						leafDataNum = i * 2 + 1;

					if(!(data[i] > data[leafDataNum]) && leafDataNum <= size)
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
		}

		void output()
		{
			for(int i = 1; i <= size; i++)
				cout << "data[" << i << "]: " << data[i] << endl;
		}

		void resize()
		{
			static int re = 1;

			if(size == re * 20 - 1)
			{
				cout << "현재 배열 크기: " << size << " / 배열 크기를 늘립니다." << endl;
				int * newDataArray = (int *) calloc (++re * 20, sizeof(int));
				int * deleteArray = data;
				for(int i = 0; i <= size; i++)
				{
					newDataArray[i] = data[i];
				}
				data = newDataArray;
				free(deleteArray);
			}
		}

};

int main(void)
{
	Heap h;
	int menu, num;

	cout << "1. min  2. max: ";
	cin >> menu;

	if(menu == 1)
		h.isMin(true);
	else
		h.isMin(false);

	while(1)
	{
		cout << "1. insert  2. pop  3.output: ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cin >> num;
				h.insert(num);
				break;

			case 2:
				h.pop();
				break;

			case 3:
				h.output();
				break;

			default:
				exit(1);
		}
	}
	return 0;
}
