// ���������� 

typedef struct node *link;/* ����ָ������ */
struct node{/* �������� */
    SetItem element;/* ����Ԫ�� */ 
    link next;/* ָ����һ����ָ�� */
}Node;

typedef struct list *Set;/* ��������ָ������ */
typedef struct list{/* ������������ */
    link first;/* �������ָ�� */
}LSet;

link NewNode()
{
    return (link)malloc(sizeof(Node));
}
