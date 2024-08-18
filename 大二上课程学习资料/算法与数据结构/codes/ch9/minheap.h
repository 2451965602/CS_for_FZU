/* ��С���� */
/* 
ʹ��ʱǰ����� 
#include "setitem.h"
#include "minheap.h"
*/

#ifndef MinHeap_
#define MinHeap_

typedef struct minheap *Heap;/* ��С����ָ������ */
typedef struct minheap {/* ��С���� */
      int last,/* ���һ����Ԫ */ 
          maxsize;/* ���������󳤶� */ 
      SetItem *heap;/* Ԫ������ */
}Minheap;

Heap MinHeapInit(int HeapSize)
{/* ����һ���ն� */
   Heap H=(Heap)malloc(sizeof *H);
   H->maxsize=HeapSize;
   H->heap=(SetItem *)malloc((H->maxsize+1)*sizeof(SetItem));
   H->last=0;
   return H;
}

int HeapSize(Heap H)
{/* �ѵĴ�С */ 
   return H->last;
}

SetItem HeapMin(Heap H)
{/* ������СԪ */ 
    if(H->last==0)return 0;/* �ն� */
    else return H->heap[1];/* ������СԪ */
}

void HeapInsert(SetItem x,Heap H)
{/* �Ѳ������� */
   if(H->last==H->maxsize)return;/* ������ */
   /* �Ӷѵ׿�ʼ����Ԫ��x�Ĳ���λ�� */
   int i=++H->last;
   while(i!=1 && less(x,H->heap[i/2])){
        H->heap[i]=H->heap[i/2];/* Ԫ������ */
        i/=2;/* �������� */
    }
    H->heap[i]=x;
}

SetItem DeleteMin(Heap H)
{/* ��ȡ������СԪ */ 
   if(H->last==0)return 0;/* ���ѿ� */;
   SetItem x=H->heap[1];/* ������СԪ */
   /* �ع��� */
   SetItem y=H->heap[H->last--]; /* �������һ��Ԫ�� */
   /* �ӶѶ���ʼ����Ԫ��y��λ�� */
   int i=1, /* �ѵĵ�ǰλ�� */
       ci=2; /* i�Ķ��ӽ���ڶ���λ�� */
   while(ci<=H->last){ /* ����y�Ĳ���λ�� */
      if(ci<H->last && less(H->heap[ci+1],H->heap[ci]))ci++;
      /* ����heap[i]������� */ 
      if(!less(H->heap[ci],y))break;/* �ɲ��� */ 
      /* ���ɲ��� */ 
      H->heap[i]=H->heap[ci];/* ���ӽ������ */
      i=ci;/* ��ǰ����½� */
      ci*=2;
   }
   H->heap[i]=y;
   return x;
}

Heap BuildHeap(SetItem a[],int size,int arraysize)
{/* ������a����Ϊһ���� */
   Heap H=MinHeapInit(arraysize);
   H->heap=a;
   H->last=size;
   H->maxsize=arraysize;
   for(int i=H->last/2;i>=1;i--){
      SetItem y=H->heap[i]; /* �Ѷ� */ 
      /* ����y��λ�� */
      int c=2*i; /* ���i������ӽ�� */
      while(c<=H->last){
         if(c<H->last &&  less(H->heap[c+1],H->heap[c]))c++;
         /* ����heap[c/2]������y�� */
         if(!less(H->heap[c],y))break;/* �ɲ��� */ 
         /* ���ɲ��� */
         H->heap[c/2]=H->heap[c];/* heap[c]���� */
         c*=2;/* ��ǰ���c�½� */
      }
      H->heap[c/2]=y;
   }
   return H;
}

void HeapOut(Heap H)
{/* ����� */
   for(int i=1;i<=H->last;i++)printf("  %d",H->heap[i]);
   printf( "\n");
}

void HeapSort(SetItem a[],int n)
{/* �������㷨 */
   Heap H=BuildHeap(a,n,n);/* ����ʼ�� */
   /* �Ӷ�����γ�ȡ��СԪ */
   for(int i=n-1;i>=1;i--){
      SetItem x=DeleteMin(H);
      a[i+1]=x;
   }
}

#endif
