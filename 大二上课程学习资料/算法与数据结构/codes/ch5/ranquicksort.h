// ������������㷨
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "ranquicksort.h"
*/

int randomi(int l,int r)
{/* ���ѡȡ���ֻ�׼ */
    return l+(r-l)*(1.0*rand()/RAND_MAX);
}

int partition(Item a[],int l,int r)
{/* Ԫ�ػ����㷨 */
   int i=l-1,j=r;Item v=a[r];
   /* �����ڵ���v��Ԫ�ؽ������ұ����� */
   /* ��С�ڵ���v��Ԫ�ؽ������������ */
   for(;;){
      while(less(a[++i],v));
      while(less(v,a[--j]))if(j==l)break;
      if(i>=j)break;
      swap(a[i],a[j]);
   }
   swap(a[i],a[r]);
   return i;
}

int randompartition(Item a[],int l,int r)
{/* ����������㷨 */
    int i=randomi(l,r);
    swap(a[i],a[l]);
    return partition(a,l,r);
}

void sort(Item a[],int l,int r)
{/* ������������㷨 */
    if(r<=l)return;
    int i=randompartition(a,l,r);
    sort(a,l,i-1); /* ���������� */
    sort(a,i+1,r);/* ���Ұ������ */
}


