/* ���ڽӾ���ʵ�ָ�Ȩ����ͼ */
/* 
ʹ��ʱǰ����� 
#include "witem.h"
#include "awdgraph.h"
*/

#ifndef AdjacencyWDigraph_
#define AdjacencyWDigraph_

#include "awdgnode.h"
#include "make2db.h"

Graph Graphinit(int n,WItem noEdge)
{/* ����n����������ĸ�Ȩ����ͼ */
   Graph G=(Graph)malloc(sizeof *G);
   G->n=n;
   G->e=0;
   G->NoEdge=noEdge;
   G->a=Make2DArray(G->n+1,G->n+1,noEdge);
   return G;
}

int GraphEdges(Graph G)
{/* ���� */
    return G->e;
}

int GraphVertices(Graph G)
{/* ������ */
    return G->n;
}

int GraphExist(int i,int j,Graph G)
{/* ��(i,j)�Ƿ���� */
   if(i<1 || j<1 || i>G->n || j>G->n || G->a[i][j]==G->NoEdge)return 0;
   return 1;
}

void GraphAdd(int i,int j,WItem w,Graph G)
{/* �����(i,j) */
   if(i<1 || j<1 || i>G->n || j>G->n || i==j || G->a[i][j]!=G->NoEdge)return;
   G->a[i][j]=w;
   G->e++;
}

void GraphDelete(int i,int j,Graph G)
{/* ɾ����(i,j) */
   if(i<1 || j<1 || i>G->n || j>G->n || G->a[i][j]==G->NoEdge)return;
   G->a[i][j]=G->NoEdge;
   G->e--;
}

int OutDegree(int i,Graph G)
{/* ����i�ĳ��� */
   int sum=0;
   if(i<1 || i>G->n)return -1;
   /* ͳ�Ƴ��� */
   for(int j=1;j<=G->n;j++)
      if(G->a[i][j]!=G->NoEdge)sum++;
   return sum;
}

int InDegree(int i, Graph G)
{/* ����i����� */
   int sum=0;
   if(i< 1 || i>G->n)return -1;
   /* ͳ����� */
   for(int j=1;j<=G->n;j++)
      if(G->a[j][i]!=G->NoEdge)sum++;
   return sum;
}

void GraphOut(Graph G)
{/* ����ڽӾ��� */
   for(int i=1;i<=G->n;i++){
      for(int j=1;j<=G->n;j++)WItemShow(G->a[i][j]);
      printf("\n");
   }
}

#endif
