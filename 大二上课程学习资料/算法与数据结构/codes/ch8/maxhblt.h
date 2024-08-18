/* ������ƫ���� */

#ifndef MaxHBLT_
#define MaxHBLT_

#include "maxhbltnode.h"
#include "qitem1.h"
#include "lqueue.h"

#define swap(A,B) {ltlink t=A;A=B;B=t;}

MaxHBLT HBLTInit()
{/* ����һ�ÿ��� */
   MaxHBLT H=(MaxHBLT)malloc(sizeof *H);
   H->root=0;
   return H;
}

SetItem HBLTMax(MaxHBLT H)
{/* ���Ԫ�� */
   if (H->root==0)return 0;
   return H->root->element;
}

bool HBLTEmpty(MaxHBLT H)
{/* �Ƿ���� */
    return H->root==0;
}
 
ltlink Concatenate(ltlink x, ltlink y)
{/* ��ƫ���ĺϲ����� */
   if(!y)return x;/* y�ǿ��� */
   if(!x)return y;/* x�ǿ��� */
   /* x��y���ǿ� */
   if(less(x->element,y->element))swap(x,y);
   /* ��ʱ��x->element >= y->element */
   x->right=Concatenate(x->right,y);
   if(!x->left){/* x��������Ϊ���� */
      /* �������������� */
      x->left=x->right;
      x->right=0;
      x->s=1;
   }
   else{/* ��x�����������򽻻����������� */
      if(x->left->s<x->right->s)swap(x->left,x->right);
      x->s=x->right->s+1;
   }
   return x;
}

void HBLTConc(MaxHBLT H,MaxHBLT T)
{/* �ϲ���ƫ�� */
   H->root=Concatenate(H->root,T->root);
   T->root=0;
}

void HBLTInsert(SetItem x,MaxHBLT H)
{/* �������� */
   ltlink q=NewHBLTnode(x,1);
   H->root=Concatenate(H->root,q);
}

SetItem DeleteMax(MaxHBLT H)
{/* ɾ�����������Ԫ */
   if(H->root==0)return 0;
   SetItem x=H->root->element;/* ���Ԫ */
   ltlink L=H->root->left;
   ltlink R=H->root->right;
   free(H->root);
   H->root=Concatenate(L,R);
   return x;
}

MaxHBLT BuildHBLT(SetItem a[], int n)
{/* ��ƫ�����Ľ����㷨 */
   Queue Q=QueueInit();
   MaxHBLT H=HBLTInit();
   /* ��ʼ����ƫ�������� */
   for(int i=1;i<=n;i++){
      /* ����������� */
      ltlink q=NewHBLTnode(a[i],1);
      EnterQueue(q,Q);
   }
   /* ������˳��ϲ���ƫ���� */
   for(int i=1;i<=n-1;i++){
      /* �Ӷ�����ɾ��������ƫ�������ϲ�֮ */
      ltlink b=DeleteQueue(Q);
      ltlink c=DeleteQueue(Q);
      b=Concatenate(b,c);
      /* �ϲ��������ƫ������� */
      EnterQueue(b,Q);
   }
   if(n)H->root=DeleteQueue(Q);
   return H;
}

void HBLTOut(ltlink t)
{/* �����ƫ���� */
   if(t){
      HBLTOut(t->left);
      HBLTOut(t->right);
      SetItemShow(t->element);
   }
}

#endif
