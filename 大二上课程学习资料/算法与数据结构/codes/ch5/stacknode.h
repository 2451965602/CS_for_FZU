// ջ��� 

typedef struct snode *slink;/* ջ���ָ������ */
typedef struct snode{/* ջ�ṹ */
    StackItem element;/* ջԪ�� */ 
    slink next;/* ��һ���ָ�� */ 
}StackNode;

slink NewStackNode()
{
    return (slink)malloc(sizeof(StackNode));
}

typedef struct lstack *Stack;/* ջָ������ */
typedef struct lstack{/* ջ�ṹ */
    slink top;/* ջ��ָ�� */
}Lstack;


