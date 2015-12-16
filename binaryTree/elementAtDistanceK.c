#define null NULL
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
    int data;
    struct node_tag *left,*right;
}node;


int max(int x, int y){
    return x > y ? x : y ;
}

node* newNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left=newnode->right = null;
    return newnode;
}


void printLevel(node* root , int level){

    if (root == null)
        return;

    if (level == 1)
        printf("%d  ",root->data);

    else{
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

int height(node* root){

    if(root == null)
        return 0;
    else
        return max(height(root->left)+1 , height(root->right)+1);
}




int main(){

    node* root = newNode(5);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);
    root->right = newNode(9);
    root->right->left = newNode(7);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(8);
    printf("Enter the distance : ");
    int k;
    scanf("%d",&k);
    printLevel(root , k);
    return 0;
}
