# include <stdio.h>

int fun1(int m,int n)
{
	int t;
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}
		while(n!=0);
		{
			t=m%n;
			m=n;
			n=t;
		}	
	return m;
}
	int fun2(int m,int n)
{
	int t;
	t=m*n/fun1(m,n);
	return t;
}
int main()
{
	int m,n;
	printf("����������������:\n");
	scanf("%d%d",&m,&n);
	printf("%d��%d�����Լ��Ϊ:&d\n",m,n,fun1(m,n));
	printf("%d��%d����С��Լ��Ϊ:%d\n",m,n,fun2(m,n));
}
		
 
