#include <stdio.h>

int flag(int year)
{
	int a=0;
	if( year%4==0)
	a=1;
	return a;
}
int date(int mon,int day)
{
	int a=0;
	int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	for(i=0;i<mon-1;i++)	
	a=a+b[i];
	a=a+day;
	return a;
}
int main()
{
	int year,mon,day,sum,d;
	printf("输入日期:\n");
	scanf("%d%d%d",&year,&mon,&day);
	sum=date (mon,day);
	d=flag(year);
	if(mon>=3&&d==1)
	sum++;
	printf("%d年%d月%d日是这一年的第%d天\n",year,mon,day,sum);
}


