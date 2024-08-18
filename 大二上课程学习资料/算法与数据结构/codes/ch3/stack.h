// ������ʵ��ջ
/* 
ʹ��ʱǰ����� 
#include "stackitem.h"
#include "stack.h"
*/

typedef struct astack *Stack;/* ջָ������ */
typedef struct astack{/* ջ�ṹ */
      int top,/* ջ�� */
          maxtop;/* ջ�ռ��Ͻ� */
      StackItem *data;/* �洢ջԪ�ص����� */
}Astack;

Stack StackInit(int size);
int StackEmpty(Stack S);
int StackFull(Stack S);
StackItem StackTop(Stack S);
void Push(StackItem x, Stack S);
StackItem Pop(Stack S);

Stack StackInit(int size)
{
   Stack S=(Stack)malloc(sizeof *S);
   S->data=(StackItem *)malloc(size*sizeof(StackItem));
   S->maxtop=size;
   S->top=-1;
   return S;
}

int StackEmpty(Stack S)
{
    return S->top < 0;
}

int StackFull(Stack S)
{
    return S->top>=S->maxtop;
}

StackItem StackTop(Stack S)
{/* ǰ�᣺ջ�ǿ� */
   if(StackEmpty(S))return 0;
   return S->data[S->top];
}

void Push(StackItem x, Stack S)
{/* ǰ�᣺ջδ�� */
    if(StackFull(S))return;
    S->data[++S->top]=x;
}

StackItem Pop(Stack S)
{/* ǰ�᣺ջ�ǿ� */
    if(StackEmpty(S))return 0;
    return S->data[S->top--];
}

void StackFree(Stack S)
{
    free(S->data);
    free(S);
}
