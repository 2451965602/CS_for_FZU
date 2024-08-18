/* ��ɢ�б� */
/* 
ʹ��ʱǰ����� 
#include "setitem.h"
#include "hash.h"
*/

#ifndef HashTable_
#define HashTable_

typedef struct hashtable *HashTable;
typedef struct hashtable{
      int size;/* Ͱ�����С */
      int (*hf)(SetItem x);/* ɢ�к��� */
      SetItem *ht;/* Ͱ���� */
      int *state;/* ռ��״̬���� */
}Hashtable;

HashTable HTInit(int div, int(*hashf)(SetItem x))
{/* ����һ����ɢ�б� */
   HashTable H=(HashTable)malloc(sizeof *H);
   H->size=div;
   H->hf=hashf;
   H->ht=(SetItem *)malloc(H->size*sizeof(SetItem));
   H->state=(int *)malloc(H->size*sizeof(int));
   for (int i=0;i<H->size;i++)H->state[i]=1;
   return H;
}

int HashProb(int i)
{/* ����̽�� */
   return i;
}

int FindMatch(SetItem x,HashTable H)
{/* ��Ͱ�����в��Ҵ洢Ԫ��x��λ�û�����Ͱ */
    int j=(*H->hf)(x);/* ��ʼͰ */
    for(int i=0;i<H->size;i++){
        int k=(j+HashProb(i))%H->size;
        if(H->state[k]==1)break;
        if(!H->state[k] && eq(H->ht[k],x))return k;
    }
    return H->size;
}

int Unoccupied(SetItem x,HashTable H)
{/* Ͱ�����пɴ洢Ԫ��x��δռ��Ͱ��Ԫλ�� */
   int j=(*H->hf)(x);/* ��ʼͰ */
   for(int i=0;i<H->size;i++){
        int k=(j+HashProb(i))%H->size;
        if(H->state[k])return k;
    }
    return H->size;
}

int HTMember(SetItem x,HashTable H)
{/* ��Ա��ѯ */
    int i=FindMatch(x,H);
    if(i<H->size && eq(H->ht[i],x))return 1;
    return 0;
}

void HTInsert(SetItem x,HashTable H)
{/* ����Ԫ�� */
   if(HTMember(x,H))return;
   int i=Unoccupied(x,H);/* Ͱ�����еĿɲ���λ�� */
   if(i<H->size){/* �ɲ��� */
       H->state[i]=0;
       H->ht[i]=x;
   }
   else return;
}

void HTDelete(SetItem x,HashTable H)
{/* ɾ��Ԫ�� */
   int i=FindMatch(x,H);
   if(i<H->size && H->ht[i]==x)H->state[i]=2;
}

void HTDelete1(SetItem x,HashTable H)
{/* ��䱻ɾ��Ԫ���ͷŵ�Ͱ�ռ� */
    int j,i=FindMatch(x,H);
    if(i<H->size && H->ht[i]==x)
        for(;;){
            H->state[i]=1;
            for(j=(i+1)%H->size;!H->state[j];j=(j+1)%H->size){
                int k=(*H->hf)(H->ht[j]);
                if((k<=i && i<j)||(i<j && j<k)||(j<k && k<=i))break;
            }
            if(H->state[j])break;
            H->ht[i]=H->ht[j];
            H->state[i]=H->state[j];
            i=j;
        }
}
 
void HTOutput(HashTable H)
{
   for(int i=0;i<H->size;i++){
      if(H->state[i]==1)printf("��Ͱ ");
      else if(H->state[i]==2)printf("��ɾ�� ");
      else SetItemShow(H->ht[i]);
    }
}

#endif
