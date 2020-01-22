//Given a graph G, convert that graph into adjacency matrix
#include <stdio.h>
#include <stdlib.h>
typedef struct node* nodeptr;
typedef struct node{
	int data;
	nodeptr link;
}node;
nodeptr getnode(){
	nodeptr temp=malloc(sizeof(node));
	temp->link=NULL;
	return temp;
}
void insert(nodeptr* arr,int from,int to){
	nodeptr nd=getnode();
	nd->data=to;
	//printf("IN INSERT FUNCTION\n");
	if(arr[from]==NULL){
		arr[from]=nd;
		return;
	}
	nodeptr trav=arr[from];
	while(trav->link!=NULL){
		trav=trav->link;
	}
	trav->link=nd;
}

void main(){
	int nodecount=0;
	printf("insert number of nodes\n");
	scanf("%d",&nodecount);
	int matrix[nodecount][nodecount];
	nodeptr* arr=malloc(sizeof(nodeptr)*nodecount);
	for(int i=0;i<nodecount;i++)arr[i]=NULL;
	for(int i=0;i<nodecount;i++)
		for(int j=0;j<nodecount;j++)
			matrix[i][j]=0;
	printf("insert number of edges\n");
	int edgecount;
	scanf("%d",&edgecount);
	int from,to;
	for(int i=0;i<edgecount;i++){
	printf("enter from and to vertex\n");
		scanf("%d %d",&from,&to);
		matrix[from][to]=1;
		insert(arr,from,to);
	}
	printf("adjacency matrix is::\n");
	for(int i=0;i<nodecount;i++){
		for(int j=0;j<nodecount;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("adjacency list is::\n");
	nodeptr trav;
	for(int i=0;i<nodecount;i++){
		trav=arr[i];
		printf("%d:\t",i );
		while(trav!=NULL){
			printf("%d-->",trav->data);
			trav=trav->link;
		}
		printf("NULL\n");
	}

}