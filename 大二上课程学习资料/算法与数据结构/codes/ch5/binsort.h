/* Ͱ�����㷨 */
/* 
ʹ��ʱǰ����� 
#include "item.h"
#include "binsort.h"
*/

#include "node.h"

#define m 10000

link binsort(link first)
{/* Ͱ�����㷨 */
    int  b;/* Ͱ�±� */
    link bottom[m+1],top[m+1];
    link p=0;
    for(b=0;b<=m;b++)bottom[b]=0;/* Ͱ��ʼ�� */
    for(;first;first=first->next){/* ��Ԫ��װ��Ͱ�� */
       b=first->element;
       if(bottom[b]){/* Ͱ�ǿ� */
         top[b]->next=first;
         top[b]=first;}
       else bottom[b]=top[b]=first;/* Ͱ�� */
    }
    /* ��Ͱ��˳��Ͱ��Ԫ��˳��������һ�� */
    for(b=0;b<=m;b++)
       if(bottom[b]){/* Ͱ�ǿ� */
          if(p)p->next=bottom[b];/* ���ǵ�һ���ǿ�Ͱ */
          else first=bottom[b];/* ��һ���ǿ�Ͱ */
          p=top[b];
       }
    if(p)p->next=0;
    return first;
}


