/* ���������� */

#include <stdio.h>
#include <stdlib.h>
#include "treeitem.h"
#include "binary.h"
#include "huffman.h"
#include "setitem2.h"
#include "minheap.h"

BinaryTree HuffmanTree(int f[],int n)
{/* ������������ */
   Huffman x,y,*w=(Huffman *)malloc((n+1)*sizeof(Huffman));
   BinaryTree z, zero;
   zero=BinaryInit();
   for(int i=1;i<=n;i++){/* ���ɵ������ */
      z=BinaryInit();
      MakeTree(i,z,zero,zero);
      w[i].weight=f[i];
      w[i].tree=z;
    }
   /* �����ȶ��� */
   Heap Q=BuildHeap(w,n,n);
   /* �����ϲ���СƵ���� */
   for(int i=1;i<n;i++){
      x=DeleteMin(Q);
      y=DeleteMin(Q);
      z=BinaryInit();
      MakeTree(0,z,x.tree,y.tree);
      x.weight+=y.weight;x.tree=z;
      HeapInsert(x,Q);
   }
   x=DeleteMin(Q);
   return x.tree;
}

int main()
{
   BinaryTree x;
   int a[11];
   int n=10;
   for(int i=1;i<=n;i++)a[i]=2*i;
   x=HuffmanTree(a,n);
   PostOut(x);
   return 0;
}

/* out 
10 3 1 2 0 0 6 0 0 7 8 0 9 4 5 0 0 0 0  
*/
