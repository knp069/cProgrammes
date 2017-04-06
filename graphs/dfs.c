#define null NULL
#include <stdio.h>
#include <stdlib.h>
#define N 8

// adjacency matrix
int adj[N][N]={
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
};

int visited[N]={0,0,0,0,0,0,0,0};

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

int isVisited(int x){
    if (visited[x])
        return 1;
    return 0;
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

void dfs(int s){
    stack* stck;
    initialise(&stck);
    push(stck,s);
    visited[s]=1;
    int node;
    while(!isEmpty(stck)){
        node = pull(stck);
        printf("%d\t",node);
        for(int i=0;i<N;i++){
            if(adj[node][i] && !isVisited(i)){
                push(stck,i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

int main(){
    dfs(0);
    return 0;
}
