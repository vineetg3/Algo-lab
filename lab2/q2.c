#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* seive(int n){
	int *a=malloc(sizeof(int)*n);
	for(int i=2;i<n;i++)a[i]=0;
	int j=0;
	for(int i=2;i<=((int)sqrt(n));i++){
		if(a[i]!=-1){
			j=i*i;
			while(j<=n){
				a[j]=-1;
				j+=i;
			}
		}
	}
	//for(int i=2;i<n;i++)if(a[i]==0)printf("%d ",i);
	return a;
}

int* findprimefactors(int x){
	int *pa=seive(x);
	int n=x;
	for(int i=2;i<=x;i++){
		n=x;
		if(pa[i]==0)
			{	while(1){
				if(n%i==0){
					n=n/i;
					pa[i]++;continue;
				}break;
			}
		}                                                                                         
	}
	return pa;
	//for(int i=2;i<x;i++)if(pa[i]>0)printf("%d ",pa[i]);
}
int gcd(int a,int b){
	int small,big;
	if(a<b){small=a;big=b;}else{small=b;big=a;}
	int* arr1=findprimefactors(small);
	int* arr2=findprimefactors(big);
	int gcd=1;
	
	for(int i=2;i<=small;i++){
		if(arr1[i]>0 & arr2[i]>0){
			while(arr1[i]!=0 & arr2[i]!=0){
				gcd=gcd*i;
				arr1[i]--;arr2[i]--;
			}
		}
	}
	return gcd;
}

void main(){
	// int a,b;
	// printf("Enter two numbers to find the gcd\n");
	// scanf("%d %d",&a,&b);
	int a,b,f;
	scanf("%d %d",&a,&b);
	f=gcd(a,b);
	printf("gcd is %d\n",f);

}