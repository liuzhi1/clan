#include <stdio.h>

int main()
{
	printf("�������Ӣ�ߺ�Ӣ��:");//��5,7��ʾ5Ӣ��7Ӣ��
	
	int foot; //double foot (2)
	int inch; //double inch  (2)
	
	scanf("%d %d",&foot, &inch);//%lf %lf  (2)
	
	printf("�����%f��\n",((foot + inch / 12)* 0.3048));
	//�Ľ���12��Ϊ12.0 (1) 
	return 0;
	 //�������� ���ֻ��������   10��10.0��ͬ  10.0Ϊ������ 
 } 
