#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << "Enter number: ";
	cin >> x;
	for (int i = 2; i <= x; i++)
	{
		if (x % i == 0) // проверка на делимость на i
		{
			//cout << "i = " << i << endl;
			int c = 0;
			for (int k = 2; k*k < i; k++)// выводим делители i 
			{
				if (i % k == 0)
				{
					c = 1;
				}
			}
			if (c != 1)
			{
				cout << i << " ";
			}
			
		}
	}

}