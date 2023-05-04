#include <iostream>
using namespace std;

// 判断是否为字串
bool pattern(char *s, char *p)
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0' && p[j] != '\0';)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (p[j] == '\0')
        return true;
    return false;
}

int main()
{
    char s[] = {"abcdefg"};
    char p[] = {"cdf"};
    cout << pattern(s, p) << endl;
}