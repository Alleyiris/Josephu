#include<stdio.h>

void delnode(int*, int, int);

int main()
{
	//初始化数组
	int m;
	printf("m=");
	scanf("%d",&m);
	int i = 0;//下标0表示第一个位置
	int a[50] = { 0 };
	for (i = 0; i < m; ++i)
		a[i] = 1;

	//删除元素
	int n;
	printf("n=");
	scanf("%d",&n);
	delnode(a, m, n);

	return 0;
}

void delnode(int* a, int m, int n)
{
	if (n <= 0)
	{
		printf("error\n");
		return;
	}
	int total = 0;
	int i = -1;
	int j = 0;
	int temp;
	while (total < m)
	{
		for (j = 0; j < n; ++j)
		{
			i = (i + 1) % m;

			while(!a[i])
				i = (i + 1) % m;
		}
		if (a[i])
		{
			temp = i + 1;
			printf("%d ",temp);
			a[i] = 0;
			++total;
		}
	}
	return;
}