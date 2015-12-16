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

int delete(node** head){
	node* ptr = *head;

	if (head == null)
        return 0;

    free(*head);
    *head = ptr->next;
    return 1;
}
int main(){

	node* head = newNode(5);
	head->next = newNode(4);
	head->next->next = newNode(3);
	printf("list before deleting \n");
	print(head);
	delete(&head);
	printf("list after deleting\n");
	print(head);
	return 0;
}
