//DFS with recursion
#include <stdio.h>
#include <stdlib.h>

void dfs(int** mat,int * visited, int i,int n){
	if(visited[i]==1)return;
	visited[i]=1;
	printf("%d ",i);
	for(int j=0;j<n;j++){
		if(mat[i][j]==1 && visited[j]==0){
			dfs(mat,visited,j,n);
		}
	}
}




void main(){
	int nodecount=0;
	printf("insert number of nodes\n");
	scanf("%d",&nodecount);
	int** matrix=malloc(sizeof(int*)*nodecount);
	for(int i=0;i<nodecount;i++)matrix[i]=malloc(sizeof(int)*nodecount);
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
		
	}
	printf("adjacency matrix is::\n");
	for(int i=0;i<nodecount;i++){
		for(int j=0;j<nodecount;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	int *visited=malloc(sizeof(int)*nodecount);
	printf("dfs is:\n");
	dfs(matrix,visited,0,nodecount);
	

}
/*
insert number of nodes
5
insert number of edges
4
enter from and to vertex
0 4
enter from and to vertex
0 2
enter from and to vertex
2 3
enter from and to vertex
3 1
adjacency matrix is::
0 0 1 0 1 
0 0 0 0 0 
0 0 0 1 0 
0 1 0 0 0 
0 0 0 0 0 
dfs is:
0 2 3 1 4 
*/