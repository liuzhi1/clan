#include <stdio.h> 

int main()
{
	int amount = 100; 
	int price = 0;
	
	
	printf("����:");
	scanf("%d",&price);
	
	printf("����Ʊ��:");
	scanf("%d",&amount);
	
	int change = amount - price;
	
	printf("��:%d\n",change);
	
	return 0;
}
