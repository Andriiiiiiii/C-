#include <iostream>

using namespace std;

int main()
{
	int x;
	int b = 0;
	cout << "Enter number:";
	cin >> x;
	for (int i = 2; i*i < x; i++)
	{
		if (x % i == 0)
		{
			b = 1;
		}
	}
	if (b == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}