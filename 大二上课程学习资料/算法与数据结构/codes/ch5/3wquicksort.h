/* �����ֿ��������㷨 */
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "3wquicksort.h"
*/

void sort(Item a[],int l,int r)
{/* �����ֿ��������㷨 */
    int i=l-1,j=r,p=l-1,q=r;
    Item v=a[r];//�����һ����������׼ֵ 
    if(r<=l)return;
    for(;;){
       while(less(a[++i],v));//�ҵ�ǰ�����v�� 
       while(less(v,a[--j]))if(j==l)break;//�ҵ�����С��v��
       if(i>=j)break;
       swap(a[i],a[j]);//�����������ҵ��� 
       if(eq(a[i],v)){p++;swap(a[p],a[i]);}//��ǰ����v��ȵľۼ���ǰ�� 
       if(eq(v,a[j])){q--;swap(a[q],a[j]);}//�Ѻ�����v��ȵľۼ������ 
    }
    swap(a[i],a[r]);j=i-1;i=i+1;//�ѻ�׼ֵv(a[r])�ŵ��м� 
    for(int k=l;k<p;k++,j--)swap(a[k],a[j]);//�Ѿۼ���ǰ�����v��ȵķŵ��м� 
    for(int k=r-1;k>q;k--,i++)swap(a[k],a[i]);//�Ѿۼ����������v��ȵķŵ��м�
    sort(a,l,j);//С�ڻ�׼ֵv�Ĳ��ּ����ݹ� 
    sort(a,i,r);//���ڻ�׼ֵv�Ĳ��ּ����ݹ�
}

