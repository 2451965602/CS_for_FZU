// ���Ѱַ������

typedef struct indlist *List;/* ��ָ������ */
typedef struct indlist{/* ��ṹ���� */
      int n,/* �� */
          curr;/* ��ǰλ�� */
      int maxsize;/* �����Ͻ� */
      addr *table;/* �洢��Ԫ��ָ������� */ 
}Indlist;


addr NewNode()
{
    return (addr)malloc(sizeof(addr));
}

List ListInit();
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);


