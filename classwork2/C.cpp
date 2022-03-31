#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	int x;
	cout << "Enter number:";
	cin >> x;
	while (x % 2 == 0)
	{
		x = x / 2;
	}
	if (x == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}