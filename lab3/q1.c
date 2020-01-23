#include <stdlib.h>
#include <stdio.h>
int opcount=0;
void bubblesort(int *a,int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			opcount++;
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void main(){
	int len,ele;
	int *arr=malloc(sizeof(int)*len);
	scanf("%d",&len);
	printf("lenth is %d\n",len );
	for(int i=0;i<len;i++){
		scanf("%d",&ele);
		arr[i]=ele;
	}
	//printf("?????\n");
	bubblesort(arr,len);
	printf("sorted array is: ");
	for(int i=0;i<len;i++)printf("%d ",arr[i]);
	printf("opcount is %d\n",opcount);
}
