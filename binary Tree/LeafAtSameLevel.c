#define and &&
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

int leafFoundAtHeight = -1;

int leafAtSameLevel(node* root , int height){

    if (root == NULL)
        return 1;
    if (root->left ==NULL and root->right==NULL){
        if(leafFoundAtHeight == -1){
            leafFoundAtHeight = height;
            return 1;
        }
        else{
            return (leafFoundAtHeight == height);
        }
    }

    return leafAtSameLevel(root->left , height+1) && leafAtSameLevel(root->right , height+1);
}

int main(){
    // Let us create tree shown in thirdt example
    node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    root->left->left->left->left = newNode(10);
    if (leafAtSameLevel(root,0))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
    return 0;
}
