// ָ����н�� 

typedef struct qnode *qlink;/* ���н��ָ������ */
struct qnode{/* ���н�� */
    QItem element;/* ����Ԫ�� */
    qlink next;/* ָ����һ����ָ�� */
}Qnode;

qlink NewQNode()
{
    return (qlink)malloc(sizeof(Qnode));
}

typedef struct lque *Queue;/* ����ָ������ */
typedef struct lque{/* ���нṹ */
      qlink front;/* ����ָ�� */
      qlink rear;/* ��βָ�� */
}Lqueue;


Queue QueueInit();
int QueueEmpty(Queue Q);
QItem QueueFirst(Queue Q);
QItem QueueLast(Queue Q);
void EnterQueue(QItem x, Queue Q);
QItem DeleteQueue(Queue Q);
