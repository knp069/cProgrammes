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

    temp->next = qu->rear;
    qu->rear = temp;
    return 1;
}

int dequeue(queue* qu){
	node* ptr = qu->rear;;
    node* prev = null;

	if (isEmpty(qu))
        return -9999;

    if (ptr->next == null){
        free(ptr->next);
        ptr->next = null;
		qu->front = ptr;
    	return 1;
    }

	while(ptr->next != null){
        prev = ptr;
		ptr = ptr->next;
	}
    free(ptr);
	qu->front = prev;
    prev->next = NULL;
    return 1;
}

int main(){
    queue* qu;
    initialise(&qu);
    printf("%d\n",isEmpty(qu));
    printf("%d\n",dequeue(qu));
    printf("%d\n",enqueue(qu,1));
    printf("%d\n",enqueue(qu,2));
    printf("%d\n",enqueue(qu,3));
    printf("%d\n",enqueue(qu,4));
    print(qu->rear);
    printf("%d\n",isEmpty(qu));
    printf("%d\n",dequeue(qu));
    print(qu->rear);
    return 0;
}
