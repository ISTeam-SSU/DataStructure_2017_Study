#include "stack.h"

int main() {
	stack cMyStack;
	int iOption;
	int iNum;
	while (true) {
		cout << "1.empty 2.size 3.top 4.push 5.pop\n" << endl;
		cin >> iOption;
		switch(iOption){
		case 1:
			if (cMyStack.empty()) {
				cout << "empty" << endl;
			}
			else {
				cout << "not empty" << endl;
			}
			break;
		case 2:
			cout << cMyStack.size() <<endl;
			break;
		case 3:
			cout << cMyStack.top() << endl;
			break;
		case 4:
			cin >> iNum;
			cMyStack.push(iNum);
			break;
		case 5:
			cMyStack.pop();
		}
	}
	return 0;
}