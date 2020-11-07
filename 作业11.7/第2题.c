#include <stdio.h>

int f(int x)
{
	if(x==(x/100)*(x/100)*(x/100)+(x%100/10)*(x%100/10)*(x%100/10)+(x%10)*(x%10)*(x%10))
	printf("%d",x);
	
}
main ()
{
	int m; 
	scanf("%d",&m);
	f(m);
}

