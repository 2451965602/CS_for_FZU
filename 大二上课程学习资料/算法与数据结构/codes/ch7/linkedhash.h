/* ��ɢ�б� */
/* 
ʹ��ʱǰ����� 
#include "setitem.h"
#include "linkedhash.h"
*/

#ifndef HASH_TABLE_CLASS
#define HASH_TABLE_CLASS

#include "listitem.h"
#include "cchain.h"

typedef struct open *OpenHashTable;/* ��ɢ�б� */
typedef struct open{
      int size;/* Ͱ����Ĵ�С */
      int(*hf)(SetItem x);/* ɢ�к��� */
      List *ht;/* Ͱ���� */
}Open;

OpenHashTable HTInit(int nbuckets,int(*hashf)(SetItem x))
{/* �����տ�ɢ�б� */
   OpenHashTable H=(OpenHashTable)malloc(sizeof *H);
   H->size=nbuckets;
   H->hf=hashf;
   H->ht=(List *)malloc(H->size*sizeof(List));
   for(int i=0;i<H->size;i++)
      H->ht[i]=ListInit();
   return H;
}

int HTMember(SetItem x,OpenHashTable H)
{/* ��Ա��ѯ */
   int i=(*H->hf)(x)%H->size;
   return(ListLocate(x,H->ht[i])>0);
}

void HTInsert(SetItem x,OpenHashTable H)
{/* ����Ԫ�� */
   if(HTMember(x,H))return;
   int i=(*H->hf)(x)%H->size;
   ListInsert(0,x,H->ht[i]);
}

void HTDelete(SetItem x,OpenHashTable H)
{/* ɾ��Ԫ�� */
   int i,k;
   i=(*H->hf)(x)%H->size;
   if(k=ListLocate(x,H->ht[i]))ListDelete(k,H->ht[i]);
}

void HTOutput(OpenHashTable H)
{
    for(int i=0;i<H->size;i++){
        printf("i= %d\n",i);
        PrintList(H->ht[i]);
        printf("\n");
    }
}

#endif 
