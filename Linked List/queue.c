#define null NULL
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
	int data;
	struct node_tag *next;
}node;

typedef struct queue_tag{
    node* front;
    node* rear;
}queue;

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

void initialise(queue **qu){
    *qu = (queue*)malloc(sizeof(queue));
    (*qu)->rear = (*qu)->front = null;
}

int isEmpty(queue* qu){
    return (qu->rear == null && qu->front == null)?1:0;
}

int enqueue(queue* qu , int data){
    node* temp = newNode(data);

    if (temp == null)
        return 0;

	if (isEmpty(qu)){
		temp->next = qu->rear;
		qu->rear = qu->front = temp;
		return 1;
	}

    temp->next = qu->rear;
    qu->rear = temp;
    return 1;
}

int dequeue(queue* qu){
	node* ptr = qu->rear;;
    node* prev = null;
	int retval;

	if (isEmpty(qu))
        return -9999;

	prev = null;

	if( qu->front == qu->rear){
		retval = qu->front->data;
		free(qu->front);
		qu->front = qu->rear = null;
		return retval;
	}

	while(ptr->next != null){
        prev = ptr;
		ptr = ptr->next;
	}
	retval = ptr->data;
    free(ptr);
	qu->front = prev;
    prev->next = NULL;
    return retval;
}

int main(){
    queue* qu;
    initialise(&qu);
    printf("%d\n",isEmpty(qu));
    printf("%d\n",dequeue(qu));
    printf("%d\n",enqueue(qu,5));
	printf("%d\n",dequeue(qu));
    printf("%d\n",enqueue(qu,5));
    printf("%d\n",enqueue(qu,2));
    printf("%d\n",enqueue(qu,3));
    printf("%d\n",enqueue(qu,4));
    print(qu->rear);
    printf("%d\n",isEmpty(qu));
    printf("%d\n",dequeue(qu));
    print(qu->rear);
    return 0;
}
