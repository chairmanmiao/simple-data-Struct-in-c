#include <stdio.h>
#define List_Size 20
typedef int KeyType;
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
int BinSearch(RecordList r,KeyType k)
{
	int low=0;
	int high = r.Length;
		while(low<=high)
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

}
int main()
{
	RecordList r= {{1,2,3,4,5,6,7,8,9,10,55,66,44,77,88,99,111,777,33333},20};
	int temp = BinSearch(r,777);
	printf("%c�����ڲ���Ԫ�ص�λ���ǣ�");
	printf("%d\n",temp+1);//������Ǵ�0 ��ʼ���� ����Ҫ��1
	return 0;
}
