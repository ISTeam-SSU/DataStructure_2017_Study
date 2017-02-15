#include <iostream>
using namespace std;

class Test{
	private:
		int num;

	public:

		Test(int n)
		{
			num = n;
		}

		~Test()
		{
		}

		void Print()
		{
			cout << "Number: " << num << endl;
		}
};

int main(void)
{
	int n;

	cout << "Input number: ";
	cin  >> n;
	Test t(n);
	t.Print();
	return 0;
}
