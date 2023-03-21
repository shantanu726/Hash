#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int a[] = {2, 6, 2, 4, 8, 3, 9, 3, 1};
    int has[100] = {0};
    int n = sizeof(a) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        has[a[i]]++;
        if (has[a[i]] == 2)
        {
        cout << a[i] << " ";
        }
    }
    return 0;
}