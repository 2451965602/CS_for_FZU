
#ifndef Make2DArray_
#define Make2DArray_

WItem **Make2DArray(int rows,int cols,WItem value)
{/* ������̬2ά���� */
    WItem **t=(WItem **)malloc(rows*sizeof(WItem *));
    for(int i=0;i<rows;i++)
      t[i]=(WItem *)malloc(cols*sizeof(WItem));
    for(int i=0;i<rows;i++)
       for(int j=0;j<cols;j++)t[i][j]=value;
    return t;
}

void Erase2D(WItem**t, int rows)
{/* ɾ����̬2ά���� */
   for(int i=0;i<rows;i++)free(t[i]);
   free(t);
}

#endif
