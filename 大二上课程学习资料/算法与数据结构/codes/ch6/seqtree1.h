// ������
/* 
ʹ��ʱǰ����� 
#include "seqtree.h"
*/

#include <math.h> 
#include <memory.h>

const int maxn=101111;

int seqn;
int xx[maxn];

typedef struct seqnode {/* ������������� */
    int mx;
    int lx;
    int rx;
}Sqnode;

Sqnode *tree=(Sqnode *)malloc((2*maxn)*sizeof(Sqnode));/* ������������� */

void update(int pos,int l,int r)
{
    int mid=(l+r)/2;
    tree[pos].mx=max(tree[2*pos].mx,tree[2*pos+1].mx); //����mx
    if(xx[mid]<xx[mid+1])//�������������������Ժϲ�
       tree[pos].mx=max(tree[pos].mx,tree[2*pos].rx+tree[2*pos+1].lx);
    tree[pos].lx=tree[2*pos].lx; //����lx
    if(tree[pos].lx==mid-l+1 && xx[mid]<xx[mid+1])
       tree[pos].lx+=tree[2*pos+1].lx;//������������,�������������������Ժϲ�
    tree[pos].rx=tree[2*pos+1].rx; //����rx
    if(tree[pos].rx==r-mid && xx[mid]<xx[mid+1])
       tree[pos].rx+=tree[2*pos].rx;//������������,�������������������Ժϲ�
}

void build(int l,int r,int pos)
{/* �����������ṹ */
	if(l==r){
        tree[pos].mx=tree[pos].lx=tree[pos].rx=1;
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,2*pos);
	build(mid+1,r,2*pos+1);
	update(pos,l,r);
}

void treeinit(int nn)
{/* ��ʼ�� */
	seqn=nn;
    memset(tree,0,(2*maxn)*sizeof(Sqnode));
	build(0,nn-1,1);
}

void inst(int k,int v,int t,int pos,int l,int r)
{
    if(l==r){
		if(t)xx[l]+=v;
		else xx[l]=v;
		tree[pos].mx=tree[pos].lx=tree[pos].rx=1;
		return ;
	}
	int mid=(l+r)/2;
	if(k<=mid)inst(k,v,t,2*pos,l,mid);
	else inst(k,v,t,2*pos+1,mid+1,r);
	update(pos,l,r);
}

int qsum(int lft,int rht,int pos,int l,int r)
{
    if(lft<=l && r<=rht)return tree[pos].mx;
    int mid=(l+r)/2;
    if(rht<=mid)return qsum(lft,rht,2*pos,l,mid);
    if(lft>mid)return qsum(lft,rht,2*pos+1,mid+1,r);
    int ret=max(qsum(lft,rht,2*pos,l,mid),qsum(lft,rht,2*pos+1,mid+1,r));
    //����[mid+1,rht]��[mid+1,r]�ཻ����
    int lx=min(rht-mid,tree[2*pos+1].lx);
    //����[lft,mid]��[l,mid]�ཻ����
    int rx=min(mid-lft+1,tree[2*pos].rx);
    if(xx[mid]<xx[mid+1])ret=max(ret,lx+rx);
    return ret;
}

void insert(int k,int v)
{
    inst(k,v,0,1,0,seqn-1);
}

void add(int k,int v)
{
    inst(k,v,1,1,0,seqn-1);
}

int query(int lft,int rht)
{
    return qsum(lft,rht,1,0,seqn-1);
}
