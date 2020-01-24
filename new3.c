#include <stdio.h>
#include <malloc.h>
int main(void)
{
	int k=0,polozh=0,otric=0,nevyp=0,i,j,n;
	int *a;
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
	a=(int*)malloc(k*sizeof(int));
	k=0;
	while(fscanf(pfile,"%d",&n)==1)
	{
        a[k]=n;
		k++;
	}
	for(j=0;j<k-5;j=j+2)
	{
		for(i=0;i<k-1;i=i+2)
		{
			if(((a[i]-a[j+2])*(a[j+3]-a[j+1])-(a[i+1]-a[j+3])*(a[j+2]-a[j]))/((a[j+2]-a[j])*(a[j+3]-a[j+1]))>=0)
				polozh=1;
			if(((a[i]-a[j+2])*(a[j+3]-a[j+1])-(a[i+1]-a[j+3])*(a[j+2]-a[j]))/((a[j+2]-a[j])*(a[j+3]-a[j+1]))<0)
				otric=1;
		}
		if((polozh==1)&&(otric==1))
			nevyp=1;
	}
	if(nevyp==1)
		printf("Nevypukliy ");
	else printf("Vypukliy ");
	fclose(pfile);
	free(a);
	return 0;
}

	