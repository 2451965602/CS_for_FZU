/* ���ڽӱ�ʵ�ָ�Ȩͼ */
/* 
ʹ��ʱǰ����� 
#include "witem.h"
#include "lwgraph.h"
*/

#ifndef LinkedWGraph_
#define LinkedWGraph_

#include "lwgnode.h"

Graph Graphinit(int v)
{/* ����n�����������ͼ */
   Graph G=(Graph)malloc(sizeof *G);
   G->n=v;
   G->e=0;
   G->adj=(glink *)malloc((v+1)*sizeof(glink));
   for(int i=0;i<=v;i++)G->adj[i]=0;
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

int GraphExist(int i, int j, Graph G)
{/* ��(i,j)�Ƿ���� */
   if(i<1 || j<1 || i>G->n || j>G->n)return 0;
   glink p=G->adj[i];
   while(p && p->v!=j)p=p->next;
   if(p)return 1;
   else return 0;
}

void GraphAdd(int i, int j, WItem w, Graph G)
{/* �����(i,j) */
   if(i<1 || j<1 || i>G->n || j>G->n || i==j || GraphExist(i,j,G))return;
   G->adj[i] = NewLWNode(j,w,G->adj[i]);
   G->adj[j] = NewLWNode(i,w,G->adj[j]);
   G->e++;
}

void GraphDelete(int i,int j,Graph G)
{/* ɾ����(i,j) */
   glink p,q;
   if(i<1 || j<1 || i>G->n || j>G->n || !GraphExist(i,j,G))return;
   p=G->adj[i];
   if(p->v == j){
      G->adj[i]=p->next;
      free(p);
   }
   else{
      while(p && p->next->v!=j)p=p->next;
      if(p){
          q=p->next;
          p->next=q->next;
          free(q);
      }
   }
   p=G->adj[j];
   if(p->v==i){
       G->adj[j]=p->next;
       free(p);
   }
   else{
      while(p && p->next->v!=i)p=p->next;
      if(p){ 
          q=p->next;
          p->next=q->next;
          free(q);
      }
   }
   G->e--;
}

int Degree(int i, Graph G)
{/* ����i�Ķ� */
   int j=0;
   if(i<1 || i>G->n)return -1;
   /* ͳ�Ʊ� */
   glink p=G->adj[i];
   while(p){
        j++;
        p=p->next;
   }
   return j;
}

void GraphOut(Graph G)
{/* ����ڽӱ� */
   for(int i=1;i<=G->n;i++){
     glink p=G->adj[i];
     while(p){
       ShowNode(p);
       p=p->next;
     }
     printf("\n");}
}

#endif
