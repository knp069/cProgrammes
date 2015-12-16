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

int max(int x , int y){
    return x>y?x:y;
}

int height(node* root){

    if(root == null)
        return 0;
    else
        return max(height(root->left)+1 , height(root->right)+1);
}

int diameter(node* root){

    if ( root == null)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(leftHeight+rightHeight+1 , max(leftDiameter,rightDiameter));
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
    printf("the diameter of the tree is %d \n",diameter(root));
    return 0;
}
