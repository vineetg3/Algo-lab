#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int opcount=0;
int stringmatch(char *str,int len1,char *substr,int len2){
	int flag=0;int k;
	for(int i=0;i<=len1-len2;i++){
		k=i;
		for(int j=0;j<len2;j++){
			opcount++;
			if(str[k]!=substr[j])
			break;
			k++;
			if(j==len2-1){
				flag=1;
				break;
			}
		}
		if(flag==1)break;
	}
	return flag;
}
void main(){
	char* str=malloc(sizeof(char)*30);
	char* substr=malloc(sizeof(char)*30);
	scanf("%s",str);
	scanf("%s",substr);
	//printf("length of string : %ld\n",strlen(str) );
	int flag=stringmatch(str,strlen(str),substr,strlen(substr));
	if(flag)printf("substring found\n");else printf("substring not found\n");
	printf("opcount is: %d\n",opcount);

}