#include <stdio.h> 

int main()
{
	const int AMOUNT = 100;//constΪһ�����η������޸� 
	int price = 0;
	
	AMOUNT=90// �ı�ͱ��� 
	
	printf("����:");
	scanf("%d",&price);
	
	int change = AMOUNT - price;
	
	printf("��%d\n",change);
	
	return 0;
}
