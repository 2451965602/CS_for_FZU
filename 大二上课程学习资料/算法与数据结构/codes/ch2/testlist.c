// ���Ա� 
#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
//#include "llist.h"
//#include "chain.h"
//#include "indlist.h"
//#include "schain.h"
//#include "cchain.h"
#include "cdouble.h"

int main()
{
   //List l=ListInit(10);
   List l=ListInit();
   printf("��=%d \n", ListLength(l));
   printf("�ձ�=%d \n", ListEmpty(l));
   ListInsert(0,2,l);
   ListInsert(1,6,l);
   ListInsert(1,8,l);
   ListInsert(0,9,l);
   PrintList(l);
   printf("�ձ�=%d \n", ListEmpty(l));
   printf("Ԫ��6λ��%d \n", ListLocate(6,l));
   printf("��Ԫ��Ϊ%d \n", ListRetrieve(1,l));
   printf("�ڶ���Ԫ����%d \n", ListRetrieve(2,l));
   printf("������Ԫ����%d \n", ListRetrieve(3,l));
   printf("��=%d \n", ListLength(l));
   printf("��ɾ��Ԫ��%d \n", ListDelete(2,l));
   int len=ListLength(l);
   printf("��=%d \n", len);
   PrintList(l);
   printf("ɾ����βԪ��%d \n", ListDelete(len,l));
   PrintList(l);
   printf("����Ԫ��Ϊ%d \n", ListRetrieve(1,l));
   printf("��βԪ��Ϊ%d \n", ListRetrieve(ListLength(l),l));
   printf("���ײ���Ԫ�� 10\n");
   ListInsert(0,10,l);
   PrintList(l);
   printf("��β����Ԫ�� 15\n");
   ListInsert(ListLength(l),15,l);
   PrintList(l);
   ListFree(l);
   return 0;
}
