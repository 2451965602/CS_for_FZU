// ����Ԫ������

typedef struct pnode *Pos;/* λ�ý��ָ������ */
struct pnode{/* λ�ý�� */
    int row,/* �� */ 
        col;/* �� */
}Pnode;

typedef Pos QItem;/* ����Ԫ������ */ 
typedef QItem* Qaddr;/* ����Ԫ��ָ������ */ 

Pos NewPos()
{
    return (Pos)malloc(sizeof(Pnode));
}

void QItemShow(QItem x)
{
   printf("%d  %d\n", x->row,x->col);
}

