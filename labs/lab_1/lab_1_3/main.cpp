#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;

int randd(int a, int b)
{
    int seed = rand() + time(NULL);
    mt19937 generator(seed);
    uniform_int_distribution<int> distr(a, b);
    return distr(generator);
}

int main()
{
    const int k = 100; // площадь дислокации max
    const int N = 101; // площадь кристалла
    const double n = 1000;

    double sum = 0;
    for (int u = 100; u < N; u+=50) // меняем площадь
    {
        for (int p = 0; p < n; p++) // усреднение
        {
            int q = 1;
            int pos_x[k];
            int o[k] = { 0 };
            for (int i = 0; i < k; i++)
            {
                pos_x[i] = randd(0, u);
                int ii = i;
                for (int h = 0; h < ii; h++)
                {
                    if (pos_x[ii] == pos_x[h])
                    {
                        i--;
                    }
                }
               // cout << i + 1 << " x -- " << pos_x[i] << endl;
            }
            int t = 0;
            while (q != 0) // основной цикл 
            {
                t++;
                q = 0;
                for (int j = 0; j < k; j++) // проверка на запуск
                {
                    if (pos_x[j] < u && pos_x[j] > 0 && o[j] == 0)
                    {
                        q++;
                    }
                }
                for (int l = 0; l < k; l++) // начинаем ходить
                {
                    int r = randd(1, 2);
                    if (o[l] == 0 && pos_x[l] < u && pos_x[l] > 0) // ход
                    {
                        if (r == 1)
                        {
                            pos_x[l]--;
                        }
                        else if (r == 2)
                        {
                            pos_x[l]++;
                        }
                    }
                    for (int i = 0; i < k; i++) // проверка хода в одну клетку
                    {
                        if (i != l)
                        {
                            if (pos_x[i] == pos_x[l])
                                pos_x[i]--;
                        }
                    }
                    //cout << l + 1 << " -- x: " << pos_x[l] << endl;
                }
                //cout << endl;
                for (int l = 0; l < k; l++)
                {
                    for (int j = 0; j < k; j++) // проверка слипания с другими
                    {
                        int dx = pos_x[l] - pos_x[j];
                        if (j != l)
                        {
                            if (dx == 1 or dx == -1)
                            {
                                o[j] = 1;
                                o[l] = 1;
                            }
                        }
                    }
                }
            }
           //cout << endl;
            sum += t;
        }
        double t_sr = sum / n;
        cout << t_sr << endl;
        //cout << sum;
    }
    cout << endl;
    for (int u = 10; u < N; u+=50) // меняем площадь
    {
        cout << u << endl;
    }

    return 0;
}