#include <stdio.h>
#include <malloc.h>
#include <math.h>
int main(void)
{
	int k=0,n,i=0,m,j,p,polozh=0,otric=0;
	int *x,*y;
	FILE *pfile;
	pfile=fopen("C:/MinGW/progi/tochki.txt","r");
	if(pfile==NULL)
	{
		printf("File not found\n");
            return -1;
    }
	while(fscanf(pfile,"%d",&n)==1)
	{
		k++;
	}
	fclose(pfile);
	pfile=fopen("C:/MinGW/progi/tochki.txt","r");
	if(pfile==NULL)
	{
		printf("File not found\n");
            return -1;
    }
	x=(int*)malloc((k/2)*sizeof(int));
	y=(int*)malloc((k/2)*sizeof(int));
	while(fscanf(pfile,"%d%d",&n,&m)==2)
	{
		x[i]=n;
		y[i]=m;
		i++;
	}
	for(j=1;j<i-1;j++)
	{
		if((((x[j-1]-x[j])*(y[j+1]-y[j])-(y[j-1]-y[j])*(x[j+1]-x[j]))/(sqrt((x[j-1]-x[j])*(x[j-1]-x[j])+(y[j-1]-y[j])*(y[j-1]-y[j]))*sqrt((x[j+1]-x[j])*(x[j+1]-x[j])+(y[j+1]-y[j])*(y[j+1]-y[j]))))>=0)
			polozh++;
		if((((x[j-1]-x[j])*(y[j+1]-y[j])-(y[j-1]-y[j])*(x[j+1]-x[j]))/(sqrt((x[j-1]-x[j])*(x[j-1]-x[j])+(y[j-1]-y[j])*(y[j-1]-y[j]))*sqrt((x[j+1]-x[j])*(x[j+1]-x[j])+(y[j+1]-y[j])*(y[j+1]-y[j]))))<0)
			otric++;
	}
	if((((x[i-1]-x[0])*(y[1]-y[0])-(y[i-1]-y[0])*(x[1]-x[0]))/(sqrt((x[i-1]-x[0])*(x[i-1]-x[0])+(y[i-1]-y[0])*(y[i-1]-y[0]))*sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]))))>=0)
		polozh++;
	if((((x[i-1]-x[0])*(y[1]-y[0])-(y[i-1]-y[0])*(x[1]-x[0]))/(sqrt((x[i-1]-x[0])*(x[i-1]-x[0])+(y[i-1]-y[0])*(y[i-1]-y[0]))*sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]))))<0)
		otric++;
	if((polozh==0)||(otric==0))
		printf("Vyp");
	if((polozh>0)&&(otric>0))
		printf("Nevyp");
	fclose(pfile);
	free(x);
	free(y);
	return 0;
}

	
	
	