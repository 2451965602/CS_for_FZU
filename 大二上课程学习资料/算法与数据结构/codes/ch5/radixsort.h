
#define RADIX 10 //����

void  out(int a[],int l,int r)
{
    for(int i=l;i<=r;++i)printf("%3d ",a[i]);
    printf("\n");
}

void countsort(int a[],int b[],int l,int r,int p)
{/* ��λ�������� */
    int cnt[RADIX]={0};/* ���Ͱ������ */
    for(int i=l;i<=r;i++)cnt[a[i]/p%RADIX]++;/* Ͱ���� */
    /* cnt[i]�д�ŵ���a[l,r]�м�ֵpλ����i��Ԫ�ظ��� */
    for(int i=1;i<RADIX;i++)cnt[i]+=cnt[i-1];
    /* cnt[i]�д�ŵ���a[l,r]�м�ֵpλС�ڻ����i��Ԫ�ظ��� */
    for(int i=r;i>=l;i--)b[--cnt[a[i]/p%RADIX]]=a[i];
    /* ��дa[l,r] */
    for(int i=l;i<=r;i++)a[i]=b[i-l];
}

void RadixSort(int a[],int n)
{
	int maxv=0,pow=1;
	int *b=(int *)malloc(sizeof(int)*(n+1));
	for(int i=0;i<n;i++)if(a[i]>maxv)maxv=a[i];
	/* maxv ��a���������������ȷ��whileѭ���Ĵ��� */
	while(maxv/pow>0){
		int cnt[RADIX]={0};/* ���Ͱ������ */
		for(int i=0;i<n;i++)cnt[a[i]/pow%RADIX]++;/* Ͱ���� */
        for(int i=1;i<RADIX;i++)cnt[i]+=cnt[i-1];/* ǰ׺�� */
		/* ����Ͱλ������ */
		for(int i=n-1;i>=0;i--)b[--cnt[a[i]/pow%RADIX]]=a[i];
        for(int i=0;i<n;i++)a[i]=b[i];/* ��дa */
        pow*=RADIX;/* ��λ */
	}
    free(b);
}

void RadixSort1(int a[],int l,int r)
{
    int maxv=0,pow=1;
    int *b=(int *)malloc(sizeof(int)*(r+1));
    for(int i=l;i<=r;i++)if(a[i]>maxv)maxv=a[i];
    /* maxv ��a[l,r]���������������ȷ��whileѭ���Ĵ��� */
    while(maxv/pow>0){
       int cnt[RADIX]={0};/* ��ռ����� */
       for(int i=l;i<=r;i++)cnt[a[i]/pow%RADIX]++;/* ��λ���� */
       for(int i=1;i<RADIX;i++)cnt[i]+=cnt[i-1];/* ǰ׺�� */
       /* ��λ���� */
       for(int i=r;i>=l;i--)b[--cnt[a[i]/pow%RADIX]]=a[i];
       for(int i=l;i<=r;i++)a[i]=b[i-l];/* ��дa */
       pow*=RADIX;/* ��λ */
    }
    free(b);
}

void RadixSort(int a[],int l,int r)
{
    int maxv=0,pow=1;
    int *b=(int *)malloc(sizeof(int)*(r+1));
    for(int i=l;i<=r;i++)if(a[i]>maxv)maxv=a[i];
    /* maxv ��a[l,r]���������������ȷ��whileѭ���Ĵ��� */
    while(maxv/pow>0){
        countsort(a,b,l,r,pow);/* ��λ�������� */
        pow*=RADIX;/* ��λ */
    }
    free(b);
}

void sort(int a[],int l,int r)
{
    RadixSort(a,l,r);
    //out(a,l,r);
}

void sort(int a[],int n)
{
    //RadixSort(a,n);
    RadixSort(a,0,n-1);
}
