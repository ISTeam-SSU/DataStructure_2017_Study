#include"queue.h"

int main() {
	queue cMyQueue;
	int iOption;
	int iNum;
	while (true) {
		cout << "1.empty 2.size 3.front 4.back 5.push 6.pop\n" << endl;
		cin >> iOption;
		switch (iOption) {
		case 1:
			if (cMyQueue.empty()) {
				cout << "empty" << endl;
			}
			else {
				cout << "not empty" << endl;
			}
			break;
		case 2:
			cout << cMyQueue.size() << endl;
			break;
		case 3:
			cout << cMyQueue.front() << endl;
			break;
		case 4:
			cout << cMyQueue.back() << endl;
			break;
		case 5:
			cin >> iNum;
			cMyQueue.push(iNum);
			break;
		case 6:
			cMyQueue.pop();
		}
	}
	return 0;
}