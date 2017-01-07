#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct Node
//结构体Node代表了	struct Node *Lchild;
//struct Node *Rchild;等结构体中的东西；
//
{
	DataType data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree;



void CreatBiTree(BiTree *bt)
{
	char ch;//例AB.DF..G..C.E.H..
	ch=getchar();//将输入字符赋值给ch
	if (ch=='.')//其中.代表了空子树
		*bt=NULL;//空子树
	else
	{
		*bt=(BiTree)malloc(sizeof(BiTree));//创建节点空间
		(*bt)->data=ch;//将输入字符赋值给*bt
		//扩展先序遍历：先左后右
		CreatBiTree(&((*bt)->Lchild));
	    CreatBiTree(&((*bt)->Rchild));
	}
}


void visit(char root)
{
	char a=(root);
	printf("%c",a);
}



void PreOrder(BiTree root)//先序遍历
{
	if (root !=NULL)//对于非空树，先访问根，左孩子，右孩子；
	{
		visit(root->data);
			PreOrder(root->Lchild);
			PreOrder(root->Rchild);

	}
}
void InOrder(BiTree root)//中序遍历
{
	if (root!=NULL)//对于非空树，先访问左孩子，根节点，右孩子
	{
		InOrder(root->Lchild);
			visit(root->data);
			InOrder(root->Rchild);
	}
}
void PostOrder (BiTree root)//后序遍历
{
	if ( root!=NULL)//对于非空树，先访问左孩子，右孩子，根节点
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