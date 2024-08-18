// ������ʵ�ֱ�
/* 
ʹ��ʱǰ����� 
#include "listitem.h"
#include "llist.h"
*/

typedef struct alist *List;/* ������ָ������ */
typedef struct alist{
      int n, /* �� */
          curr;/* ��ǰλ�� */
      int maxsize;/* �����Ͻ� */
      ListItem *table;/* �洢��Ԫ�ص����� */ 
}Alist;

List ListInit(int size);                  /* ��ṹ��ʼ�� */
int ListEmpty(List L);                    /* ���Ա�L�Ƿ�Ϊ�� */
int ListLength(List L);                   /* ��L�ĳ��� */
ListItem ListRetrieve(int k,List L);      /* ���ر�L��λ��k����Ԫ�� */
int ListLocate(ListItem x,List L);        /* Ԫ��x�ڱ�L�е�λ�� */
void ListInsert(int k,ListItem x,List L); /* �ڱ�L��λ��k֮�����Ԫ��x */
ListItem ListDelete(int k,List L);        /* �ӱ�L��ɾ��λ��k����Ԫ�� */
void PrintList(List L);                   /* ��λ�ô��������L��Ԫ�� */

List ListInit(int size)
{
   List L=(List)malloc(sizeof *L);
   L->table=(ListItem *)malloc(size*sizeof(ListItem));
   L->maxsize=size;
   L->n=0;
   return L;
}

void ListFree(List L)
{
    free(L->table);
    free(L);
}

int ListEmpty(List L)
{
   return L->n==0;
}

int ListLength(List L)
{
   return L->n;
}

ListItem ListRetrieve(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* Խ�� */
   return L->table[k-1];
}

int ListLocate(ListItem x,List L)
{
   for(int i=0;i<L->n;i++)
     if(L->table[i]==x)return ++i;
   return 0;
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0 || k>L->n)return;/* Խ�� */
   for(int i=L->n-1;i>=k;i--)L->table[i+1]=L->table[i];
   L->table[k]=x;
   L->n++;
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* Խ�� */
   ListItem x=L->table[k-1];
   for(int i=k;i<L->n;i++)L->table[i-1]=L->table[i];
   L->n--;
   return x;
}

void PrintList(List L)
{
   for(int i=0;i<L->n;i++)ItemShow(L->table[i]);
}

void IterInit(List L)
{
   L->curr=0;
}

void IterNext(List L)
{
   L->curr=(L->curr+1)%L->n;
}

ListItem *CurrItem(List L)
{
   return &L->table[L->curr];
}

void InsertCurr(ListItem x,List L)
{
   ListInsert(L->curr,x,L);
}

ListItem DeleteCurr(List L)
{
   ListItem x=ListDelete(L->curr+1,L);
   L->curr=L->curr%L->n;
   return x;
}


