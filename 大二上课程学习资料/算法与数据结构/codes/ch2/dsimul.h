// ˫�ռ�ģ��ṹ����
#include "snode.h"

typedef struct dspace *Space;/* ˫ģ��ռ�ָ������ */
typedef struct dspace{/* ˫ģ��ռ�ṹ���� */
   int num,/* ��������ռ��С */
   first1, /* ��һ�������鵥Ԫ�±� */
   first2;/* �ڶ��������鵥Ԫ�±� */
   link node;/* ���ÿռ����� */
}Dspace;

Space SpaceInit(int max);
int SpaceAllocate(Space s);
void SpaceDeallocate(int i,Space s);

Space SpaceInit(int max)
{
   Space s=(Space)malloc(sizeof *s);
   s->num=max;
   s->node=(link)malloc(max*(sizeof *s->node));
   s->first1=0;
   s->first2=-1;
   return s;
}

int SpaceAllocate(Space s)
{
   if(s->first2==-1)return s->first1++;
   int i=s->first2;
   s->first2=s->node[i].next;
   return i;
}

void SpaceDeallocate(int i,Space s)
{
   s->node[i].next=s->first2;
   s->first2=i;
}

