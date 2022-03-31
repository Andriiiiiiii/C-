#include <iostream>

using namespace std;

int main()
{
    const int N = 10;
    int a[N];
    for (int i = 0; i < N; i++) // заполн€ем массив
    {
        cin >> a[i];
        cout << endl;
    }
    int i = 1;
    int j = 2;
    while (i < N) // реализаци€ сортировки
    {
        if (a[i - 1] < a[i])
        {
            i = j;
            j = j + 1;
        }
        else
        {
            swap(a[i - 1], a[i]);
            i = i - 1;
        }

        if (i == 0)
        {
            i = j;
            j = j + 1;
        }
    }
    for (int i = 1; i < N; i++) // вывод
    {
        cout << a[i] << " ";
    }
    return 0;
}