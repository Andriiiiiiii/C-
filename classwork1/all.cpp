#include <iostream>
#include <cmath>
using namespace std;

int nod(int a, int b)
{
	while (a != 0 and b != 0)
	{
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	return(a + b);
}
int nok(int a, int b)
{
	return(a*b/nod(a,b));
}
int ex1() 
{
	double a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	c = sqrt(pow(a, 2) + pow(b, 2));
	cout << "c = " << c;
	return 0;
}

int ex2()
{
	double a, b, c, x1, x2;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	double D = pow(b, 2) - 4 * a * c;
	if (a == 0)
	{
		x1 = -c / b;
		cout << "x = " << x1;
	}
	else if (D > 0 and a != 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if (D == 0 and a != 0)
	{
		x1 = -b / (2 * a);
		cout << "x = " << x1;
	}
	else if (D < 0 and a != 0)
	{
		cout << "none";
	}

	return 0;
}

int ex3()
{
	int n;
	int res = 1;
	cout << "n = ";
	cin >> n;
	int i = 1;
	while (i <= n)
	{
		res *= i;
		i++;
	}
	cout << "n! = " << res;
	return 0;
}

int ex4()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << nod(a, b);

	return 0;
}

int ex5()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << nok(a, b);
	return 0;
}

int main()
{
	int ex;
	cout << "The number of ex.: ";
	cin >> ex;
	if (ex == 1)
	{
		ex1();
	}
	else if (ex == 2)
	{
		ex2();
	}
	else if (ex == 3)
	{
		ex3();
	}
	else if (ex == 4)
	{
		ex4();
	}
	else if (ex == 5)
	{
		ex5();
	}
	return 0;
}
