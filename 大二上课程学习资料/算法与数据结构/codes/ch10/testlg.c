/* �����ڽӱ�ʵ������ͼ */

#include <stdio.h>
#include <stdlib.h>
#include "lgraph.h"

int main()
{
   Graph G=Graphinit(4);
   printf("���� %d \n",GraphEdges(G));

   GraphAdd(2,4,G);
   GraphAdd(1,3,G);
   GraphAdd(2,1,G);
   GraphAdd(1,4,G);
   GraphAdd(3,2,G);

   printf("����ͼ \n");

   GraphOut(G);
   GraphDelete(3,1,G);

   printf("ɾ�� <3,1> \n");

   GraphOut(G);

   printf("Exist(3,1)=%d \n",GraphExist(3,1,G));
   printf("Degree(2)=%d \n",Degree(2,G));
   printf("���� %d \n",GraphEdges(G));
   return 0;
}

