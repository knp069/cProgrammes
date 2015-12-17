#define null NULL
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
	int data;
	struct node_tag *next;
}node;

typedef struct stack_tag{
    node* top;
}stack;

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

void initialise(stack **stck){
    *stck = (stack*)malloc(sizeof(stack));
    (*stck)->top = null;
}

int isEmpty(stack* stck){
    return (stck->top == null)?1:0;
}

int push(stack* stck , int data){
    node* temp = newNode(data);

    if (temp == null)
        return 0;

    temp->next = stck->top;
    stck->top = temp;
    return 1;
}

int pull(stack* stck){

    if(stck->top == null)
        return -9999;

    node* temp = stck->top;
    int data = stck->top->data;
    stck->top = temp->next;
    free(temp);
    return data;
}

int main(){
    stack* stck;
    initialise(&stck);
    printf("%d\n",isEmpty(stck));
    printf("%d\n",pull(stck));
    printf("%d\n",push(stck,1));
    printf("%d\n",push(stck,2));
    printf("%d\n",push(stck,3));
    printf("%d\n",push(stck,4));
    print(stck->top);
    printf("%d\n",isEmpty(stck));
    printf("%d\n",pull(stck));
    print(stck->top);
    return 0;
}
