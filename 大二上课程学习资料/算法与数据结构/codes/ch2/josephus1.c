// Josephus��������

#include <stdio.h>
#include <stdlib.h>

void Josephus(int n,int m)
{
   int * next=(int *)malloc(n*sizeof(int));
   for(int i=0;i<n-1;i++)next[i]=i+1; /* ��i��Ԫ�ص���һԪ��Ϊi+1 */
   int k=n-1;next[k]=0; /*  kΪ�����α� */
   for(int i=1;i<n;i++){
     for(int j=1;j<m;j++)k=next[k]; /* ѭ������ */
     printf("ɾ�������� %d \n",next[k]+1);/* �����m��Ԫ�� */
     next[k]=next[next[k]];/* ɾ����m��Ԫ�� */
   }
   printf("������ %d  ʤ�� \n", next[k]+1);
}

int main()
{
   int n,m;
   n=8;m=5;
   Josephus(n,m);
   return 0;
}
