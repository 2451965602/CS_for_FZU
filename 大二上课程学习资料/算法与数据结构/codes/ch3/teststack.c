// ����ջ 

#include <stdio.h>
#include <stdlib.h>
#include "stackitem.h"
#include "stack.h"
//#include "lstack.h"

int main()
{
   Stack ss,tt;
   ss=StackInit(10);
   tt=StackInit(10);
   //ss=StackInit();
   //tt=StackInit();

   Push(1,ss);
   Push(2,ss);
   Push(3,ss);

   Push(4,tt);
   Push(5,tt);
   Push(6,tt);

   if(!StackEmpty(ss))printf("ss��ջ��Ԫ��  %d \n", StackTop(ss));
   if(!StackEmpty(tt))printf("tt��ջ��Ԫ��  %d \n", StackTop(tt));

   if(!StackEmpty(ss))printf("ɾ��  %d \n", Pop(ss));
   if(!StackEmpty(ss))printf("ɾ��  %d \n", Pop(ss));
   if(!StackEmpty(ss))printf("ɾ��  %d \n", Pop(ss));

   if(!StackEmpty(tt))printf("ɾ��  %d \n", Pop(tt));
   if(!StackEmpty(tt))printf("ɾ��  %d \n", Pop(tt));
   if(!StackEmpty(tt))printf("ɾ��  %d \n", Pop(tt));
   if(!StackEmpty(tt))printf("ɾ��  %d \n", Pop(ss));
   StackFree(ss);StackFree(tt); 
   return 0;
}
