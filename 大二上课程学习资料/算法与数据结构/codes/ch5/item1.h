/* ��Ȩ��λ����� */

typedef struct node{
    double element;/* Ԫ��ֵ */ 
    double weight;/* Ԫ��Ȩֵ */ 
} Node;

typedef Node Item;/* ��Ȩ��λ��������� */
typedef Item* addr;/* ��Ȩ��λ�����ָ������ */

#define key(A) (A.element)/* ���Ԫ��ֵ */
#define less(A,B) (key(A) < key(B))/* �����Ԫ��ֵ�Ƚ� */
#define eq(A,B) (!less(A,B) && !less(B,A))/* �����Ԫ��ֵ��� */
#define swap(A,B) { Item t=A; A=B; B=t; }/* ��㽻�� */
#define compswap(A,B) if(less(B,A)) swap(A,B)/* �ȽϺ��㽻�� */

void ItemShow(Item x)
{
   printf("%f \n", x.element);
}
