/* �����ڽӾ���ʵ������ͼ */

#include <stdio.h>
#include <stdlib.h>
#include "adigraph.h"

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
   GraphDelete(1,3,G);

   printf("ɾ�� <1,3> \n");

   GraphOut(G);

   printf("Exist(3,1) = %d \n",GraphExist(3,1,G));
   printf("InDegree(3) = %d \n",InDegree(3,G));
   printf("OutDegree(1) = %d \n",OutDegree(1,G));
   printf("���� %d \n",GraphEdges(G));
   return 0;
}

