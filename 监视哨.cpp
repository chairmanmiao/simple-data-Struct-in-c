#include <stdio.h>
#define List_Size 20
typedef int KeyType;
typedef struct
{
	KeyType key;//����Ŀ��
	//OtherType other_data;

}RecordType;
typedef struct
{
	RecordType e[List_Size];
	int Length;//��ĳ���
}RecordList;


int SeqSearch(RecordList r,KeyType k)
{
	r.e[0].key=k;//���ü�����
	int i=r.Length;//������ʱ����i����i���ڶ�β
	while(r.e[i].key!=k)//������Ԫ����Ŀ�겻ƥ�� i��ǰ��һ��λ��
		i--;
	return (i);//��󷵻�i��λ��
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
	printf("%c�����ڲ���Ԫ�ص�λ���ǣ�");
	printf("%d\n",temp);
	return 0;
}
