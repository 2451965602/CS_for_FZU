/* �ڽӾ�������ͼ�ṹ */

#ifndef agnode_
#define agnode_

typedef struct graph *Graph;/* ����ͼָ������ */
struct graph{/* �ڽӾ�������ͼ�ṹ */
      int n;/* ������ */
      int e;/* ���� */
      int **a;/* �ڽӾ��� */
}Agraph;

Graph Graphinit(int n);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,Graph G);
void GraphDelete(int i,int j,Graph G);
int Degree(int i,Graph G);
void GraphOut(Graph G);

#endif
