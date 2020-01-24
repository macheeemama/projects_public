#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned int i;
	char str[4000];
	FILE *in; FILE *out;
	char *estr;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	if(in==NULL)
	{
		printf("error\n");
		return -1;
	}
	while(1)
	{
		estr=fgets(str,sizeof(str),in);
		if(estr==NULL)
			break;
		else
		{
			for(i=0;i<strlen(str);i++)
			{
				if(str[i]!=str[i+1])
					putc(str[i], out);
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
    