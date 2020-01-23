#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int partitionprob(int * arr,int len){
	int flag=0;
	int sum=0;
	for(int i=0;i<len;i++)sum+=arr[i];
	if(sum%2!=0)return flag;
printf("AAAA\n");
	int psetcount=1<<len;
	int* sumarr=malloc(sizeof(int)*psetcount);
	int sum1=0;
	for(int i=0;i<psetcount;++i){
		sum1=0;
		for(int j=0;j<len;++j){
			if(i & (1<<j)){
				sum1+=arr[j];
			}
			sumarr[i]=sum1;
		}
	}
	//for(int i=0;i<psetcount;i++)printf("%d\n",sumarr[i] );
	int count=0;
	for(int i=0;i<psetcount;i++){
		if(sumarr[i]==sum/2)count++;
 	if(count>2)return count;
	}
	return 0;
}

int main(){
	int len;
	scanf("%d",&len);
	int *arr=malloc(sizeof(int)*len);
	for(int i=0;i<len;i++){
		scanf("%d",&arr[i]);
	}
	if(partitionprob(arr,len))printf("Subsets found\n");else printf("subsets not found\n");
}