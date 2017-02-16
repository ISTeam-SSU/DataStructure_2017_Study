#include <iostream>
#include <cstdlib>

using namespace std;

class myTree_a{
	private:
		int data[100];  //0번째는 비워둠
		int size;
	
	public:
		myTree_a()
		{ 
			size = 0;
		}

		~myTree_a() { }

		void add(int inputData)
		{
			data[++size] = inputData;
		}

		int search(int num)
		{
			return data[num];
		}

		void printLeaf(int num)
		{
			cout << "Left: " << data[num*2] << ", Right: " << data[num*2+1] << endl;
		}
};

int main(void)
{
	myTree_a t;
	int menu, num;

	while(1)
	{
		cout << "1. add  2. search  3. printLeave: ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cin >> num;
				t.add(num);
				break;
			
			case 2:
				cin >> num;
				cout << t.search(num) << endl;
				break;

			case 3:
				cin >> num;
				t.printLeaf(num);
				break;

			default:
				exit(1);
		}
	}
	return 0;
}
