// ѡ�������㷨
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "selsort.h"
*/

int mini(Item a[], int i, int r)
{/* ȷ��a[i:r]����СԪ���±� */
   int min=i;
   for(int j=i+1;j<=r;j++)if(less(a[j],a[min]))min=j;
   return min;
}

void sort(Item a[], int l, int r)
{ /* ѡ�������㷨 */
    for(int i=l;i<r;i++){int j=mini(a,i,r);swap(a[i],a[j]);}
}



