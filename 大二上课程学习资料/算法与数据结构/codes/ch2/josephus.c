// Josephus��������

#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
#include "cdouble.h"

void Josephus(int n,int m)
{
   List l=ListInit();/* ����һ���ձ� */
   for(int i=1;i<=n;i++) ListInsert(i-1,i,l);/* ���е�i��Ԫ��Ϊi */
   IterInit(l);/* ��ʼ�������α� */
   for(int i=1;i<n;i++){
     for(int j=1;j<m;j++)IterNext(l);/* �����α����� */
     ListItem x=DeleteCurr(l);/* ɾ����m��Ԫ�� */
     printf("ɾ�������� %d \n", x);/* �����ɾ��Ԫ�� */
   }
   printf("������ %d  ʤ�� \n", *CurrItem(l));
}

int main()
{
   int n,m;
   n=8;m=5;
   Josephus(n,m);
   return 0;
}
