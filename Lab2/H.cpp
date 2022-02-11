#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, x, y = 0;
	cout << "Enter N: ";
	cin >> N;
	cout << "Enter number: ";
	cin >> x;
	if (x < pow(10, (N-1)))
	{
		cout << "Error";
	}
	else
	{
		int cx = x;
		for (int k = 0; k < N; k++)
		{
			y += (cx % 10) * pow(10, (N-k-1));
			cx = cx / 10;
		}
		if (y == x)
		{
			cout << 1;
		}
		else
		{
			cout << y;
		}
	}
}