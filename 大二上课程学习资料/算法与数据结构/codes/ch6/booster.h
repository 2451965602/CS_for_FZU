/* booster �ṹ */ 
typedef struct booster{
    int D,/* Ҷ����ź�˥���� */
        d;/* ������ź�˥���� */
    int boost;/* �ź���ǿװ�ñ�־ */
}Booster;

void showboost(Booster x)
{
    printf("%  d   %d   %d \n", x.boost,x.D,x.d);
}

/*
D(i)=0��
for(i��ÿһ���ӽ��j){
    if(D(j)+d(j))>tolerence)�ڽ��j����һ���ź���ǿװ��;
    else D(i)=max(D(i),D(j)+d(j));
}
*/
