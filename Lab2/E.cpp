#include <iostream>

using namespace std;


int main()
{
	int max = INT_MIN;
	int c = 1;
	cout << "Enter numbers:";
	int x;
	while (cin >> x && x != 0)
	{
		if (x > max)
		{
			c == 0;
			max = x;
		}
		else if (x == max)
		{
			c++;
		}
	}
	cout << c;
	return 0;
}