#include <stdio.h>
#include <math.h>

float fun(double a,double b,double c,double d)
{
	float x0=2.0;
	float x;
	x=x0-((a*pow(x0,3)+b*pow(x0,2)+c*x0+d)/(a*pow(x0,3)+b*pow(x0,2)+x0+d));
	return x;
 } 
int main()
{
	float a,b,c,d;
	printf("«Î ‰»Îabcdµƒ÷µ:\n");
	scanf("%f %f %f %f",&a,&b,&c,&d);
	printf("%f",fun(a,b,c,d));
}
