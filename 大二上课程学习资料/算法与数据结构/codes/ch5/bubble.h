// ð������
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "bubble.h"
*/

void sort(Item a[],int l,int r)
{ /* ð�������㷨 */
    for(int i=l+1;i<=r;i++)
      for(int j=i;j>l;j--)
        compswap(a[j-1],a[j]);
}
