#include <iostream>

using namespace std;

const int N = 10;
void sort (int (&a)[N])
{
    int i = 1;
    int j = 2;
    while (i < N) // реализация сортировки
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
}


int main()
{
    int a[N] = { 0 };
    cout << " Enter set of numbers:";
    for (int i = 0; i < N; i++) // заполняем массив
    {
        cout << endl;
        cin >> a[i];
    }
    sort(a);
    cout << endl;
    cout << "Sort: ";
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    int n; // ищем число 
    cout << "Enter number: ";
    cin >> n;
    int l = 0; // левое значение
    int r = N - 1; // правое значение
    int c = 0; 
    while (c != 1)
    {
        c = 0;
        int sr = (r + l) / 2;
        if (a[sr] < n)
        {
            l = sr;
        }
        else if ( a[sr] > n)
        {
            r = sr;
        }
        else
        {
            r = l = sr;
        }
        for (int k = l; k <= r; k++)
        {
            c++;
            cout << a[k] << " ";
        }
        cout << endl;
        if (c == 2 and a[r] == n)
        {
            cout << a[r];
            c = 1;
        }
    }
}
