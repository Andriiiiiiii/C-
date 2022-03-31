#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter siçe: ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int* i = &a[0]; i <= &a[n - 1]; i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    for (int* i = &a[n - 1]; i >= &a[0]; i--)
    {
        cout << *i << " ";
    }
    delete[]a;
    return 0;
}