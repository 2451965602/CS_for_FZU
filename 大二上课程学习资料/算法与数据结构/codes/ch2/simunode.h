// �α��ṹ 
typedef struct slist *List;/* �α��ָ������ */
typedef struct slist{/* �α��ṹ */
      int first,/* ���׽���α� */
          curr,/* ��ǰ����α� */
          last;/* ��β����α� */
      Space s;
}Slist;

List ListInit(int size);
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);


