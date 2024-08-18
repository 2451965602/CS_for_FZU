
#ifndef HBLTNode_
#define HBLTNode_

typedef struct hbltnode *ltlink;/* ��ƫ���Ľ��ָ������ */
typedef struct hbltnode{/* ��ƫ���Ľ������ */
      int s;/* ���߶� */
      SetItem element;/* ����Ԫ�� */
      ltlink left,/* ������ָ�� */   
             right;/* ������ָ�� */  
}HBLTNode;

ltlink NewHBLTnode(SetItem x, int s)
{/* �����½�� */
    ltlink p=(ltlink)malloc(sizeof(HBLTNode));
    p->element=x;
    p->s=s;
    p->left=0;
    p->right=0;
    return p;
}

typedef struct hblt *MinHBLT;/* ��С����ƫ��ָ������ */
typedef struct hblt{/* ��С����ƫ���ṹ */
    ltlink root;/* �����ָ�� */ 
}HBLT;

#endif
