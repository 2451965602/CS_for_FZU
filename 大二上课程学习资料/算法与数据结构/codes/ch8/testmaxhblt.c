/* ���Լ�����ƫ�� */ 

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "maxhblt.h"

int main()
{
   int w,x,y,z;
   int a[6]={0,7,9,1,8,11};
   int b[5]={0,2,6,4,9};
   MaxHBLT H, J;

   H=BuildHBLT(a,5);
   //printf("��ƫ��\n");
   HBLTOut(H->root);
   printf("\n");

   J=BuildHBLT(b,4);
   //printf("��ƫ��\n");
   HBLTOut(J->root);
   printf("\n");

   HBLTConc(H,J);
   //printf("�ϲ���ƫ��\n");
   HBLTOut(H->root);
   printf("\n");

   w=DeleteMax(H);
   x=DeleteMax(H);
   y=DeleteMax(H);
   z=DeleteMax(H);

   //printf("4��ɾ�����Ԫ\n");
   HBLTOut(H->root);
   printf("\n");

   //printf("ɾ�������Ԫ��\n");
   printf("%d %d %d %d\n",w,x,y,z);

   HBLTInsert(10,H);
   HBLTInsert(20,H);
   HBLTInsert(5,H);

   //printf("��ƫ��\n");
   HBLTOut(H->root);
   printf("\n");

   HBLTInsert(15,H);
   HBLTInsert(30,H);
   HBLTInsert(2,H);

   //printf("��ƫ��\n");
   HBLTOut(H->root);
   printf("\n");

   //printf("���Ԫ %d\n",HBLTMax(H));

   x=DeleteMax(H);
   //printf("ɾ�����Ԫ�� %d\n",x);

   //printf("��ƫ��\n");
   HBLTOut(H->root);
   printf("\n");

   x=DeleteMax(H);
   //printf("ɾ�����Ԫ�� %d\n",x);

   //printf("��ƫ��\n");
   HBLTOut(H->root);
   printf("\n");

   while(!HBLTEmpty(H))x=DeleteMax(H);
   return 0;
}
