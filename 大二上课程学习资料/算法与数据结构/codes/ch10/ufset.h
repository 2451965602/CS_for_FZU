/* ����ʵ�ֲ��鼯 */

typedef struct ufset *UFset;/* ���鼯ָ������ */
typedef struct ufset{/* ���鼯�ṹ */
      int *components;/* Ԫ�������Ӽ���ϵ���� */
      int n;/* ������Ԫ�ظ��� */
}UFS;

UFset UFinit(int size)
{/* ��ʼ���ɵ�Ԫ�ؼ��� */
   UFset U=(UFset)malloc(sizeof *U);
   U->components=(int *)malloc((size+1)*sizeof(int));
   for(int e=1;e<=size;e++)
      U->components[e]=e;
   U->n=size;
   return U;
}

int UFunion(int i,int j,UFset U)
{/* �ϲ����� */
   for(int k=1;k<=U->n;k++)
      if(U->components[k]==j)U->components[k]=i;
   return i;
}

int UFfind(int e,UFset U)
{/* �ҳ�����Ԫ��e�ļ��� */
    return U->components[e];
}

