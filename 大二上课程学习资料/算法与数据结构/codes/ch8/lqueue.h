// ��ָ��ʵ�ֶ���
/* 
ʹ��ʱǰ����� 
#include "qitem.h"
#include "lqueue.h"
*/

#include "qnode.h"

Queue QueueInit()
{
   Queue Q=(Queue)malloc(sizeof *Q);
   Q->front=Q->rear=0;
   return Q;
}

int QueueEmpty(Queue Q)
{
    return Q->front==0;
}

QItem QueueFirst(Queue Q)
{/* ǰ�᣺���зǿ� */
    return Q->front->element;
}

QItem QueueLast(Queue Q)
{/* ǰ�᣺���зǿ� */
    return Q->rear->element;
}

void EnterQueue(QItem x, Queue Q)
{
    qlink p=NewQNode();/* ����һ���½�� */
    p->element=x;
    p->next=0;
    /* ��β�����½�� */
    if(Q->front)Q->rear->next=p;/* ���зǿ� */
    else Q->front=p;/* ���п� */
    Q->rear=p;
}

QItem DeleteQueue(Queue Q)
{/* ǰ�᣺���зǿ� */
	QItem x = Q->front->element; /* ������Ԫ�ش���x�� */
    /* ɾ�����׽�� */
    qlink p=Q->front;
    Q->front=Q->front->next;
    free(p);
    return x;
}
