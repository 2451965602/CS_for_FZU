// ���ϵĵȼ��໮���㷨

#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
#include "chain.h"
#include "stackitem.h"
#include "lstack.h"

void equiv()
{
    int a,b,n,r,*q,*out;
    Stack stack=StackInit();
    scanf("%d",&n);/* ���뼯����Ԫ�ظ��� */
    scanf("%d",&r);/* ����ȼ��������� */
    /* Ϊ������ÿ��Ԫ�ؽ���һ������ */
    List *L=(List *)malloc((n+1)*sizeof(*L));
    for(int i=1;i<=n;i++)L[i]=ListInit();
    /* ˳���������ȼ������� */
    for(int i=1;i<=r;i++){
        scanf("%d%d",&a,&b);/* ����ȼ������� */
        ListInsert(0,b,L[a]);
        ListInsert(0,a,L[b]);
    }
    /* ��������д����ҳ����������ĵȼ۹�ϵ */
    out=(int *)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)out[i]=0;
    /* ����ȼ��� */
    for(int i=1;i<=n;i++)
        if(!out[i]){/* �µȼ��� */
            printf("�ȼ���: %d ",i);
            out[i]=1;
            Push(i,stack);
            /* ��ջ��ȡ�ȼ�����Ԫ�� */
            while(!StackEmpty(stack)) {
                int j=Pop(stack);
                /* L[j] ��Ԫ������ͬһ�ȼ��� */
                IterInit(L[j]);  /* �����α� */
                q=CurrItem(L[j]);
                b=ListLength(L[j]);
                for(a=1;a<=b;a++){
                    if(!out[*q]) {  /* q����ͬһ�ȼ��� */ 
                       StackShow(*q);
                       out[*q]=1;
                       Push(*q,stack);
                    }
                    IterNext(L[j]);
                    q=CurrItem(L[j]);
                }
            }
            printf("\n");
        }/* endif */
}

int main()
{
    equiv();
    return 0;
}

/* test.in 
10
7
1 6
2 5
4 1
9 2
7 10
8 5
7 9
*/

/* test.out

�ȼ���: 1 4 6 
�ȼ���: 2 9 5 8 7 10 
�ȼ���: 3 
*/
