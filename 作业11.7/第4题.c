#include <stdio.h>
#include <stdlib.h>

void xtod(int x);
int main()
{
	int i;
	scanf("%x",&i);
	xtod(i);
	system("pause");
	return 0;
}
void xtod(int x)
{ 
	printf("%d\n",x); 
} 
