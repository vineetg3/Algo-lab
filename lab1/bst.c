//Implement binary search tree in which all keys are unique. If duplicate key is present inform, else insert.
//Traverse bst in preorder,postorder and inorder.
#include <stdio.h>
#include <stdlib.h>
typedef struct node* nodeptr;
typedef struct node{
	int key;
	nodeptr lchild,rchild;
}node;

void inorder(nodeptr head){
	if(head==NULL)return;
	inorder(head->lchild);
	printf("%d\n",head->key);
	inorder(head->rchild);
}
void preorder(nodeptr head){
	if(head==NULL)return;
	preorder(head->lchild);
	preorder(head->rchild);
	printf("%d\n",head->key);
}
void postorder(nodeptr head){
	if(head==NULL)return;
	printf("%d\n",head->key);
	postorder(head->lchild);
	postorder(head->rchild);
}
// 
void isthere(nodeptr head,int ele,int* flag){
	if(head==NULL)
	{
		//*flag = 0;
		return;
	}

	isthere(head->lchild,ele,flag);
	
	if(head->key==ele)
		*flag=1;
	
	isthere(head->rchild,ele,flag);
}

void insertiter(nodeptr *head,int ele){
	nodeptr ptr=malloc(sizeof(node));
	ptr->rchild=NULL;
	ptr->lchild=NULL;
	ptr->key=ele;
	if(*head==NULL){
		*head=ptr;
		return;
	}
	//*head=ptr;
	int temp=0;
	// isthere(*head,ele,&temp);//printf("%d\n",temp);
	// if(temp){
	// 	printf("Key is there. Can't insert element\n");
	// 	return;
	// }
	int flag=1;
	nodeptr trav=*head;
	while(flag){
		//printf("IN INSETION LOOP\n");
		if(ele>trav->key){
			if(trav->rchild==NULL){
				//printf("ATTATCHING RIGHT NODE\n");
				trav->rchild=ptr;
				break;
			}
			trav=trav->rchild;
		}
		else if(ele<trav->key){
			if(trav->lchild==NULL){
				//printf("ATTATCHING LEFT NODE\n");
				trav->lchild=ptr;
				break;
			}
			trav=trav->lchild;
		}
		else{
			printf("Key is there. Can't insert element\n");
		return;
	}
	}
}
int main(){
	nodeptr head=NULL;
	int option;
	int ele;int flag=1;
	printf("1.insert 2.inorder 3.preorder 4.postorder 5.exit\n");
	while(flag){
		printf("enter option\n");
		scanf("%d",&option);
		switch(option){
			case 1:
			printf("enter element\n");
			scanf("%d",&ele);
			insertiter(&head,ele);
			break;
			case 2:
			inorder(head);
			break;
			case 3:
			preorder(head);
			break;
			case 4:
			postorder(head);
			break;
			case 5:
			flag=0;break;
		}
	}
}

