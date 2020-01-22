#include <stdio.h>
int opcount=0;
int gcd(int a ,int b){
	int min=0,other=0;
	if(a<b){min=a;other=b;}else{min=b;other=a;}
	for(int i=min;i>0;i--){
		opcount++;
		if(min%i==0 & other%i==0)return i;
	}
	return 1;
}



int main(){
	int a,b;
	printf("Enter two numbers to find the gcd\n");
	scanf("%d %d",&a,&b);
	printf("the gcd is %d\n",gcd(a,b));
	printf("opcount is:%d\n",opcount);

}