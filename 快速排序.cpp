#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100
typedef int KeyType;
typedef int RecordType;

int t = 100; 

int QKPass(RecordType a[],int low,int high)
{
	RecordType x;
    
	x=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=x)
			high--;
		if(low<high)
		{
			a[low]=a[high];
			low++;
		}
		while (low<high&&a[low]<x)
			low++;
		if(low<high)
		{
			a[high]=a[low];
			high--;
		}
	}
	a[low]=x;
	return low;
}
void QKSort(RecordType a[],int low,int high)
{
	if(low<high)
	{
		int pos;
		pos=QKPass(a,low,high);
		QKSort(a,low,pos-1);
		QKSort(a,pos+1,high);

	}
}
void BubbleSort(RecordType a[],int t)
{
	for(int i=1;i<=max-1;++i)
	{
		for(int j=1;j<=i;++j)
		{
			if( a[j]>a[j+1])
				{
					int x = a[j];
					a[j]=a[j+1];
					a[j+1]=x;
				}			
		}
	}
 } 
int main()

{
	int a[max+1];

for (int i=1;i<=max;i++)
{
	a[i]=rand();
	printf("%d",a[i]);
	printf(",");
	 
	//fprintf(fp,"%d",a[i]);
}
//int t= time(NULL);

//QKSort(a,1,99999);
BubbleSort(a,max); 
//int t2 = time(NULL);
//printf("%d",(t2-t));
int temp;
for(temp=1;temp<=max;temp++)
{
	//a[i]=rand();
	printf("%d",a[temp]);
	printf(".");
}
return 0;
}
