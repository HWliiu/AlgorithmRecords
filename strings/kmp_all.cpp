#include <stdio.h>
#include <string.h>

void get_next(char *p, int next[])
{
	next[0] = -1;
	int j = 0, k = next[0];
	while (p[j] != '\0')
	{
		if (k == -1 || p[j] == p[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

int kmp(char *s, char *p, int next[])
{
	int i = 0, j = 0, count = 0;
	int slen = strlen(s), plen = strlen(p);
	while (i < slen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
		if (j >= plen)
		{
			printf("%d\n", i - j);
			count++;
			i = i - j + 1;
			j = 0;
		}
	}
	return count;
}

int main()
{
	char *p = "abab";
	int next[11];
	get_next(p, next);
	// for (int i = 0; i < 11; printf("%d ", next[i]), i++)
	// 	;
	char *s = "ababababaabbabababaababbabaabbbab";
	int count = kmp(s, p, next);
	printf("%d\n", count);
}