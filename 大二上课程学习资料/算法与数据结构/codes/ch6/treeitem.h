/* ��Ԫ������ */
typedef int TreeItem;/* ��Ԫ������ */
typedef TreeItem* Treeaddr;/* ��Ԫ��ָ������ */

void TreeItemShow(TreeItem x)
{
   printf("%d \n", x);
}

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {TreeItem t=A;A=B;B=t;}
#define compswap(A,B) if(less(B,A))swap(A,B)
