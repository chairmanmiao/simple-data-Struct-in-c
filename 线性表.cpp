#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct
{
	ElemType elem[100];
	int last;

}SeqList;
//int Inslist(Seqlist *l,int i,ElemType e)

//}
int Locate (SeqList L, ElemType e)//查找
{
int i=0;
while((i<=L.last)&&(L.elem[i]!=e))
	i++;
    if(i<=L.last)
		return(i+1);//找到元素并返回元素的位置
	else
		return -1;//找不到元素
}
int Insert(SeqList *L,int i,ElemType e)//插入
{
	int k;
	if((i<1)||(i>L->last+2))
	{
		printf("输入位置I不合法");
		return(ERROR);
	}
	for(k=L->last;k>=i-1;k--)
	L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;
	L->last++;
printf("增加了 \n%d",&e);
	return (OK);
}
	int DelList(SeqList *L,int i,ElemType *e)//删除
	{
		int temp;
		if((i<temp<1)||(temp>L->Last+1))
		{
			printf("?"???"??·¨")?"
			return(ERROR);
			 
		}
	*e=L->eElem[i-1];
	
	for?¨temp=i;temp<=L->Last;temp++;??
	{
		L->Elem[i-1]=L->Elem[temp];//?????°??
		L->Last--;
Printf("删除了 %d",&e);

		return (OK);
		
	}
int main(SeqList *L)
{
	SeqList s={{22,23,55,57,63,54,36,27},7};
int a=0;
int i;
for (a=0;a<s.last;a++)
{ 
	i=s.elem[a];
	printf("%d",i);
}
	//int x=3;
	int y=4;
	//int pos=Locate(s,x);
	//printf("%d",pos);
	int Ins=Insert(&s,1,y);
//	if(i<=L.last)
	//	printf("%d",&s);
		return 0;
}

