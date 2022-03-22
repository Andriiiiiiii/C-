#include <iostream>

using namespace std;


int main()
{
	int max = INT_MIN;
	cout << "Enter numbers:";
	int x;
	while (cin >> x && x != 0)
	{	
		if (x % 2 == 0 and x > max)
		{
			max = x;
		}
	}
	cout << max;
	return 0;
}