// ��·����

#include <stdio.h>
#include <stdlib.h>
#include "qitem2.h"
#include "lqueue.h"
#include "make2db.h"

int **g,n,m;

void Input(Pos a, Pos b)
{
    int k;
    scanf("%d",&n);
    scanf("%d",&m);
    g=malloc2d(n+2,m+2);
    scanf("%d",&a->row);
    scanf("%d",&a->col);
    scanf("%d",&b->row);
    scanf("%d",&b->col);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++){
            scanf("%d",&k);
            g[i][j]=k;
        }
}

void Output(int Len,Pos *path)
{
    for(int i=0;i<Len;i++)
      printf("%d %d\n",(path[i])->row,(path[i])->col);
}

int Search(Pos a,Pos b,Pos *path)
{ /* �������ʼλ��a��Ŀ��λ��b����̲���·��
     �ҵ���̲���·���򷵻����·��,���򷵻�0  */
    Pos off[4];/* ���λ�� */
    Queue Q;/* �����췽����� */
    Q=QueueInit();
    if((a->row==b->row) && (a->col==b->col))return 0;/* a=b */
    /* ���÷�������Χǽ */
    for(int i=0;i<=m+1;i++)g[0][i]=g[n+1][i]=1;/* �����͵ײ� */
    for(int i=0;i<=n+1;i++)g[i][0]=g[i][m+1]=1;/* ��������� */
    /* ��ʼ�����λ�� */
    for(int i=0;i<4;i++)off[i]=NewPos();
    off[0]->row=0;off[0]->col=1;/* �� */
    off[1]->row=1;off[1]->col=0;/* �� */
    off[2]->row=0;off[2]->col=-1;/* �� */
    off[3]->row=-1;off[3]->col=0;/* �� */
    int k=4;/* ���ڷ����� */
    Pos nbr,cur=NewPos();
    cur->row=a->row;
    cur->col=a->col;
    g[a->row][a->col]=2;
    /* ��ǿɴ﷽��λ�� */
    while(1){/* ��ǿɴ����ڷ��� */
       for(int i=0;i<k;i++){
         nbr=NewPos();
         nbr->row=cur->row+off[i]->row;
         nbr->col=cur->col+off[i]->col;
         if(g[nbr->row][nbr->col]==0){
            /* �÷���δ��� */
            g[nbr->row][nbr->col]=g[cur->row][cur->col]+1;
            if((nbr->row==b->row)&&(nbr->col==b->col))break; /* ��ɲ��� */
            EnterQueue(nbr,Q);
         }
       }
       /* �Ƿ񵽴�Ŀ��λ��b? */
       if((nbr->row==b->row)&&(nbr->col==b->col))break; /* ��ɲ��� */
       /* �����췽������Ƿ�ǿ� */
       if(QueueEmpty(Q))return 0; /* �޽� */
       cur=DeleteQueue(Q); /* ȡ��һ�����췽�� */
    }
    /* ������̲���·�� */
    int len=g[b->row][b->col] - 2;
    for(int i=0;i<len;i++)path[i]=NewPos();
    cur=b;/* ��Ŀ��λ��b��ʼ����ʼλ�û��� */
    for(int j=len-1;j>=0;j--){
        path[j]=cur;
        /* ��ǰ��λ�� */
        for(int i=0;i<k;i++){
            nbr=NewPos();
            nbr->row=cur->row+off[i]->row;
            nbr->col=cur->col+off[i]->col;
            if(g[nbr->row][nbr->col]==j+2)break;
        }
        cur=nbr;/* ��ǰ�ƶ� */
    }
    return len;
}

int main()
{
   Pos s,f,*p;
   s=(Pos)malloc(sizeof(*s));
   f=(Pos)malloc(sizeof(*f));
   Input(s,f);

   printf("n=%d\n",n);
   printf("m=%d\n",m);

   printf("%d  ",s->row);
   printf("%d  ",s->col);
   printf("%d  ",f->row);
   printf("%d\n",f->col);

   p=(Pos *)malloc(n*m*sizeof(Pos));

   Output(Search(s,f,p),p);
   return 0;
}

/* test.in
7 7
3 2
4 6
0 0 1 0 0 0 0
0 0 1 1 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 0 0
1 0 0 0 1 0 0
1 1 1 0 0 0 0
1 1 1 0 0 0 0
*/

/* test.out
n=7
m=7
3  2  4  6
4 2
5 2
5 3
5 4
6 4
6 5
6 6
5 6
4 6
*/ 
