/* ���������㷨 */
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "countsort.h"
*/

#define m 10000

void ctsort(int a[],int b[],int n)
{/* ���������㷨 */
    int cnt[m]={0};
    for(int i=0;i<n;i++)cnt[a[i]]++;
    /* cnt[i]�д�ŵ���a�м�ֵ����i��Ԫ�ظ��� */
    for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
    /* cnt[i]�д�ŵ���a�м�ֵС�ڻ����i��Ԫ�ظ��� */
    for(int i=n-1;i>=0;i--)b[--cnt[a[i]]]=a[i];
}

void countsort(int a[],int l,int r)
{/* ���������㷨 */
    int *b=(int *)malloc(sizeof(int)*(r+1));
    int cnt[m]={0};
    for(int i=l;i<=r;i++)cnt[a[i]]++;
    /* cnt[i]�д�ŵ���aa[l,r]�м�ֵ����i��Ԫ�ظ��� */
    for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
    /* cnt[i]�д�ŵ���a[l,r]�м�ֵС�ڻ����i��Ԫ�ظ��� */
    for(int i=r;i>=l;i--)b[--cnt[a[i]]]=a[i];
    /* ��дa[l,r] */
    for(int i=l;i<=r;i++)a[i]=b[i-l];
    free(b);    
}

void sort(int a[],int l,int r)
{
    countsort(a,l,r);
}

