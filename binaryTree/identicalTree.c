#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
    int data;
    struct node_tag *right,*left;
}node;

node* newNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int identicalTree(node* root1 , node* root2){

    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL)
        return 0;
    if (root2 == NULL)
        return 0;
    return root1->data == root2->data &&
    identicalTree(root1->left,root2->left) &&
    identicalTree(root1->right,root2->right);
}

int main(){
    node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->right = newNode(3);
    node* root1 = newNode(5);
    root1->left = newNode(2);
    root1->left->right = newNode(1);
    if(identicalTree(root,root1))
        printf("trees are identiccal\n");
    else
        printf("Trees are not identical\n");

    return 0;
}
