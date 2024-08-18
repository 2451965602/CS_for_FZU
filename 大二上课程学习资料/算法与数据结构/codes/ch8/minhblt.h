/* ��ƫ���� */

#ifndef MinHBLT_
#define MinHBLT_

#include "hbltnode.h"
#include "qitem1.h"
#include "lqueue.h"

#define swap(A,B) {ltlink t=A;A=B;B=t;}

MinHBLT HBLTInit()
{/* ����һ�ÿ��� */
   MinHBLT H=(MinHBLT)malloc(sizeof *H);
   H->root=0;
   return H;
}

bool HBLTEmpty(MinHBLT H)
{/* �Ƿ���� */
    return H->root==0;
}

SetItem HBLTMin(MinHBLT H)
{/* ��СԪ�� */
   if(H->root==0)return 0;
   return H->root->element;
}

ltlink Concatenate(ltlink x, ltlink y)
{/* ��ƫ���ĺϲ����� */
   if(!y)return x;/* y�ǿ��� */
   if(!x)return y;/* x�ǿ��� */
   /* x��y���ǿ� */
   if(less(y->element,x->element))swap(x,y);
   /* ��ʱ��x->element >= y->element */
   x->right=Concatenate(x->right,y);
   if(!x->left){/* x��������Ϊ���� */
      /* �������������� */
      x->left=x->right;
      x->right=0;
      x->s=1;
   }
   else{/* ��x�����������򽻻����������� */
      if(x->left->s>x->right->s)swap(x->left,x->right);
      x->s=x->right->s+1;
   }
   return x;
}

void HBLTConc(MinHBLT H,MinHBLT T)
{/* �ϲ���ƫ�� */
   H->root=Concatenate(H->root,T->root);
   T->root=0;
}

void HBLTInsert(SetItem x,MinHBLT H)
{/* �������� */
   ltlink q=NewHBLTnode(x,1);
   H->root=Concatenate(H->root,q);
}

SetItem DeleteMin(MinHBLT H)
{/* ɾ����������СԪ */
   if(H->root==0)return 0;
   SetItem x=H->root->element; /* ��СԪ */
   ltlink L=H->root->left;
   ltlink R=H->root->right;
   free(H->root);
   H->root=Concatenate(L,R);
   return x;
}

MinHBLT BuildHBLT(SetItem a[],int n)
{/* ��ƫ�����Ľ����㷨 */
   Queue Q=QueueInit();
   MinHBLT H=HBLTInit();
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
