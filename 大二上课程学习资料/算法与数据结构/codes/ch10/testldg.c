/* �����ڽӱ�ʵ������ͼ */

#include <stdio.h>
#include <stdlib.h>
#include "ldgraph.h"

int main()
{
   Graph G = Graphinit(4);
   printf("���� %d \n",GraphEdges(G));

   GraphAdd(2,4,G);
   GraphAdd(1,3,G);
   GraphAdd(2,1,G);
   GraphAdd(1,4,G);
   GraphAdd(4,2,G);

   printf("����ͼ \n");

   GraphOut(G);
   GraphDelete(2,4,G);

   printf("ɾ��<2,4> \n");

   GraphOut(G);

   //GraphDelete(3,4,G);

   printf("Exist(3,1) = %d \n",GraphExist(3,1,G));
   printf("InDegree(3) = %d \n",InDegree(3,G));
   printf("OutDegree(1) = %d \n",OutDegree(1,G));
   printf("���� %d \n",GraphEdges(G));
   return 0;
}

