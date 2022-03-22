#include <iostream>
using namespace std;

void ch_year(int x)
{
	if (x % 100 != 0 or x % 400 == 0)
	{
		if (x % 4 == 0)
		{
			cout << "YES";
		}
		else 
		{
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
}


int main() 
{
	int year;
	cout << "Enter your year:";
	cin >> year;
	ch_year(year);
}