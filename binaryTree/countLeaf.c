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

int countLeaf(node* root){

    if (root == null)
        return 0;

    if (root->right == null and root->left == null)
        return 1;

    return countLeaf(root->left)+countLeaf(root->right);
}

int main(){
    // Let us create tree shown in thirdt example
    node* root = newNode(5);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);
    root->right = newNode(9);
    root->right->left = newNode(7);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(8);
    printf("the number of leaves are %d \n",countLeaf(root));
    return 0;
}
