#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
	int i;
	FILE *si, *co;
	si=fopen("C:/MinGW/progi/sin.txt","w");
	co=fopen("C:/MinGW/progi/cos.txt","w");
	for(i=0;i<100;i++)
	{
		fprintf(si, "%f,%f", i*2*pi/100, sin(i*2*pi/100));
		fprintf(co, "%f,%f", i*2*pi/100, cos(i*2*pi/100));
	}
	fclose(si);
	fclose(co);
	return 0;
