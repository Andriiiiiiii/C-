#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	double x = 0;
	for (int i = 1; i <= n; i++)
	{
		x += 1 / pow(i, 2);
	}
	cout << x;
}