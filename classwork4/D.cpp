#include <iostream>

using namespace std;

int sort(int* arr, int a, int b) 
{
    int num = arr[(a + b) / 2];
    int l = a;
    int r = b;
    int o = 0;
    while (true) 
    {
        while (arr[l] < num)
        {
            l++;
        }
        while (arr[r] > num)
        {
            r--;
        }
        if (l >= r)
        {
            return r;
        }
        int a_r = arr[l];
        arr[l] = arr[r];
        arr[r] = a_r;
        l++;
        r--;
    }
}

void sas(int* arr, int a, int b)
{
    if (a < b)
    {
        int p = sort(arr, a, b);
        sas(arr, a, p);
        sas(arr, p + 1, b);
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
    sas(a, 0, n - 1);
    cout << "Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}