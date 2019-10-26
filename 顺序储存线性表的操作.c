#include<stdio.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;//将抽象数据类型表示为整型
typedef struct
{
	ElemType Data[MAXSIZE];//线性表最大储存容量
	int Length;//当前线性表长度
}SqList;//建立名为SqList的线性表

//数据操作
void getElemType(SqList L, int i, ElemType *e)//查询线性表指定位置的数据
{
	if (L.Length == 0)
	{
		printf("线性表为空");
		return;
	}
	if (L.Length == 0 || i<1 || i>L.Length)
	{
		printf("查询位置无效");
		return;
	}
	*e = L.Data[i-1];
	printf("第%d个数值为%d", i, *e);
	return;
}
void InsertElemType(SqList L, int i, ElemType *e)
{
	if (L.Length == MAXSIZE)
	{
		printf("线性表已满");
		return;
	}
	if (i<1 || i>L.Length)
	{
		printf("插入位置无效");
		return;
	}
	for (int j = L.Length; j > i - 1; j--)
	{
		L.Data[j] = L.Data[j - 1];
	}
	L.Data[i-1] = *e;
	L.Length++;
	printf("更新后的线性表为\n");
	for (int j = 0; j < L.Length; j++)
	{
		printf("%d ", L.Data[j]);
	}
	printf("\n");
}
void DeleteElemType(SqList L, int i, ElemType *e)
{
	if (L.Length == 0)
	{
		printf("线性表为空");
		return;
	}
	if (i<1 || i>L.Length)
	{
		printf("删除位置无效");
		return;
	}
	*e = L.Data[i - 1];
	for (int j = i-1; j < L.Length-1; j++)
	{
		L.Data[j] = L.Data[j+1];
	}
	L.Length--;
	printf("被删除的数据是%d\n",*e);
	printf("更新后的线性表为\n");
	for (int j = 0; j < L.Length; j++)
	{
		printf("%d ", L.Data[j]);
	}
	printf("\n");
}
void ChangeType(SqList L, int i, ElemType *e)
{
	if (i<1 || i>L.Length)
	{
		printf("修改位置无效");
		return;
	}
	L.Data[i - 1]=*e;
	printf("更新后的线性表为\n");
	for (int j = 0; j < L.Length; j++)
	{
		printf("%d ", L.Data[j]);
	}
	printf("\n");
}
void main()
{
	SqList La;
	for (int i = 0; i < 5; i++)
	{
		La.Data[i] =i+1;
	}
	La.Length = 5;
	int a=11;
	//int Operate_Result=getElemType(La,2,&a);
	//printf("The result is %d\nThe secone number is %d\n", Operate_Result, a);
	//InsertElemType(La, 2, &a);
	//DeleteElemType(La, 2, &a);
	ChangeType(La, 2, &a);
	system("pause");
}
