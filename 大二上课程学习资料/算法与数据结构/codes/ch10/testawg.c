/* �����ڽӾ���ʵ�ָ�Ȩͼ */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "awgraph.h"

int main()
{
   Graph G=Graphinit(4, 100);
   printf("���� %d \n",GraphEdges(G));

   GraphAdd(2,4,1,G);
   GraphAdd(1,3,2,G);
   GraphAdd(2,1,3,G);
   GraphAdd(1,4,4,G);
   GraphAdd(3,2,5,G);

   printf("��Ȩͼ \n");

   GraphOut(G);
   GraphDelete(1,2,G);

   printf("ɾ�� <1,2> \n");

   GraphOut(G);

   printf("Exist(3,1)=%d \n",GraphExist(3,1,G));
   printf("Degree(3)=%d \n",Degree(3,G));
   printf("Degree(1)=%d \n",Degree(1,G));
   printf("���� %d \n",GraphEdges(G));
   return 0;
}
