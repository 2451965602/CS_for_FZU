// �������� 

typedef struct node *link;/* ����ָ������ */
typedef struct node{/* �������� */
    ListItem element;/* ��Ԫ�� */ 
    link next;/* ָ����һ����ָ�� */
} Node;

typedef struct llist *List;/* ������ָ������ */
typedef struct llist{/* ���������� */
    link first,/* �������ָ�� */
         curr,/* ����ǰ���ָ�� */
         last;/* �����βָ�� */
}Llist;

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


