#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct monkey
{
	int num;
	struct monkey* next;
};
struct monkey* creat_list(int);
void delnode(int, int, struct monkey*);


int main()
{
	//创建链表
	int m;
	printf("m=");
	scanf("%d", &m);
	struct monkey* ptail = creat_list(m);
	//删除结点
	int n;
	printf("n=");
	scanf("%d", &n);
	delnode(m, n, ptail);

	return 0;
}

struct monkey* creat_list(int m)
{
	int i = 0;
	struct monkey* phead = (struct monkey*)malloc(sizeof(struct monkey));
	if (phead == NULL)
	{
		printf("分配结点失败！\n");
		exit(-1);
	}
	phead->next = NULL;
	struct monkey* ptail = phead;
	for (i = 1; i <= m; ++i)
	{
		struct monkey* pnew = (struct monkey*)malloc(sizeof(struct monkey));
		if (pnew == NULL)
		{
			printf("分配结点失败！\n");
			exit(-1);
		}
		pnew->num = i;
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
	}
	ptail->next = phead->next;
	return (ptail);//返回的是最后一个结点
}

void delnode(int m, int n, struct monkey* ptail)
{
	if (n <= 0)
	{
		printf("error\n");
		return;
	}
	int i = 1;
	int total = 0;//已删除个数
	struct monkey* ptemp = (struct monkey*)malloc(sizeof(struct monkey));
	while (total != m)
	{
		for (i = 1; i <= n; ++i)
		{
			ptemp = ptail;
			ptail = ptail->next;
		}
		printf("%d ", ptail->num);
		ptemp->next = ptail->next;
		++total;
	}
	return;
}
