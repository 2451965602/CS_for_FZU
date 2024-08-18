// ���Զ���
 
#include <stdio.h>
#include <stdlib.h>
#include "qitem.h"
//#include "lqueue.h"
#include "queue.h"

int main()
{
   Queue pp,qq;
   pp=QueueInit(10);
   qq=QueueInit(10);
   //pp=QueueInit();
   //qq=QueueInit();

   printf("pp �ն��� %d \n", QueueEmpty(pp));
   printf("qq �ն��� %d \n", QueueEmpty(qq));

   //printf("pp ������  %d \n", QueueFull(pp));
   //printf("qq ������  %d \n", QueueFull(qq));

   EnterQueue(1,pp);
   EnterQueue(2,pp);
   EnterQueue(3,pp);
   EnterQueue(4,pp);
   EnterQueue(5,pp);

   EnterQueue(10,qq);
   EnterQueue(9,qq);
   EnterQueue(8,qq);
   EnterQueue(7,qq);
   EnterQueue(6,qq);

   if(!QueueEmpty(pp)) printf("pp ����Ԫ��  %d \n", QueueFirst(pp));
   if(!QueueEmpty(qq)) printf("qq ����Ԫ��  %d \n", QueueFirst(qq));

   if(!QueueEmpty(pp))printf("pp ��βԪ��  %d \n", QueueLast(pp));
   printf("qq ��βԪ��  %d \n", QueueLast(qq));

   printf("pp �ն��� %d \n", QueueEmpty(pp));
   printf("qq �ն��� %d \n", QueueEmpty(qq));

   if(!QueueEmpty(pp))printf("ɾ��  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("ɾ��  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("ɾ��  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("ɾ��  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("ɾ��  %d \n", DeleteQueue(pp));

   if(!QueueEmpty(qq))printf("ɾ��  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("ɾ��  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("ɾ��  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("ɾ��  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("ɾ��  %d \n", DeleteQueue(qq));

   if(!QueueEmpty(pp))printf("ɾ��  %d \n", DeleteQueue(pp));
   QueueFree(pp);QueueFree(qq);
   return 0;

}
