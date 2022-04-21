#include <iostream>
#include <cmath>

using namespace std;

float const f_pi = 3.14159265359f;

float mean(float psi[], float const pdf[], float const dv, unsigned size)
{
	for (long int i = 0; i < size; i++)
	{
		psi[i] = psi[i] * pdf[i] * dv;
	}
	for (long int i = 1; i < size; i *= 2)
	{
		for (long int k = 0; k + i < size; k += 2 * i)
		{
			psi[k] += psi[k + i];
		}
	}
	return psi[0];
}

int main()
{
	float n = 10000000; // количество точек
	float T = 0.f; // температура
	T = 0.00001;
	float V_min = -sqrt(pow(40 * log(T) + T, 2));
	float V_max = sqrt(pow(40 * log(T) + T, 2));
	float* psi = nullptr;
	psi = new float[n];
	float* pdf = nullptr;
	pdf = new float[n];
	float V = V_min;
	float delta = (V_max - V_min) / n;
	for (int i = 0; i < n; i++)
	{
		psi[i] = fabs(V);
		pdf[i] = exp(-pow(V, 2) / T) / sqrt(T * f_pi);
		V += delta;
	}
	float real = sqrt(T / f_pi);
	cout << mean(psi, pdf, delta, n) << endl;
	cout << "Real value = " << real;
	delete[]psi;
	delete[]pdf;
	return 0;
}