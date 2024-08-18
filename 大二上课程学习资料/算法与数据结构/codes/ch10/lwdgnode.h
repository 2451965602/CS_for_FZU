/* �ڽӱ�Ȩ����ͼ�ṹ */

#ifndef lwgnode_
#define lwgnode_

typedef struct lwnode *glink;/* ��Ȩ�ڽӱ�ָ������ */
struct lwnode{/* ��Ȩ�ڽӱ������� */ 
    int v;/* �ߵ���һ������ */ 
    WItem w;/* ��Ȩ */ 
    glink next;/* �ڽӱ�ָ�� */ 
}Lwnode;

glink NewLWNode(int v,WItem w,glink next)
{/* ����һ�����ڽӱ��� */
    glink x=(glink)malloc(sizeof *x);
    x->v=v;x->w=w;x->next=next;
    return x;
}

typedef struct graph *Graph;/* ��Ȩͼָ������ */
struct graph{/* �ڽӱ�Ȩͼ�ṹ */
    int n;/* ������ */
    int e;/* ���� */
    glink *adj;/* �ڽӱ����� */
}Lwgraph;

void ShowNode(glink p)
{
   printf("%d %d ",p->v,p->w);
}

Graph Graphinit(int v);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,WItem w,Graph G);
void GraphDelete(int i,int j,Graph G);
int Degree(int i,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
