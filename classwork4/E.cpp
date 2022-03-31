#include <iostream>

using namespace std;

void sas(int* a, int n, int i)
{
    int ll = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[ll])
    {
        ll = l;
    }
    if (r < n && a[r] > a[ll])
    {
        ll = r;
    }
    if (ll != i)
    {
        swap(a[i], a[ll]);
        sas(a, n, ll);
    }
}

void sort(int* a, int n)
{
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        sas(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        sas(a, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    int* a = new int[n];
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    cout << "Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}