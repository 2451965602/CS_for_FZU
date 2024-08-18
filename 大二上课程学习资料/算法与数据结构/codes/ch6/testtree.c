/* ���Զ����� */

#include <stdio.h>
#include <stdlib.h>
#include "treeitem.h"
#include "binary.h"

int main()
{
   BinaryTree a,x,y,z;

   a=BinaryInit();
   x=BinaryInit();
   y=BinaryInit();
   z=BinaryInit();

   MakeTree(1,y,a,a);
   MakeTree(2,z,a,a);
   MakeTree(3,x,y,z);
   MakeTree(4,y,x,a);

   printf("ǰ���б� \n");
   PreOut(y);
   printf("�����б� \n");
   InOut(y);
   printf("�����б� \n");
   PostOut(y);
   printf("�����б� \n");
   LevelOut(y);

   printf("����� %d\n",Size(y->root));
   printf("����� %d\n",Size1(y->root));
   printf("�߶� %d\n",Height(y->root));

   count=0;
   PreOrder(Add1, y->root);
   printf("count= %d\n",count);
   return 0;
}
