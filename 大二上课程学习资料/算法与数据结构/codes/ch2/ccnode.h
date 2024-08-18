// file ccnode.h
// ��ѭ�������� 

typedef struct node *link;/* ����ָ������ */
typedef struct node {/* �������� */
    ListItem element; /* ��Ԫ�� */ 
    link next;/* ָ����һ����ָ�� */
} Node;

typedef struct clist *List;/* ��ѭ������ָ������ */
typedef struct clist{/* ��ѭ������ṹ */
    int n;/* �� */
    link last,/* �����βָ�� */
         curr;/* ����ǰ���ָ�� */
}Clist;

link NewNode()
{
    return (link)malloc(sizeof(Node));
}

List ListInit();
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);


