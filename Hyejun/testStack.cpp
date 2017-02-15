#include <iostream>
#include "stack.h"

int main(void)
{
	myStack s;
	int menu, data;

	while(1)
	{
		cout << "\n메뉴를 선택하세요" << endl;
		cout << "1. empty  2. size  3. top  4. push  5. pop  :";
		cin >> menu;

		switch(menu)
		{
			case 1:
				if(s.empty())
					cout << "Stack is empty" << endl;
				else
					cout << "Stack is not empty" << endl;
				break;

			case 2:
				cout << s.size() << endl;
				break;

			case 3:
				cout << s.top() << endl;
				break;

			case 4:
				cout << "값을 입력하세요: ";
				cin >> data;
				s.push(data);
				break;

			case 5:
				s.pop();
				break;

			default:
				exit(1);
		}
	}

	return 0;
}
