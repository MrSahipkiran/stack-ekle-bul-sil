#include <stdio.h>
#include <stdlib.h>
	struct node{
		int data;
		struct node *next;
	};
	struct node *top=NULL;
	
	int push(int x){
		if(top == NULL){
			struct node *new=(struct node*)malloc(sizeof(struct node));
			new -> data = x;
			new -> next = NULL;
			top = new;	
						}
		
		else{
			struct node *new=(struct node*)malloc(sizeof(struct node));
			new -> data = x;
			new -> next = top;
			top = new;
		}
	}
	
	int display(){
		struct node *temp;
		temp=top;
		while(temp!=NULL){
			printf("the number(%d) is in %x\n",temp->data,temp);
			temp = temp -> next;
		}
	}
	
	int searchDisplay(){
		struct node *temp;
		temp=top;
		int x;
		printf("which do you want to search the number	");
		scanf("%d",&x);
		while(temp!=NULL){
			if(temp -> data == x){
				printf("the number(%d) was founded in %x\n",temp->data,temp);
				break;
			}
			else{
				temp = temp -> next;
			}
		}
			return 1;
	}
	
	int searchDelete(){
		struct node *temp;
		struct node *previous=NULL;
		temp=top;
		int x;
		printf("which do you want to search and delete the number	");
		scanf("%d",&x);
		while(temp != NULL){
			if(temp -> data == x){
				printf("the number(%d) was founded in %x ,and it was deleted\n",temp->data,temp);
				previous -> next = temp -> next ;
				free(temp);
				break;			
			}
			else{
				previous = temp;
				temp = temp -> next;
			}
		}
	}
	
	int main(){
		int number;
		printf("if you exit ,you enter '-1'\n");
		while(1){printf("could you enter the number		\n");scanf("%d",&number);	
			if(number==-1)break;		else push(number);	
		}
		
		while(1){
			printf("\n1 for display\t2 for search and display\t3for search and delete \t -1 for exit\t");
			scanf("%d",&number);
			if(number == -1 ) break;
			switch(number){
				case 1:
					display();
					break;
				case 2:
					searchDisplay();
					break;
				case 3:
					searchDelete();
					break;
			}	
		}
	}
