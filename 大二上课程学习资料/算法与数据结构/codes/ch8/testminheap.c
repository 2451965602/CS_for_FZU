/* ���Լ�С���� */ 

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "minheap.h"

int main()
{
   Heap H=MinHeapInit(6);
   HeapInsert(10,H);
   HeapInsert(20,H);
   HeapInsert(5,H);
   printf("����Ԫ��\n");
   HeapOut(H);
   HeapInsert(15,H);
   HeapInsert(30,H);
   printf("����Ԫ��\n");
   HeapOut(H);
   printf("��СԪ��%d\n",HeapMin(H));
   int x=DeleteMin(H);
   printf("ɾ����СԪ��%d\n",x);
   x=DeleteMin(H);
   printf("ɾ����СԪ��%d\n",x);
   printf("����Ԫ��\n");
   HeapOut(H);
   return 0;
}
