#include <iostream>
#include "queue.h"

int main(void)
{
	myQueue q;
	int menu, data;

	while(1)
	{
		cout << "\n메뉴를 선택하세요" << endl;
		cout << "1. empty  2. size  3. front  4. back  5. push  6.pop  :";
		cin >> menu;

		switch(menu)
		{
			case 1:
				if(q.empty())
					cout << "Queue is empty" << endl;
				else
					cout << "Queue is not empty" << endl;
				break;

			case 2:
				cout << q.size() << endl;
				break;

			case 3:
				cout << q.front() << endl;
				break;

			case 4:
				cout << q.back() << endl;
				break;

			case 5:
				cout << "값을 입력하세요: ";
				cin >> data;
				q.push(data);
				break;

			case 6:
				q.pop();
				break;

			default:
				exit(1);
		}
	}

	return 0;
}
