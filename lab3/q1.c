#include <stdlib.h>
#include <stdio.h>
void bubblesort(int *a,int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
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
	for(int i=0;i<len;i++){
		scanf("%d",&ele);
		arr[i]=ele;
	}
	bubblesort(arr,len);
	for(int i=0;i<len;i++)printf("%d ",arr[i]);
}
