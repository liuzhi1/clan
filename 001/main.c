#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}

int array[5]={11,22,6,62,9};
int i;
int j;
int temp;
for( i=0,i<5,i++){
	for(j = 1,j<5,j++);
	{
		if(array[i]<array[j])
		{
			temp =array[j];
			array[i]=array[j];
			array[i]=temp;
		}
	}
}

for(i =0,i<5,i++)
{
	printf(" %d",array[i]);
	return 0;
}
