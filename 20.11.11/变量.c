#include <stdio.h> 

int main()
{
	const int AMOUNT = 100;//const为一个修饰符表不能修改 
	int price = 0;
	
	AMOUNT=90// 改变就报错 
	
	printf("输入:");
	scanf("%d",&price);
	
	int change = AMOUNT - price;
	
	printf("找%d\n",change);
	
	return 0;
}
