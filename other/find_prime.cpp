#include <iostream>
#include <cmath>

using namespace std;

void find_prime1(int n)
{
    for (int i = 2; i <= n; i++)
    {
        bool flag = true;
        for (int j = 2; j <= int(sqrt(double(i))); j++)
        {
            if (i % j == 0)
                flag = false;
        }
        if (flag)
            cout << i << " ";
    }
}

void find_prime2(int n)
{
    bool is_prime[n] = {0}; // 素数表
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            continue;

        bool flag = true;
        for (int j = 2; j <= int(sqrt(double(i))); j++)
            if (i % j == 0)
                flag = false;

        if (flag) // i是素数
        {
            for (int m = 1, k = i; k <= n; m++, k = i * m)
                is_prime[k] = 1; // 筛除i的倍数
            cout << i << " ";
        }
    }
}

int main()
{
    find_prime2(100);
}