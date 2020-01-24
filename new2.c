#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
	int n,zn=0,n1=-1,n2=-1,n3=-1,n4=-1,a1=-1,a2=-1,a3=-1,a4=-1;
	scanf("%d",&n);
	if(n>=0)
		zn=1;
	if(abs(n)>=10)
	{
		a1=abs(n)%10;
		n1=(abs(n)/10);
	}
	else a1=abs(n);
	if(n1>=10)
	{
		a2=n1%10;
		n2=(n1/10); 
	}
	else a2=n1;
	if(n2>=10)
	{
		a3=n2%10;
		n3=(n2/10);
	}
	else a3=n2;
	if(n3>=10)
	{
		a4=n3%10;
		n4=(n3/10); 
	}
	else a4=n3; // число - n4 a4 a3 a2 a1
	if(n4==-1) n4=0; if(a4==-1) a4=0; if(a3==-1) a3=0; if(a2==-1) a2=0; if(a1==-1) a1=0;
	if(zn==0)
		printf("minus ");
	if(abs(n)>=1000)
	{
		if(a4+n4*10==1) printf("one "); if(a4+n4*10==2) printf("two "); if(a4+n4*10==3) printf("three "); if(a4+n4*10==4) printf("four "); if(a4+n4*10==5) printf("five "); if(a4+n4*10==6) printf("six ");
		if(a4+n4*10==7) printf("seven "); if(a4+n4*10==8) printf("eight "); if(a4+n4*10==9) printf("nine "); if(a4+n4*10==10) printf("ten "); if(a4+n4*10==11) printf("eleven "); if(a4+n4*10==12) printf("twelve ");
		if(a4+n4*10==13) printf("thirteen "); if(a4+n4*10==14) printf("fourteen "); if(a4+n4*10==15) printf("fifteen "); 
		if(a4+n4*10==16) printf("sixteen "); if(a4+n4*10==17) printf("seventeen "); if(a4+n4*10==18) printf("eighteen "); if(a4+n4*10==19) printf("nineteen "); if(a4+n4*10==20) printf("twenty ");	if(a4+n4*10==21) printf("twenty one "); 
		if(a4+n4*10==22) printf("twenty two "); if(a4+n4*10==23) printf("twenty three "); if(a4+n4*10==24) printf("twenty four "); if(a4+n4*10==25) printf("twenty  five "); if(a4+n4*10==26) printf("twenty six "); if(a4+n4*10==27) printf("twenty seven "); 
		if(a4+n4*10==28) printf("twenty eight "); if(a4+n4*10==29) printf("twenty nine "); if(a4+n4*10==30) printf("thirty "); if(a4+n4*10==31) printf("thirty one "); if(a4+n4*10==32) printf("thirty two ");
		printf("thousand ");
	}
	if(abs(n)>=100)
	{
		if(a3==1) printf("one hundred ");  if(a3==2) printf("two hundred ");  if(a3==3) printf("three hundred "); if(a3==4) printf("four hundred "); if(a3==5) printf("five hundred "); if(a3==6) printf("six hundred "); 
		if(a3==7) printf("seven hundred "); if(a3==8) printf("eight hundred "); if(a3==9) printf("nine hundred ");
	}
	if(a2>=2)
	{
		if(a2==2) printf("twenty ");  if(a2==3) printf("thirty "); if(a2==4) printf("fourty "); if(a2==5) printf("fifty "); if(a2==6) printf("sixty "); 
		if(a2==7) printf("seventy "); if(a2==8) printf("eighty "); if(a2==9) printf("ninety ");
		if(a1==1) printf("one ");  if(a1==2) printf("two ");  if(a1==3) printf("three "); if(a1==4) printf("four "); if(a1==5) printf("five "); if(a1==6) printf("six "); 
		if(a1==7) printf("seven "); if(a1==8) printf("eight "); if(a1==9) printf("nine ");
	}
	if((a1+a2*10>0)&&(a1+a2*10<20))
	{
		if(a1+a2*10==1) printf("one "); if(a1+a2*10==2) printf("two "); if(a1+a2*10==3) printf("three "); if(a1+a2*10==4) printf("four "); if(a1+a2*10==5) printf("five "); if(a1+a2*10==6) printf("six ");
		if(a1+a2*10==7) printf("seven "); if(a1+a2*10==8) printf("eight "); if(a1+a2*10==9) printf("nine "); if(a1+a2*10==10) printf("ten "); if(a1+a2*10==11) printf("eleven "); if(a1+a2*10==12) printf("twelve ");
		if(a1+a2*10==13) printf("thirteen "); if(a1+a2*10==14) printf("fourteen "); if(a1+a2*10==15) printf("fifteen "); 
		if(a1+a2*10==16) printf("sixteen "); if(a1+a2*10==17) printf("seventeen "); if(a1+a2*10==18) printf("eighteen "); if(a1+a2*10==19) printf("nineteen ");
	}
	if(n==0)
		printf("zero ");
	printf("(%d %d %d %d %d)",n4,a4,a3,a2,a1);
	return 0;
}