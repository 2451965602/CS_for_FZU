/* λ�������� */
/* 
ʹ��ʱǰ����� 
#include "set.h"
*/

#ifndef SET_CLASS
#define SET_CLASS

typedef struct bitset *Set;/* λ��������ָ������ */
typedef struct bitset{/* λ�������� */
    int setsize;/* ���ϴ�С */
    int arraysize;/* λ�����С */
    unsigned short *v;/* λ���� */
}Bitset;

int ArrayIndex(int x)
{/* ����4λ���x�������е�λ�� */
    return x>>4;
}

unsigned short BitMask(int x)
{/* ȷ��x����Ӧ���鵥Ԫ�е�׼ȷλ�� */
    return 1<<(x&15);
}

Set SetInit(int size)
{/* ����һ����λ����ʵ�ֵĿռ� */
   Set S=(Set)malloc(sizeof *S);
   S->setsize=size;
   /* �洢��СΪsetsize�ļ���������޷��Ŷ�����λ�� */
   S->arraysize=(size+15)>>4;
   S->v=(unsigned short *)malloc(size*sizeof(unsigned short));
   /* ��ʼ��Ϊ�ռ� */
   for(int i=0;i<size;i++)S->v[i]=0;
   return S;
}

void SetAssign(Set A,Set B)
{/* ���ϸ�ֵ���� */
    if(A->setsize!=B->setsize)return;
    for(int i=0;i<A->arraysize;i++)A->v[i]=B->v[i];
}

int SetMember(int x,Set S)
{/* ��Ա�����ж� */
    if(x<0 || x>=S->setsize)return 0;
    return S->v[ArrayIndex(x)]&BitMask(x);
}

int SetEqual(Set A,Set B)
{/* �ж�����A��B�Ƿ���� */
    if(A->setsize!=B->setsize)return 0;
    int retval=1;
    for(int i=0;i<A->arraysize;i++)
        if(A->v[i] != B->v[i]){
            retval=0;
            break;
        }
    return retval;
}

Set SetUnion (Set A,Set B)
{/* �������� */
    Set tmp=SetInit(A->setsize);
    for(int i=0;i<A->arraysize;i++)
        tmp->v[i]=A->v[i] | B->v[i];
    return tmp;
}

Set SetIntersection(Set A,Set B)
{/* �������� */
    Set tmp=SetInit(A->setsize);
    for(int i=0;i<A->arraysize;i++)
        tmp->v[i]=A->v[i] & B->v[i];
    return tmp;
}

Set SetDifference(Set A,Set B)
{/* ����� */
    Set tmp=SetInit(A->setsize);
    for(int i=0;i<A->arraysize;i++)
        tmp->v[i]= A->v[i]^(B->v[i] & A->v[i]);
    return tmp;
}

void SetInsert(int x,Set S)
{/* �������� */
    if(x<0 || x>=S->setsize)return;
    S->v[ArrayIndex(x)] |= BitMask(x);
}

void SetDelete(int x, Set S)
{/* ɾ������ */
    if(x<0 || x>=S->setsize)return;
    S->v[ArrayIndex(x)]&=~BitMask(x);
}

void SetOut(Set S)
{/* �������Ԫ�� */
    for(int i=0;i<S->setsize;i++)
      if(S->v[ArrayIndex(i)] & BitMask(i))printf(" %d ",i);
    printf("\n");
}

#endif
