#define null NULL
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
	int data;
	struct node_tag *next;
}node;

int max(int x , int y){
	return x>y?x:y;
}

node* newNode(int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void print(node* head){
	node* ptr = head;
	
	while(ptr!=null){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return;
}

int append(node** head , int data){
	node* temp  = newNode(data);
	
	if (temp == null)
		return 0;
	
	temp->next = *head;
	*head = temp;
	return 1;
}
int main(){

	node* head = newNode(5);
	head->next = newNode(4);
	head->next->next = newNode(3);
	printf("Enter the data to be appended at the end : ");
	int x;
	scanf("%d",&x);
	printf("list before appending \n");
	print(head);
	append(&head , x);
	printf("list after appending\n");
	print(head);
	return 0;
}
