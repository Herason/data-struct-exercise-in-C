#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node Node;
typedef Node *LinkList;//LinkList是结构体指针，指向一个结点；
//链表基本操作
//1，初始化链表
LinkList initialize()//为头结点申请一个结点的空间，并初始化指针域为空,返回链表的头结点指针；
{
	LinkList L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}
//2,检查链表是否为空
int isEmpty(LinkList L)
{
	if (L->next == NULL) return 1;
	return 0;
}
//3，查询表的长度
int length(LinkList L)
{
	int count=0;
	Node *p;
	p = L->next;//将p指向第一个结点
	while (p!=NULL)
	{
		count++;//先确定p后面有结点，加一
		p = p->next;//再将p指向后一个结点，再判断后一个结点的指针域之前已经将后一个结点计数了
	}
	return count;
}
//4,查询某一个结点的值
int GetElem(LinkList L, int i,ElemType *e)//读取第i个数据
{
	if (i > length(L))
	{
		printf("超出链表长度");
		return 0;
	}
	Node *p = L->next;//将p指向第一个结点
	int j = 1;
	while (p && (j < i))
	{
		p = p->next;
		j++;//用变量j来记录当前结点指针p指向的第几个结点
	}
	if (p == NULL || j>i)
	{
		return 0;
	}
	*e = p->data;
	return 1;
}
//5,查找某个元素在链表中的序号
int find(LinkList L, ElemType e)
{
	Node *p = L->next;
	int j = 1;
	while (p)
	{
		if (p->data == e) return j; 
		p = p->next;
		j++;
	}

	return -1;
}
//6插入结点
int insertElem(LinkList L, int i,ElemType e)
{
	LinkList p=L;
	int j = 1;

	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));//为新结点申请空间并初始化
	tmp->data = e;
	tmp->next = NULL;

	while (p&&(j < i))//将p指向第I个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		return 0;
	}
	tmp->next = p->next;
	p->next = tmp;
	return 1;

}
//7，删除一个结点
//若第i个结点存在，删除并将其值放入e所指向的空间，返回1；失败返回0
int delete(LinkList L, int i, ElemType *e)
{
	Node *p = L;
	int j = 1;
	while (p&&(j<i))
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		return 0;
	}
	*e = p->next->data;
	Node *tmp = p->next;
	p->next = p->next->next;
	free(tmp);
	return 1;
}
//8，遍历并打印整个链表；
void print(LinkList L)
{
	Node *p = L->next;
	if (isEmpty(L) == 1)
	{ 
		return; 
	}
	printf("链表为：");
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
//9,清空链表
int clear(LinkList L)
{
	Node *p;
	while (L->next != NULL)
	{
		p = L->next;
		L->next = L->next->next;
		free(p);
	}
	return 1;
}
void main()
{
	int order = 1,result,i;
	ElemType e;
	LinkList L =initialize();
	while (1)
	{
		printf("请输入指令：\n 1，查询是否为空\n 2，插入一个结点\n 3，查询链表长度\n 4，查询结点的值\n 5，删除结点\n 6，打印整个链表\n 7，清空链表\n");
		scanf("%d",&order);
		switch (order)
		{
		case 1: 
			if (isEmpty(L) == 0)
			{
				printf("链表不为空\n");
				break;
			}
			else
			{
				printf("链表为空\n");
				break;
			}
		case 2:
			printf("输入插入位置和插入值\n");
			scanf("%d", &i);
			scanf("%d", &e);
			result = insertElem(L,i,e);
			if (result == 1)
			{
				printf("插入结点成功\n");
				break;
			}
			else
			{
				printf("插入结点失败\n");
				break;
			}
		case 3:
			printf("链表的长度为：%d\n",length(L));
			break;
		case 4:
			printf("输入要查询的结点位置\n");
			scanf("%d", &i);
			printf("查询操作结果：%d", GetElem(L, i, &e));
			printf("该结点的值为：%d\n", e);
			break;
		case 5:
			printf("输入要删除的结点位置\n");
			scanf("%d", &i);
			printf("删除操作的结果为：%d\n", delete(L, i,&e));
			printf("被删除的值为：%d\n", e);
			break;
		case 6:
			print(L);
			break;
		case 7:
			clear(L);
			break;
		}
		system("pause");
	}
	return;
}
