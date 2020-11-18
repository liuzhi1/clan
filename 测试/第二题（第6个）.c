#include <stdio.h>

int main()
{
	int a,b=0,i;
	printf("输入10个数字");
	for(i=0;i<=10;i++);
	{
		scanf("%d",&a);
		if(a%2==0);
			b++;
	}
	printf("偶数%d 奇数%d",b,10-b);
}
