/* ��ʵ�ֲ��鼯 */

typedef struct ufset *UFset;/* ���鼯ָ������ */
typedef struct ufset{/* ���鼯�ṹ */
      int *parent;/* ��������� */
}UFS;

UFset UFinit(int size)
{/* ��ʼ���ɵ�Ԫ�ؼ��� */
   UFset U=(UFset)malloc(sizeof *U);
   U->parent=(int *)malloc((size+1)*sizeof(int));
   for(int e=1;e<=size;e++)
      U->parent[e]=0;
   return U;
}

int UFunion(int i,int j,UFset U)
{/* �ϲ����� */
   U->parent[j]=i;
   return i;
}

int UFfind(int e,UFset U)
{/* �ҳ�����Ԫ��e�ļ��� */
   while(U->parent[e])e=U->parent[e];/* ���� */ 
   return e;
}

