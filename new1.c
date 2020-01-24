#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int mesto(double *a,double x,int n);
int main(void)
{
        double* a;
        int m,kol,k=0;
        double x,n;
        FILE *pfile;
        pfile=fopen("C:/MinGW/progi/mass.txt","r");
        if(pfile==NULL)
        {
        printf("File not found\n");
                return -1;
        }
        fscanf(pfile,"%d",&kol);
        a=(double*)malloc(kol*sizeof(double));
        while(fscanf(pfile,"%lf",&n)==1)
        {
                a[k]=n;
                k++;
        }
        scanf("%lf",&x);
        m=mesto(a,x,kol);
        printf("na %d meste\n",m+2);
        fclose(pfile);
        free(a);
        return 0;
}
int mesto(double *a,double x,int n)
{
        int i,p=0;
        for(i=0; i<n; i++)
        {
                if((!(a[i]>x))&&(!(a[i]<x)))
                p=i;
        }
        return p;
}