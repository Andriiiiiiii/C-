#include <iostream>
#include <cmath>

using namespace std;

float const f_pi = 3.14159265359f;

float mean(float const psi[], float const pdf[], float const dv, unsigned size)
{
	static float x = 0.f;
	if (size != 1)
	{
		x = fma(mean(psi, pdf, dv, size / 2), 1, mean(psi + size / 2, pdf + size / 2, dv, size - size / 2));
		return x;
	}
	else
	{
		x = fma(fmaf(psi[0], pdf[0], 0), dv, 0);
		return x;
	}
}

int main()
{
	float n = 10000000; // количество точек
	float T = 0.f; // температура
	T = 0.000001;
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