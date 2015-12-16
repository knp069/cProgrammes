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

void deleteTree(node* root){

    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void print(node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}

int main(){

    node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->right = newNode(3);
    printf("printing inorder traversal of tree before deletion\n" );
    print(root);
    printf("\n" );
    deleteTree(root);
    printf("tree deleated ...\n");
    root = NULL;
    print(root);
    return 0;
}
