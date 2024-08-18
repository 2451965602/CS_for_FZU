/* С���ϲ������� */
#include<iostream>
using namespace std;

typedef struct ufset *UFset;/* ���鼯ָ������ */
typedef struct ufset{/* ���鼯�ṹ */
      int *parent;/* ��������� */
      int *root;/* ��������� */
}UFS;

UFset UFinit(int size)
{/* ��ʼ���ɵ�Ԫ�ؼ��� */
   UFset U=(UFset)malloc(sizeof *U);
   U->parent=(int *)malloc((size+1)*sizeof(int));
   U->root=(int *)malloc((size+1)*sizeof(int));
   for(int e=0;e<=size;e++){
      U->parent[e]=1;
      U->root[e]=1;
   }
   return U;
}

void UFfree(UFset U)
{/* �ͷſռ� */
   free(U->parent);
   free(U->root);
   free(U);
}

int UFunion(int i,int j,UFset U)
{/* �ϲ����� */
   if(i==j)return i;
   if(U->parent[i]<U->parent[j]){
      /* i ��Ϊ j ������ */
      U->parent[j]+=U->parent[i];
      U->root[i]=0;
      U->parent[i]=j;
      return j;
   }
   else{/* j ��Ϊ i ������ */
      U->parent[i]+=U->parent[j];
      U->root[j]=0;
      U->parent[j]=i;
      return i;
   }
}

int UFfind(int e, UFset U)
{/* �ҳ�����Ԫ��e�ļ��� */
   while(!U->root[e])e=U->parent[e];/* ���� */ 
   return e;
}

int UFsize(int e, UFset U)
{/* �ҳ�����Ԫ��e�ļ��� */
   while(!U->root[e])e=U->parent[e];/* ���� */ 
   return U->parent[e];
}

int UFfind1(int e,UFset U)
{/* �ҳ�����Ԫ��e�ļ��� */
   int i,j=e;
   while(!U->root[j])j=U->parent[j];/* ���� */ 
   while(j!=e){/* ·��ѹ�� */
     i=U->parent[e];
     U->parent[e]=j;
     e=i;
   }
   return j;
}

