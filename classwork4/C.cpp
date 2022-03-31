#include <iostream>

using namespace std;

void meas()
{
	static int c = 0;
	c++;
	cout << c << endl;
}

int main()
{
	int n = 20;
	for (int i = 0; i < n; i++)
	{
		meas();
	}
	return 0;
}