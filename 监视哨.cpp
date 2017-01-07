#include <stdio.h>
#define List_Size 20
typedef int KeyType;
typedef struct
{
	KeyType key;//搜索目标
	//OtherType other_data;

}RecordType;
typedef struct
{
	RecordType e[List_Size];
	int Length;//表的长度
}RecordList;


int SeqSearch(RecordList r,KeyType k)
{
	r.e[0].key=k;//设置监视哨
	int i=r.Length;//设置临时变量i，把i放在队尾
	while(r.e[i].key!=k)//当表中元素与目标不匹配 i向前走一个位置
		i--;
	return (i);//最后返回i的位置
}

/*int BinSearch(RecordList r,KeyType k)
{
	int low=r.e[0];
	int high = r.e[20];
		while(low<high)
		{
			int mid = (low+high)/2;
			if(k==r.e[mid].key)
			{
				return (mid);
			}
			else if(k<r.e[mid].key)
			{
				high=mid-1;
			}
			else
				low=mid+1;
		}
		return 0;

}*/
int main()
{
	RecordList r= {{1,2,3,4,5,6,7,8,9,10,44,55,66,77,88,99,222,1111},20};
	int temp = SeqSearch(r,55);
	printf("%c监视哨查找元素的位置是：");
	printf("%d\n",temp);
	return 0;
}
