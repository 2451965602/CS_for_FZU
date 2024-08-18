/* �ڽӾ���Ȩͼ�ṹ */

#ifndef awgnode_
#define awgnode_

typedef struct graph *Graph;/* ��Ȩͼָ������ */
struct graph{/* �ڽӾ���Ȩͼ�ṹ */
      WItem NoEdge;/* �ޱ߱�� */
      int n;/* ������ */
      int e;/* ���� */
      WItem **a;/* �ڽӾ��� */
}AWDgraph;

Graph Graphinit(int n,WItem noEdge);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,WItem w,Graph G);
void GraphDelete(int i,int j,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
