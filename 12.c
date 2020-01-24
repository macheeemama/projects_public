#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
double* c1(double* a,int na,double* b,int nb,double* c);
int main(void)
{
	double* a;
	double* b;
	double* c;
	int kolA=0,kolB=0,kolC=0,k,i;
	double n;
	FILE *massA,*massB,*massC;
	massA=fopen("C:/MinGW/progi/12.1.txt","r");
	massB=fopen("C:/MinGW/progi/12.2.txt","r");
	massC=fopen("C:/MinGW/progi/12.3.txt","w");
	if((massA==NULL)&&(massB==NULL))
	{
		printf("Files not found :c \n");
		return -1;
	}
	while(fscanf(massA,"%lf",&n)==1)
	{
		kolA++;
	}
	fclose(massA);
	while(fscanf(massB,"%lf",&n)==1)
	{
		kolB++;
	}
	fclose(massB);
	massA=fopen("C:/MinGW/progi/12.1.txt","r");
	massB=fopen("C:/MinGW/progi/12.2.txt","r");
	if((massA==NULL)&&(massB==NULL))
	{
		printf("Files not found :c \n");
		return -1;
	}
	kolC=kolA+kolB;
	a=(double*)malloc(kolA*sizeof(double));
	b=(double*)malloc(kolB*sizeof(double));
	c=(double*)malloc(kolC*sizeof(double));
	k=0;
	while(fscanf(massA,"%lf",&n)==1)
	{
		a[k]=n;
		k++;
	}
	k=0;
	while(fscanf(massB,"%lf",&n)==1)
	{
		b[k]=n;
		k++;
	}
	c=c1(a,kolA,b,kolB,c);
	for(i=0;i<kolC;i++)
	{
		fprintf(massC,"%f\n",c[i]);
	}
	fclose(massA);
	free(a);
	fclose(massB);
	free(b);
	fclose(massC);
	free(c);
	return 0;
}
double* c1(double* a,int na,double* b,int nb,double* c)
{
	int nc,i=0,j=0,k=0;
	nc=na+nb;
	for(k=0;k<nc;k++)
	{
		if((i==na)&&(j<nb))
		{
			c[k]=b[j];
			j++;
		}
		if((j==nb)&&(i<na))
		{
			c[k]=a[i];
			i++;
		}
		if((i<na)&&(j<nb))
		{
			if(a[i]>=b[j])
			{
				c[k]=b[j];
				j++;
			}
			else 
			{
				c[k]=a[i];
				i++;
			}
		}
		printf("%d %d %f \n", i, j, c[k]);
	}
	return c;
}