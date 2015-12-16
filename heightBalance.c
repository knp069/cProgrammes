#define and &&
#define or ||
#define null NULL
#include <stdio.h>
#include <stdlib.h>
typedef struct node_tag{
    int data;
    struct node_tag *left,*right;
}node;

node* newNode(int data){
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int heightBalance(node* root){
    
    return heightBalance(root->right) && heightBalance(root->right);
}
