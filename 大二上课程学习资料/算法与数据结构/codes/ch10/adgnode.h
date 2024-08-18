/* �ڽӾ�������ͼ�ṹ */

#ifndef adgnode_
#define adgnode_

typedef struct graph *Graph;/* ����ͼָ������ */
struct graph{/* �ڽӾ�������ͼ�ṹ */
      int n;/* ������ */
      int e;/* ���� */
      int **a;/* �ڽӾ��� */
}AWDgraph;

Graph Graphinit(int n);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,Graph G);
void GraphDelete(int i,int j,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
