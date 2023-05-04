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
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << i << " ";
    }
}

// 筛法求素数
void find_prime2(int n)
{
    bool *not_prime = new bool[n]{0};
    for (int i = 2; i <= n; i++)
    {
        if (not_prime[i])
            continue;

        bool flag = true;
        for (int j = 2; j <= int(sqrt(double(i))); j++)
            if (i % j == 0)
            {
                flag = false;
                break;
            }

        if (flag) // i是素数
        {
            for (int m = 1, k = i; k <= n; m++, k = i * m)
                not_prime[k] = 1; // 筛除i的倍数
            cout << i << " ";
        }
    }
    delete[] not_prime;
}

int main()
{
    find_prime2(100);
}