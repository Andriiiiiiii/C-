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
    const int N = 10; // площадь кристалла
    const double n = 1000; // для усреднения

    double sum = 0; // для подсчёта времени
    for (int p = 0; p < n; p++) // усреднение
    {
        int q = 1; // для цикла while
        int pos_x[k];
        int pos_y[k];
        int o[k] = { 0 };
        for (int i = 0; i < k; i++) // даем координаты
        {
            pos_x[i] = randd(0, N);
            pos_y[i] = randd(0, N);
            int ii = i;
            for (int h = 0; h < ii; h++)
            {
                if (pos_x[ii] == pos_x[h] and pos_y[ii] == pos_y[h])
                {
                    i--;
                }
            }
            //cout << i + 1 << " x -- " << pos_x[i] << " y  -- " << pos_y[i] << endl;
        }
        int t = 0;
        while (q != 0) // основной цикл 
        {
            t++;
            q = 0;
            for (int j = 0; j < k; j++) // проверка на запуск
            {
                if (pos_x[j] < N && pos_y[j] < N && pos_y[j] > 0 && pos_x[j] > 0 && o[j] == 0)
                {
                    q++;
                }
            }
            for (int l = 0; l < k; l++) // начинаем ходить
            {
                int r = randd(1, 4);
                if (o[l] == 0 && pos_x[l] < N && pos_y[l] < N && pos_y[l] > 0 && pos_x[l] > 0) // ход
                {
                    if (r == 1)
                    {
                        pos_x[l]--;
                    }
                    else if (r == 2)
                    {
                        pos_y[l]++;
                    }
                    else if (r == 3)
                    {
                        pos_x[l]++;
                    }
                    else if (r == 4)
                    {
                        pos_y[l]--;
                    }
                }
                for (int i = 0; i < k; i++) // проверка хода в одну клетку
                {
                    if (i != l)
                    {
                        if (pos_x[i] == pos_x[l])
                            pos_x[i]--;
                        if (pos_y[i] == pos_y[l])
                            pos_y[i]--;
                    }
                }
                //cout << l + 1 << " -- x: " << pos_x[l] << " y: " << pos_y[l] << endl;

            }
            //cout << endl;
            for (int l = 0; l < k; l++)
            {
                for (int j = 0; j < k; j++) // проверка слипания с другими
                {
                    int dx = abs(pos_x[l] - pos_x[j]);
                    int dy = abs(pos_y[l] - pos_y[j]); // проверить диаг
                    if (j != l)
                    {
                        if ((dx == 1 and dy == 0) or (dx == -1 and dy == 0) or (dy == 1 and dx == 0) or (dy == -1 and dx == 0))
                        {
                            o[j] = 1;
                            o[l] = 1;
                        }
                    }
                }
            }
        }
        //cout << t<<endl;
        sum += t;
        cout << p << endl;
    }
    double t_sr = sum / n;
    cout << t_sr << endl;
    //cout << sum;

    return 0;
}