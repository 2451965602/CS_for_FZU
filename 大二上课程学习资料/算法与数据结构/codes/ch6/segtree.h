// �߶���
/* 
ʹ��ʱǰ����� 
#include "segtree.h"
*/

#include <memory.h>

const int maxn=28010;

typedef struct intv
{/* �߶ν������ */
	int low,/* �߶���˵��±� */
        high;/* �߶��Ҷ˵��±� */
}Intv;

typedef struct stnode *link;/* �߶������ָ������ */ 
typedef struct stnode {/* �߶���������� */
    int left,/* ��׼�߶���� */
        right;/* ��׼�߶��Ҷ� */
    int count;/* ���򸲸Ǽ��� */
    int clq;/* �߶μ������ */
    float uni;/* �߶μ����ĳ��� */
}Stnode;

Stnode *tree=(Stnode *)malloc((2*maxn)*sizeof(Stnode));/* �߶���������� */

int nn,/* �߶ν������ */
    mm;/* �߶����� */
float *xx;/* �߶ν������ */
intv *iset;/* �߶����� */ 

void outtree(int n)
{/* ����߶���������� */
   for(int i=1;i<=2*n+1;i++) 
       printf("pos=%d l=%d r=%d count=%d\n",i,tree[i].left,tree[i].right,tree[i].count); 
}

void update(int pos)
{/* �����û���Ϣ */
    int l=tree[pos].left,r=tree[pos].right;
    int cnt=tree[pos].count;
    float ret=(tree[pos].count)?xx[r]-xx[l]:0;
    if(r-l<=1){
        tree[pos].clq=cnt;
        tree[pos].uni=ret;
    }
    else{
        float unil=tree[pos*2].uni,unir=tree[pos*2+1].uni;
        int clql=tree[pos*2].clq,clqr=tree[pos*2+1].clq;
        tree[pos].clq=cnt+max(clql,clqr);
        if(cnt)tree[pos].uni=ret;
        else tree[pos].uni=unil+unir;
    }
}

void change(int pos,int k)
{/* ���½����Ϣ */
    /* k=1Ϊ���룬k=-1Ϊɾ�� */
    tree[pos].count+=k;
}

void build(int l,int r,int pos)
{/* �����߶����ṹ */
	tree[pos].left=l;
	tree[pos].right=r;
	if(l+1==r)return;
	int mid=(l+r)/2; 
	build(l,mid,pos*2);
	build(mid,r,pos*2+1);
}

void inst(intv r,int pos)
{/* ���뵥���߶� */
    if(r.low<=tree[pos].left && tree[pos].right<=r.high)change(pos,1);
    else{
        int mid=(tree[pos].left+tree[pos].right)>>1;
        if(r.low<mid)inst(r,pos*2);
        if(r.high>mid)inst(r,pos*2+1);
    }
    update(pos);
}

void erase(intv r,int pos)
{/* ɾ�������߶� */
    if(r.low<=tree[pos].left && tree[pos].right<=r.high)change(pos,-1);
    else{
        int mid=(tree[pos].left+tree[pos].right)>>1;
        if(r.low<mid)erase(r,pos*2);
        if(r.high>mid)erase(r,pos*2+1);
    }
    update(pos);
}

void insert()
{/* �����߶μ�iset�������߶� */
    for(int i=0;i<mm;i++)inst(iset[i],1);
}

void buildst(int n,int m,float *x,intv *s)
{/* �����߶μ�s���߶��� */
    nn=n,mm=m;
    xx=x;
    iset=s;
    memset(tree,0,(2*maxn)*sizeof(Stnode));
    //outtree(nn);
    build(0,n-1,1);
    insert();
}

void quit()
{/* �ͷ��߶���������� */
    free(tree);
}

int stab(float x, int pos)
{/* �߶������̼��� */
    int l=tree[pos].left,r=tree[pos].right,c=0;
    if(x>xx[l] && x<=xx[r])c+=tree[pos].count;
    if(r-l>1){
        int mid=(l+r)>>1;
        if(x<=xx[mid])c+=stab(x,pos*2);
        else c+=stab(x,pos*2+1);
    }
    return c;
}

float uni1(int pos)
{/* �߶β� */
    return tree[pos].uni;
}

float uni(int pos)
{/* �߶β� */
    int l=tree[pos].left,r=tree[pos].right;
    float ret=(tree[pos].count)?xx[r]-xx[l]:0; 
    if(r-l<=1 || (tree[pos].count))return ret;
    else return uni(pos*2)+uni(pos*2+1);
}

int maxclq(int pos)
{/* �߶μ������ */
    int l=tree[pos].left,r=tree[pos].right,cnt=tree[pos].count;
    if(r-l<=1)return cnt;
    else return cnt+max(maxclq(pos*2),maxclq(pos*2+1));
}

int maxclq1(int pos)
{/* �߶μ������ */
     return tree[pos].clq;
}
