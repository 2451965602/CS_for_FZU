/* ����ȡ�п��������㷨 */
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "m3quicksort.h"
*/

#define M 1000

void insertion(Item a[],int l,int r)
{
    for(int i=l+1;i<=r;i++)compswap(a[l],a[i]);
    for(int i=l+2;i<=r;i++){ 
        int j=i;Item v=a[i];
        while(less(v,a[j-1])){a[j]=a[j-1];j--;}
        a[j]=v;
    }
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

void qsort(Item a[],int l,int r)
{ /* ����ȡ�п��������㷨 */
    if(r-l<=M)return;
    swap(a[(l+r)/2],a[r-1]);
    compswap(a[l],a[r-1]);
    compswap(a[l],a[r]);
    compswap(a[r-1],a[r]);
    int i=partition(a,l+1,r-1);
    qsort(a,l,i-1);
    qsort(a,i+1,r);
}

void sort(Item a[],int l,int r)
{
    qsort(a,l,r);
    insertion(a,l,r);
}



