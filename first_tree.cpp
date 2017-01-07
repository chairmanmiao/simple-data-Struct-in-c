#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct Node
//�ṹ��Node������	struct Node *Lchild;
//struct Node *Rchild;�Ƚṹ���еĶ�����
//
{
	DataType data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree;



void CreatBiTree(BiTree *bt)
{
	char ch;//��AB.DF..G..C.E.H..
	ch=getchar();//�������ַ���ֵ��ch
	if (ch=='.')//����.�����˿�����
		*bt=NULL;//������
	else
	{
		*bt=(BiTree)malloc(sizeof(BiTree));//�����ڵ�ռ�
		(*bt)->data=ch;//�������ַ���ֵ��*bt
		//��չ����������������
		CreatBiTree(&((*bt)->Lchild));
	    CreatBiTree(&((*bt)->Rchild));
	}
}


void visit(char root)
{
	char a=(root);
	printf("%c",a);
}



void PreOrder(BiTree root)//�������
{
	if (root !=NULL)//���ڷǿ������ȷ��ʸ������ӣ��Һ��ӣ�
	{
		visit(root->data);
			PreOrder(root->Lchild);
			PreOrder(root->Rchild);

	}
}
void InOrder(BiTree root)//�������
{
	if (root!=NULL)//���ڷǿ������ȷ������ӣ����ڵ㣬�Һ���
	{
		InOrder(root->Lchild);
			visit(root->data);
			InOrder(root->Rchild);
	}
}
void PostOrder (BiTree root)//�������
{
	if ( root!=NULL)//���ڷǿ������ȷ������ӣ��Һ��ӣ����ڵ�
	{
		PostOrder(root->Lchild);
			PostOrder(root->Rchild);
			visit(root->data);
	}
}
void main()
{
	BiTree s;

	BiTree *L=&s;
	CreatBiTree(L);
	PreOrder(*L);
	printf("\n");
	InOrder(*L);
	printf("\n");
	PostOrder(*L);
	printf("\n");


		
}

/*char * preSeq="***";
int index=0;


{
	char ch;
	char= preSeq[index];
	index ++;

}*/