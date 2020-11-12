#include <stdio.h>

int main()
{
	printf("输入身高英尺和英寸:");//如5,7表示5英尺7英寸
	
	int foot; //double foot (2)
	int inch; //double inch  (2)
	
	scanf("%d %d",&foot, &inch);//%lf %lf  (2)
	
	printf("身高是%f米\n",((foot + inch / 12)* 0.3048));
	//改进将12改为12.0 (1) 
	return 0;
	 //整数运算 结果只能是整数   10与10.0不同  10.0为浮点数 
 } 
