#include <stdio.h>
#include <string.h>

// next数组实质上就是找出模式串中前后字符重复出现的个数
// next数组的定义为：next[i]表示模式串A[0]至A[i-1]这个字串，使得前k个字符等于后k个字符的最大值
// 或者可以将next数组理解为将部分匹配值数组右移一位得到的数组
// 实际代码执行过程中子串并没有移动，而是直接将指针j退回到next[j]的位置实现相对移动
void get_next(char *p, int next[])
{
	// 第一个元素右移以后空缺的用-1来填充
	// 即第一个元素匹配失败时将子串第一个位置左边的元素对齐到当前主串匹配位置，
	// 也即将子串右移一位
	next[0] = -1;
	// j为当前子串的匹配位置，k可以看作是子串的字串的匹配位置
	int j = 0, k = next[0];
	// 这段处理流程和下面的的kmp()函数类似
	while (p[j] != '\0')
	{
		// 子串只有第一个元素的k==-1，即若第一个元素匹配失败，则将子串向右移动一位
		if (k == -1 || p[j] == p[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

// 当匹配失败时，指针i不变，指针j退回到next[j]的位置重新进行比较
int kmp(char *s, char *p, int next[])
{
	// i为当前主串的匹配位置，j为当前子串的匹配位置
	int i = 0, j = 0;
	while (s[i] != '\0' && p[j] != '\0')
	{
		// j==-1时说明子串第一个就不匹配，初始将主串位置右移1位，并同时将子串位置置为0
		// 即j==-1时，j++正好置为0，和s[i]==p[j]时的处理代码一致
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			// 子串右移，即将next[j]对齐到主串i位置
			j = next[j];
	}
	if (p[j] == '\0')
		return i - j;
	return -1;
}

int main()
{
	char *p = "ABAABAC";
	int n = strlen(p);
	int next[n];
	get_next(p, next);
	for (int i = 0; i < n; i++)
		printf("%d ", next[i]);
	char *s = "ABABAABAABAC";
	int pos = kmp(s, p, next);
	printf("\n%d\n", pos);
}