// ���������㷨
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "quicksort.h"
*/

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

void sort(Item a[],int l,int r)
{/* ���������㷨 */ 
    if(r<=l)return;
    int i=partition(a,l,r);
    sort(a,l,i-1);/* ���������� */
    sort(a,i+1,r);/* ���Ұ������ */
} 
  
/*void sort(Item a[], int l, int r)
{ /* ���������㷨 /
    if(r<=l)return;
    int i=partition(a,l,r);
    if(i-l>r-i){sort(a,i+1,r);sort(a,l,i-1);}
    else{sort(a,l,i-1);sort(a,i+1,r);}
}*/ 

