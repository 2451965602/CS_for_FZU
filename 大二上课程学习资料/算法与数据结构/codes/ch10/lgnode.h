/* �ڽӱ�ͼ�ṹ */

#ifndef lgnode_
#define lgnode_

typedef struct lnode *glink;/* �ڽӱ�ָ������ */
struct lnode{/* �ڽӱ������� */ 
    int v;/* �ߵ���һ������ */ 
    glink next;/* �ڽӱ�ָ�� */ 
}Lnode;

glink NewLNode(int v,glink next)
{/* �����ڽӱ��� */ 
    glink x=(glink)malloc(sizeof *x);
    x->v=v;x->next=next;
    return x;
}

typedef struct graph *Graph;
struct graph{
      int n;/* ������ */
      int e;/* ���� */
      glink *adj;/* �ڽӱ����� */
}Lgraph;

Graph Graphinit(int n);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,Graph G);
void GraphDelete(int i,int j,Graph G);
int Degree(int i,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
