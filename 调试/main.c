#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i=0;
	int a;
	for(a=0;a<1000;a++)
	{  	i=i+2;
	    printf("转圈圈拍掌次数: %d \n",i);
	}
	printf("转圈圈拍掌次数: %d \n",i);
	return 0;
}
