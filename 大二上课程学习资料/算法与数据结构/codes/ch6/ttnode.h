/* ����������������� */

typedef struct btnode *tbtlink;
struct tbtnode {
     TreeItem element;
     btlink left;/* ������ */
     btlink right;/* ������ */
     int leftThread,/* ��������־ */
         rightThread;/* ��������־ */
}ThreadedNode;


tbtlink NewBNode()
{
    return (tbtlink)malloc(sizeof(ThreadedNode)); 
}

typedef struct binarytree *TBinaryTree;/* �������������� */
typedef struct binarytree{/* �����������ṹ */
      tbtlink root;/* ���� */ 
}TBTree;

