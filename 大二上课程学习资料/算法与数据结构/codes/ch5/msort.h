/* �ϲ������㷨 */

//ʹ��ʱǰ����� 
#include "item.h"
//#include "msort.h"


#define mini(A,B) (A<B)?A:B
#define maxN 10000

Item b[maxN];//����ʱ������ݵ����� 

void insertion(Item a[],int l,int r)//�������� 
{
    for(int i=l+1;i<=r;i++)compswap(a[l],a[i]);
    for(int i=l+2;i<=r;i++){ 
        int j=i;Item v=a[i];
        while(less(v,a[j-1])){a[j]=a[j-1];j--;}
        a[j]=v;
    }
}

void copy(Item b[],Item a[],int l,int r)
{
    for(int i=l;i<=r;i++)a[i]=b[i];
}

void mergeab(Item a[],Item b[],int l,int m,int r)
{/* �ϲ�a[l:m]}��a[m+1:r] ��b[l:r] */
   int i=l,j=m+1,k=l;
    /* ȡ�����н�СԪ�ص�����b�� */
   while((i<=m) && (j<=r))
      if(less(a[i],a[j]))b[k++]=a[i++];
      else b[k++]=a[j++];
   /* ����ʣ��Ԫ�� */
   if(i>m)for(i=j;i<=r;i++)b[k++]=a[i];
   else for(;i<=m;i++)b[k++]=a[i];
}

void msort(Item a[],int l,int r)
{/* �ϲ������㷨 */
    int m=(r+l)/2;/* ȡ�е� */
    if(r<=l)return;
    msort(a,l,m);/* ���������� */
    msort(a,m+1,r);/* ���Ұ������ */
    mergeab(a,b,l,m,r);/* �ϲ�������b */
    copy(b,a,l,r);/* ���ƻ�����a */
}

void mergeAB(Item c[],Item a[],int N,Item b[],int M )
{//������a��b�ϲ���c�� 
    for(int i=0,j=0,k=0;k<N+M;k++){
        if(i==N){c[k]=b[j++];continue;}
        if(j==M){c[k]=a[i++];continue; }
        c[k]=(less(a[i],b[j]))?a[i++]:b[j++];
    }
}

void merge(Item a[],int l,int m,int r)
{
    int i,j,k;
    for(i=m+1;i>l;i--)b[i-1]=a[i-1];
    for(j=m;j<r;j++)b[r+m-j]=a[j+1]; 
    for(k=l;k<=r;k++)//һ������ʱ�������ϲ� 
       if(less(b[i],b[j]))a[k]=b[i++];
       else a[k]=b[j--];
}

void mergesort(Item a[],int l,int r)
{
    int m=(r+l)/2;
    if(r<=l)return;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
}
  
void mergesortAB(Item a[],Item b[],int l,int r)
{
    int m=(l+r)/2;
    if(r-l<=10){insertion(a,l,r);return;}
    mergesortAB(b,a,l,m);
    mergesortAB(b,a,m+1,r);
    mergeab(b,a,l,m,r);//�ϲ�b�������������ݵ�a 
}

void mergesort1(Item a[],int l,int r)
{
    for(int i=l;i<=r;i++)b[i]=a[i];
    mergesortAB(a,b,l,r);//b����ʱ���� 
}

void mergesortBU(Item a[],int l,int r)
{//�Ե����Ϻϲ����� 
    for(int m=1;m<=r-l;m=m+m)
      for(int i=l;i<=r-m;i+=m+m)
        merge(a,i,i+m-1,mini(i+m+m-1,r));
}

void sort(Item a[],int l,int r)
{
    //msort(a,l,r);    
    //mergesort(a,l,r);    
    mergesortBU(a,l,r);    
}

