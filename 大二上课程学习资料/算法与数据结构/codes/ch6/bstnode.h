/* ����������������� */

typedef struct btnode *btlink;/* ���������ָ������ */
struct btnode{/* ���������ṹ */
    TreeItem element;/* ����������ţ�Ԫ�أ� */ 
    btlink left;/* ������ */ 
    btlink right;/* ������ */
    btlink parent;/* �����ָ�� */
    int bal;/* ���ƽ������ */
}Btnode;

btlink NewBNode()
{/* ��������� */
    return (btlink)malloc(sizeof(Btnode));
}

typedef struct bstree *BinaryTree;/* �������������� */
typedef struct bstree{/* �����������ṹ */
      btlink root;/* �����ָ�� */
}BStree;

