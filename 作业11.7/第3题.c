#include <stdio.h>

int main()
{
	int prime(int n);
	int x;
	printf("������Ҫ�жϵ�����:");
	scanf_s("%d",&x);
	prime(x);
	printf("\n");
	return 0;
}
int prime(int n)
{
	int i;
	int a=0;
	if(n<2)
		printf("%d��������\n",n);
	else
	{
		for (i = 2; i<n; i++)
		{
			if(n%i==0)
				a++;
		}
		if(a==0)
			printf("%d������\n",n);
		else
			printf("%d��������\n",n);
	 } 
	 
	 return 0;
}
