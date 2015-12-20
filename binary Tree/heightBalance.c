#include <stdio.h>
#include <stdlib.h>

#define null NULL

typedef struct node_tag{
    int data;
    struct node_tag *right,*left;
}node;

node* newNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = null;
    return newnode;
}

int max(int x , int y){
    return x>y?x:y;
}

int height(node* root){

    if(root == null){
        return 0;
    }

    return max(height(root->left),height(root->right))+1;
}

int isHeightBalance(node* root){

    if (root == null)
        return 1;

    int balanceFactor = abs( height(root->left) - height(root->right) ) < 2 ? 1 : 0 ;

    return balanceFactor && isHeightBalance(root->left) && isHeightBalance(root->right);

}

int main(){

    node* root = newNode(5);
    root->right = newNode(4);
    if (isHeightBalance(root)){
        printf("tree is height balanced \n");
    }
    else{
        printf("tree is not height balanced \n");
    }
    return 0;
}
