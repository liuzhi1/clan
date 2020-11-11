#include <stdio.h> 

int main()
{
	int amount = 100; 
	int price = 0;
	
	
	printf(" ‰»Î:");
	scanf("%d",&price);
	
	printf(" ‰»Î∆±√Ê:");
	scanf("%d",&amount);
	
	int change = amount - price;
	
	printf("’“:%d\n",change);
	
	return 0;
}
