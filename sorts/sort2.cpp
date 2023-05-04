#include <iostream>
using namespace std;

#pragma region insert_sort
void insert_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            int t = a[i], j;
            for (j = i - 1; j >= 0 && a[j] > t; j--)
                a[j + 1] = a[j];
            a[j + 1] = t;
        }
    }
}

void b_insert_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            int t = a[i];
            int l = 0, h = i - 1;
            while (l <= h)
            {
                int m = (l + h) / 2;
                if (a[m] < t)
                    l = m + 1;
                else
                    h = m - 1;
            }
            for (int j = i - 1; j >= l; j--)
                a[j + 1] = a[j];
            a[l] = t;
        }
    }
}

void shell_sort(int a[], int n)
{
    for (int d = n / 2; d >= 1; d /= 2)
    {
        for (int i = d; i < n; i++)
        {
            if (a[i] < a[i - d])
            {
                int t = a[i], j;
                for (j = i - d; j >= 0 && a[j] > t; j -= d)
                    a[j + d] = a[j];
                a[j + d] = t;
            }
        }
    }
}
#pragma endregion insert_sort

#pragma region swap_sort
void bubble_sort(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

void quick_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int t = a[l];
        int i = l, j = h;
        while (i < j)
        {
            while (i < j && a[j] > t)
                j--;
            a[i] = a[j];
            while (i < j && a[i] < t)
                i++;
            a[j] = a[i];
        }
        a[i] = t;
        quick_sort(a, l, i - 1);
        quick_sort(a, i + 1, h);
    }
}
#pragma endregion swap_sort

#pragma region merge_sort
void merge(int a[], int l, int m, int h, int *&b)
{
    for (int k = l; k <= h; k++)
        b[k] = a[k];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= h)
    {
        if (b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
        k++;
    }
    while (i <= m)
        a[k++] = b[i++];
    while (j <= h)
        a[k++] = b[j++];
}
void merge_sort(int a[], int l, int h)
{
    static int *b = new int[h - l + 1];
    if (l < h)
    {
        int m = (l + h) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, h);
        merge(a, l, m, h, b);
    }
}
#pragma endregion merge_sort

#pragma region heap_sort
void adjust_down(int a[], int n, int k)
{
    a[0] = a[k];
    for (int i = k * 2; i <= n; i *= 2)
    {
        if (i < n && a[i + 1] > a[i])
            i++;
        if (a[i] > a[k])
        {
            a[k] = a[i];
            a[i] = a[0];
            k = i;
        }
        else
            break;
    }
}
void adjust_up(int a[], int k)
{
    a[0] = a[k];
    for (int i = k / 2; i > 0; i /= 2)
    {
        if (a[k] > a[i])
        {
            a[k] = a[i];
            a[i] = a[0];
            k = i;
        }
    }
}
void build_heap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        adjust_down(a, n, i);
    // for (int i = 2; i <= n; i++)
    //     adjust_up(a, i);
}

void heap_sort(int a[], int n)
{
    int *b = new int[n + 1];
    for (int i = 0; i < n; i++)
        b[i + 1] = a[i];
    build_heap(b, n);
    for (int i = n; i >= 1; i--)
    {
        b[0] = b[1];
        b[1] = b[i];
        b[i] = b[0];
        adjust_down(b, i - 1, 1);
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i + 1];
}
#pragma endregion heap_sort

int main()
{
    int a[] = {312, 126, 272, 226, 28, 165, 123};
    int n = int(sizeof(a) / sizeof(a[0]));
    heap_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}