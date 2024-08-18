
#ifndef HBLTNode_
#define HBLTNode_

typedef struct hbltnode *ltlink;/* ��ƫ���Ľ��ָ������ */

typedef struct hbltnode {/* ��ƫ���Ľ������ */
      int s;/* ���߶� */
      SetItem element;/* ����Ԫ�� */
      ltlink left,/* ������ָ�� */   
             right;/* ������ָ�� */  
}HBLTNode;

typedef struct hblt *MaxHBLT;/* ������ƫ��ָ������ */
typedef struct hblt{/* ������ƫ���ṹ */
    ltlink root;/* �����ָ�� */ 
}HBLT;

ltlink NewHBLTnode(SetItem x,int s)
{
    ltlink p=(ltlink)malloc(sizeof(HBLTNode));
    p->element=x;
    p->s=s;
    p->left=0;
    p->right=0;
    return p;
}

#endif
