/* Dijkstra�㷨 */
/* 
ʹ��ʱǰ����� 
#include "witem.h"
#include "awdgraph.h"
#include "dijkstra.h"
*/

#include "listitem.h"
#include "chain.h"

ListItem ListDelMin(List L,WItem dist[])
{
   link p,q,t,r;
   if(ListEmpty(L))return 0;
   p=L->first;t=p;r=t;q=p->next;
   while(q){
       if(dist[q->element]<dist[r->element]){t=p;r=q;}
       p=q;
       q=q->next;
   }
   if(t==r)L->first=r->next;
   else t->next=r->next;
   ListItem x=r->element;
   free(r);
   return x;
}

void Dijkstra(int s,WItem dist[],int prev[],Graph G)
{/* Dijkstra�㷨 */
   List L=ListInit(); 
   if(s<1 || s>G->n)return;
   /* ��ʼ��dist, prev�� L */
   for(int i=1;i<=G->n;i++){
      dist[i]=G->a[s][i];
      if(dist[i]==G->NoEdge)prev[i]=0;
      else{
          prev[i]=s;
          ListInsert(0,i,L);
      }
   }
   dist[s]=0;
    /* �޸� dist��prev */
   while(!ListEmpty(L)){
      /* ��L�о�����Сdistֵ�Ķ���v */
      /* ������v�ӱ�L��ɾ�������޸�dist��ֵ */
      int i=ListDelMin(L,dist);
      for(int j=1;j<=G->n;j++){
         if(G->a[i][j]!=G->NoEdge && (!prev[j] || dist[j]>dist[i]+G->a[i][j])){
            /* dist[j] ���� */
            dist[j]=dist[i]+G->a[i][j];
            /* ����j����� L */
            if(!prev[j])ListInsert(0,j,L);
            prev[j]=i;
         }
       }
   }
}

