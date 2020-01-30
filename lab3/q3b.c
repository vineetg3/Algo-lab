#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int partitionprob(int * arr,int len){
	int flag=0;
	int sum=0;
	for(int i=0;i<len;i++)sum+=arr[i];//printf("sum is %d\n",sum );
	if(sum%2!=0)return flag;
//printf("AAAA\n");
	int psetcount=1<<len;
	int* sumarr=malloc(sizeof(int)*psetcount);
	int sum1=0;
	int set_arr[2]={0};int k=0;
	for(int i=0;i<psetcount;++i){
		sum1=0;
		for(int j=0;j<len;++j){
			if(i & (1<<j)){
				sum1+=arr[j];
			}
		}
		sumarr[i]=sum1;
		if(sum1==(sum/2)){
			set_arr[k]=i;k++;//printf("sum1:%d\n",sum1);
		}
	}
	// for(int i=0;i<psetcount;i++)printf("%d ",sumarr[i] );
	// int count=0;
	// for(int i=0;i<psetcount;i++){
	// 	if(sumarr[i]==sum/2)count++;
 // 	if(count>=2)return count;
	// }
	if(k){
		printf("subsets found\n");
		for(int i=0;i<2;i++){
			for(int j=0;j<len;++j){
				if(set_arr[i] & 1<<j)printf("%d ",arr[j] );
			}
			printf("\n");
		}
	}else
	printf("subsets not found\n");
}

int main(){
	int len;
	scanf("%d",&len);
	int *arr=malloc(sizeof(int)*len);
	for(int i=0;i<len;i++){
		scanf("%d",&arr[i]);
	}
	partitionprob(arr,len);
	//if(partitionprob(arr,len))printf("Subsets found\n");else printf("subsets not found\n");
}