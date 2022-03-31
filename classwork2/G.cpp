#include <iostream>

using namespace std;

int main()
{
	int x;
	cout << "Enter number:";
	cin >> x;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			cout << i << " ";
		}
	}
}