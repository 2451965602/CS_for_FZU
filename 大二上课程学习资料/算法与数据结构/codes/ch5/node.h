/* ������������ */

typedef struct node *link;/* ��������ָ������ */
typedef struct node{
    Item element;/* ������Ԫ�� */
    link next;/* ��һ���ָ�� */
}Node;

link NewNode()
{/* �����½�� */
    return (link)malloc(sizeof(Node));
}
