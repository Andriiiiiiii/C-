#include <iostream>
using namespace std;

int ch_numb(int x)
{
	if (x % 2 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	int c = 0;
	cout << "Enter numbers:";
	int x;
	while (cin >> x && x != 0)
	{
		c += ch_numb(x);
	}
	cout << c;
	return 0;
}