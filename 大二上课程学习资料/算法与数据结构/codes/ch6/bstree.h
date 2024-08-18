/* ���������� */
/* 
ʹ��ʱǰ����� 
#include "treeitem.h"
#include "bstree.h"
*/

#ifndef BSTree_
#define BSTree_

#include "binary.h"

void InsertRebal(btlink v,BinaryTree T);
void DeleteRebal(btlink v, btlink p, BinaryTree T);

btlink NewBSnode(TreeItem x)
{
   btlink r;
   r=NewBNode();
   r->element=x;
   r->bal=0;
   r->left=0;
   r->right=0;
   r->parent=0;
   return r;
}

btlink GetBSnode(TreeItem x, btlink lptr, btlink rptr, btlink pptr)
{
   btlink r;
   r=NewBNode();
   r->element=x;
   r->bal=0;
   r->left=lptr;
   r->right=rptr;
   r->parent=pptr;
   return r;
}

btlink BSSearch(TreeItem x,BinaryTree T)
{
   btlink p=T->root;
   while(p) /* �鿴p->element */
      if(less(x,p->element))p=p->left;
      else if(less(p->element,x))p=p->right;
      else break;
   return p;
}

int BSMember(TreeItem x,BinaryTree T)
{
   return BSSearch(x,T)?1:0;
}

btlink BSInsert(TreeItem x,BinaryTree T)
{/* ����Ԫ��x */
   btlink p,r,pp=0;/* pp��p�ĸ����ָ�� */
   p=T->root;/* pΪ����ָ�� */
   /* ��������λ�� */
   while(p){/* ���쵱ǰ����д洢��Ԫ��p->element */
      pp=p;/* ѡ���������� */
      if(less(x,p->element))p=p->left;
      else if(less(p->element,x))p=p->right;
      else return 0;
   }
   /* �������½�� */
   r=NewBSnode(x);
   if(T->root){/* ��ǰ���ǿ� */
      if(less(x,pp->element))pp->left=r;
      else pp->right=r;
      r->parent=pp;
      //InsertRebal(r,T);/* ���������ƽ�� */
   }
   else T->root=r;/* ������� */
   return r;
}

btlink BSInsertVisit(TreeItem x,void(*visit)(TreeItem u),BinaryTree T)
{/* ����x���ڼ�����ʱ����Ԫ�� */ 
   btlink p,r,pp=0;/* pp��p�ĸ����ָ�� */
   p=T->root;/* pΪ����ָ�� */
   while(p){/* ���쵱ǰ����д洢��Ԫ��p->element */
      pp=p;
      if(less(x,p->element))p=p->left;
      else if(less(p->element,x))p=p->right;
      else{visit(p->element);return p;}/* �����Ѵ���Ԫ�� */
   }
   /* �������½�� */
   r=NewBSnode(x);
   if (T->root) {/* ��ǰ���ǿ� */
      if (less(x,pp->element)) pp->left=r;
      else pp->right=r;
      r->parent=pp;
      //InsertRebal(r,T);/* ���������ƽ�� */
   }
   else T->root=r;/* ������� */
   return r;
}

btlink BSDelete(TreeItem x,BinaryTree T)
{/* ɾ��Ԫ��x */
   btlink c,p,s,ps,pp=0;/* pp��p�ĸ����ָ�� */
   p=T->root;/* pΪ����ָ�� */
   while(p && !eq(p->element,x)){/* ����Ҫɾ���Ľ�� */
      pp=p;
      if(less(x,p->element))p=p->left;
      else p=p->right;
   }
   if(!p)return 0;/* δ�ҵ�Ҫɾ���Ľ�� */
   /* p��Ҫɾ���Ľ�� */
   if(p->left && p->right){/* ����p��2�����ӽ������ */
      /* �任����1����0�����ӽ������ */
      /* ����p���������е����Ԫ�� */
      s=p->left;ps=p;/* ps��s�ĸ����ָ�� */
      while(s->right){/* һֱ���������Ԫ�� */
         ps=s;
         s=s->right;
      }
      /* ��s�����Ԫ���滻p�е�Ԫ�� */
      p->element=s->element;
      p=s;
      pp=ps;
   }
   /* ��ʱp���ֻ��1�����ӽ�� */
   /* ��p�Ķ��ӽ��ָ�뱣����c�� */
   if(p->left)c=p->left;
   else c=p->right;
   /* ɾ����� p */
   if(p==T->root){
        T->root=c;
        if(c)c->parent=0;
   }
   else{/* ȷ��p���丸��������ӽ�㻹���Ҷ��ӽ�� */
      if(p==pp->left){/* p������ӽ�� */
        pp->left=c;
        p->left=p;/* ��һ��Ϊ����ƽ����׼�� */
      }
      else pp->right=c;/* p���Ҷ��ӽ�� */
      if(c)c->parent=p->parent;
   }
   //DeleteRebal(c,p,T);/* ɾ��������ƽ�� */
   free(p);
   return c;
}

btlink CopyTree(btlink t)
{/* ������ */
   btlink newlptr,newrptr,newnode;
   if(t==0)return 0;
   if(t->left!=0)newlptr=CopyTree(t->left);
   else newlptr=0;
   if(t->right!=0)newrptr=CopyTree(t->right);
   else newrptr=0;
   newnode=GetBSnode(t->element,newlptr,newrptr,0);
   return newnode;
}

BinaryTree BSTCopy(BinaryTree T)
{/* ���ƶ��������� */
   btlink s;
   BinaryTree S=(BinaryTree)malloc(sizeof *S);
   if(T==0)return 0;
   s=CopyTree(T->root);
   S->root=s;
   return S;
}

void BSAscend(BinaryTree T)
{/* ���յ������������������Ԫ�� */
   InOut(T);
}

#endif
