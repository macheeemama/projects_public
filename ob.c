#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>


void process( double *a, double *b, int n );

void process( double *a, double *b, int n )
{
	int i, j, k, p, q, k1, j1, r, w;
	double c, koef, koef1, koef2;
	for(i=0;i<n;i++) // начинаем строить треугольник
	{
		if(fabs(a[i*n+i])<1e-14)
		{
			for(k=i+1;k<n;k++) // находим строчку с !=0 
			{
				if(fabs(a[k*n+i])>1e-14)
				{
					for(j=i;j<n;j++) // переставляем строчки местами
					{
						c=a[i*n+j];
						a[i*n+j]=a[k*n+j];
						a[k*n+j]=c;
					}
				}
			}
		}
		for(k1=i+1;k1<n;k1++) // вычитаем из k-ой строки i-ую
		{
			koef=a[k1*n+i]/a[i*n+i];
			for(j1=0;j1<n;j1++)
			{
				a[k1*n+j1]=a[k1*n+j1]-a[i*n+j1]*koef; b[k1*n+j1]=b[k1*n+j1]-b[i*n+j1]*koef;
			}
		}
		printf("\n");
		printf("\n");
	}
	for(p=0;p<n;p++)
	{
		for(q=0;q<n;q++)
		{
			printf("%f ", b[p*n+q]);
		}	
		printf("\n");
	}
	printf("\n");printf("\n");
	for(i=0;i<n;i++)
	{
		koef1=a[i*n+i];
		for(j=0;j<n;j++)
		{
			if(fabs(a[i*n+j])>1e-14)
				a[i*n+j]=a[i*n+j]/koef1;
			if(fabs(b[i*n+j])>1e-14)
				b[i*n+j]=b[i*n+j]/koef1;
		}
	}
	for(p=0;p<n;p++)
	{
		for(q=0;q<n;q++)
		{
			printf("%f ", b[p*n+q]);
		}	
		printf("\n");
	}
	printf("\n");
	for(p=0;p<n;p++)
	{
		for(q=0;q<n;q++)
		{
			printf("%f ", a[p*n+q]);
		}	
		printf("\n");
	}
	printf("\n");
	for(i=n-1;i>=0;i--)
	{
		for(r=0;r<i;r++)
		{
			koef2=a[r*n+i];
			for(w=0;w<n;w++)
			{
				a[r*n+w]=a[r*n+w]-a[i*n+w]*koef2;
				b[r*n+w]=b[r*n+w]-b[i*n+w]*koef2;
			}
		}
	}
	for(p=0;p<n;p++)
	{
		for(q=0;q<n;q++)
		{
			printf("%f ", a[p*n+q]);
		}	
		printf("\n");
	}
}
					
				
		


		
int main(void)
{
	int i, j, n, k, kol=0;
	double *a, *b;
	double p;
	FILE *input, *output;
	input=fopen("C:/MinGW/progi/input.txt","r");
	output=fopen("C:/MinGW/progi/output.txt","w");
	if(input==NULL)
	{
		printf("File not found\n");
		return -1;
	}
	while(fscanf(input, "%lf", &p)==1)
	{
		kol++;
	}
	n=sqrt(kol);
	fclose(input);
	input=fopen("C:/MinGW/progi/input.txt","r");
	if(input==NULL)
	{
		printf("File not found\n");
		return -1;
	}
	a=(double*)malloc(kol*sizeof(double));
	b=(double*)malloc(kol*sizeof(double));
	k=0;
	while(fscanf(input,"%lf",&p)==1)
	{
		a[k]=p;
		k++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				b[i*n+j]=1;
			else b[i*n+j]=0;
		}
	}
	process(a, b, n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(output, "%f ", b[i*n+j]);
		}
		fprintf(output, "\n");
	}
	
	fclose(input);
	fclose(output);
	free(a);
	free(b);
	return 0;
}
