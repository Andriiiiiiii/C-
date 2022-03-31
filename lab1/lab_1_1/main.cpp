#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int randd(int a, int b)
{
    int seed = rand();
    mt19937 generator(seed);
    uniform_int_distribution<int> distr(a, b);
    return distr(generator);
}

int main()
{
    const int n = 500;//кол-во повторений операции 
    int N = 100; // будем проверять от ... кол-ва клеток
    int a = 1001; // до ... 
    int b = 100; // шаг проверки
    for (int j = N; j < a; j+=b)
    {
        unsigned int sum = 0;
        for (int i = 0; i < n; i++) //цикл для одной точки
        {
            int t = 0;
            int pos_x = randd(1, j - 1), pos_y = randd(1, j - 1); //начальное положение
            while (pos_x < j && pos_x > 0 && pos_y < j && pos_y > 0) // 
            {
                int r = randd(1, 4);
                if (r == 1)
                {
                    pos_x--;
                }
                else if (r == 2)
                {
                    pos_y++;
                }
                else if (r == 3)
                {
                    pos_x++;
                }
                else if (r == 4)
                {
                    pos_y--;
                }
                t++;
            }
            sum += t;
        }
        cout << sum / n << endl;
    }
    cout << endl;
    for (int j = N; j < a; j+=b)
    {
        cout << j << endl;
    }

    return 0;
}