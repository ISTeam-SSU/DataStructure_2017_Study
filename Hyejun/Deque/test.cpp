#include "stack.h"
#include "queue.h"

using namespace std;

int main(void)
{
	myStack s;
	myQueue q;

	s.push(10);
	s.push(10);

	cout << s.size() << endl;
	cout << s.top() << endl;

	s.pop();

	cout << s.top() << endl;

	return 0;
}
