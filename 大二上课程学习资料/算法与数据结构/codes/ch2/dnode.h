// ѭ��˫����ṹ

typedef struct node *link;/* ˫������ָ������ */
typedef struct node {/* ˫���������� */
    ListItem element;/* ��Ԫ�� */
    link left,/* ��������ָ�� */ 
         right;/* �����ҽ��ָ�� */ 
} Node;

typedef struct dlist *List;/* ѭ��˫����ָ������ */
typedef struct dlist{/* ѭ��˫����ṹ */
    int n;/* �� */
    link header,/* �������ָ�� */
         curr;/* ����ǰ���ָ�� */
}Dlist;

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


