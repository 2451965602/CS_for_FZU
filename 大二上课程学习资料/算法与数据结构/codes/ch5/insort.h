// ���������㷨
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "insort.h"
*/
void insert(Item a[],int l,int i)
{/* Ԫ��a[i]��������a[l:i] */
    Item v=a[i];
    while(i>l && less(v,a[i-1])){a[i]=a[i-1];i--;}
    a[i]=v;
}

void sort(Item a[],int l,int r)
{/* ���������㷨 */
    for(int i=l+1;i<=r;i++)insert(a,l,i);
}

