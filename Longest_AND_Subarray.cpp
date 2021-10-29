#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin>>t;
    while (t--)
    {
        cin >> n;
        int ref = log2(n);
        int pow2=pow(2, ref);
        int curr = n - pow2 + 1;
        int prev = pow2/2;
        if (curr > prev)
            cout << curr <<endl;
        else
            cout << prev <<endl;
    }
    return 0;
}