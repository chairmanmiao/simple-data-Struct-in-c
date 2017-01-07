#include<stdio.h>
#define Stack_Size 50
#define TRUE 1
#define FALSE 0
#include <stdlib.h>

typedef char StackElementType;
typedef struct
{
	StackElementType elem[Stack_Size];
	int top;


}SeqStack;

void InitStack(SeqStack *S)
{
	S->top = -1;
}

int Push(SeqStack *S, StackElementType x)//?? 
{
	if (S->top == Stack_Size - 1)//??? 
		return 0;
	else
		S->top++;
	S->elem[S->top] = x;
	return 1;

}
int Pop(SeqStack *S, StackElementType *x)//?? 
{
	if (S->top == -1)
		return 0;
	else
		*x = S->elem[S->top];
	S->top--;
	return 1;
}
int GetTop(SeqStack *S, StackElementType *x)
{
	if (S->top == -1)
		return 0;
	else
		*x = S->elem[S->top];
	return  1;

}
int IsEmpty(SeqStack *S)
{
	return S->top == -1;
}
int IsMatch(char left, char right)
{
	if ( left == '('&& right == ')')
		return 1;
	else
		if ( left == '['&& right == ']')
			return 1;
		else
			if ( left == '{'&& right == '}')
				return 1;
			else
				return 0;
}
void BracketMatch(char *str)
{
	SeqStack S; int temp; char ch;

	InitStack(&S);
	for (int temp = 0; str[temp]; temp++)
	{
		switch (str[temp])
		{
		case'(':
		case'[':
		case'{':
			break;

			Push(&S, str[temp]);
			break;
		case')':
		case']':
		case'}':
			if (IsEmpty(&S))
			{
				printf("\n 有多余");
					return;

			}
			else
			{
				GetTop(&S, &ch);
				if (IsMatch(ch, str[temp]))
					Pop(&S, &ch);
				else
				{
					printf("\n 左右不同");
					return;

				}


			}
		}




	}


}





int main()
{
	char * bracket = "{{{}";
	BracketMatch(bracket);
	return 0;
}
/*  int IsMatch(char a, char b)
{
char a;
char b;
if (a=='('&&b==')')
return 1;
else
return 0;
if (a=='['&&b==']')
return 1;
else
return 0;
if (a=='{'&&b=='}')
return 1;
else
return 0;

}*/


