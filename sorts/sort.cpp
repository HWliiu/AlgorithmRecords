#include <stdio.h>

void insert_sort(int a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
        {
            a[0] = a[i];
            int j;
            for (j = i - 1; a[0] < a[j]; a[j + 1] = a[j], j--);
            a[j + 1] = a[0];
        }
    }
}

void b_insert_sort(int a[], int n)
{
    int m, l, r;
    for (int i = 2; i <= n; i++)
    {
        l = 1;
        r = i - 1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (a[m] < a[i]) l = m + 1;
            else r = m - 1;
        }
        a[0] = a[i];
        for (int j = i - 1; j >= l; a[j + 1] = a[j], j--);
        a[l] = a[0];
    }
}

void shell_sort(int a[], int n)
{
    for (int d = n / 2; d >= 1; d /= 2)
    {
        for (int i = d + 1; i <= n; i++)
        {
            if (a[i] < a[i - d])
            {
                a[0] = a[i];
                int j;
                for (j = i - d; j > 0 && a[0] < a[j]; a[j + d] = a[j], j -= d);
                a[j + d] = a[0];
            }
        }
    }
}

void bubble_sort(int a[], int n)
{
    for (int i = n; i > 1; i--)
    {
        bool flag = false;
        for (int j = 1; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                a[0] = a[j];
                a[j] = a[j + 1];
                a[j + 1] = a[0];
                flag = true;
            }
        }
        if (!flag) return;
    }
}

void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        a[0] = a[i];
        while (i < j)
        {
            while (i < j && a[j] > a[0]) j--;
            a[i] = a[j];
            while (i < j && a[i] < a[0]) i++;
            a[j] = a[i];
        }
        a[i] = a[0];
        quick_sort(a, l, i - 1);
        quick_sort(a, i + 1, r);
    }
}

void select_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int m = i;
        for (int j = i + 1; j <= n; j++)
            if (a[j] < a[m]) m = j;
        if (i != m)
        {
            a[0] = a[i];
            a[i] = a[m];
            a[m] = a[0];
        }
    }
}

void adjust_down(int a[], int n, int k)
{
    a[0] = a[k];
    for (int i = k * 2; i <= n; i *= 2)
    {
        if (i < n && a[i] < a[i + 1]) i++;
        if (a[0] < a[i])
        {
            a[k] = a[i];
            k = i;
        }
        else
            break;
    }
    a[k] = a[0];
}
void adjust_up(int a[], int k)
{
    a[0] = a[k];
    int i;
    for (i = k / 2; i > 0 && a[0] > a[i]; a[k] = a[i], k = i, i /= 2);
    a[k] = a[0];
}
void build_heap(int a[], int n)
{
    for (int i = n / 2; i > 0; i--)
        adjust_down(a, n, i);
    // for(int i=2;i<=n;i++)
    // adjust_up(a,i);
}
void heap_sort(int a[], int n)
{
    build_heap(a, n);
    for (int i = n; i > 1; i--)
    {
        a[0] = a[i];
        a[i] = a[1];
        a[1] = a[0];
        adjust_down(a, i - 1, 1);
    }
}

void merge(int a[], int l, int m, int r)
{
    static int *b = new int[r - l + 1];
    int i, j, k;
    for (k = l; k <= r; b[k] = a[k], k++);
    for (i = l, j = m + 1, k = l; i <= m && j <= r; k++)
    {
        if (a[i] < a[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while (i <= m) a[k++] = b[i++];
    while (j <= r) a[k++] = b[j++];
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    // a[0]是哨兵位
    int a[] = {0, 312, 126, 272, 226, 28, 165, 123};
    merge_sort(a, 1, 7);
    for (int i = 1; i <= 7; printf("%d ", a[i]), i++);
}
