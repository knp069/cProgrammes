#define null NULL
#define max(x,y) (x)>(y)?(x):(y)
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
    int data;
    struct node_tag *left,*right;
}node;


node* newNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left=newnode->right = null;
    return newnode;
}


void printLevel(node* root , int level,int verbose){

    if (root == null)
        return;

    if (level == 1)
        printf("%d  ",root->data);

    else{
        if (verbose == 0 ){
            printLevel(root->left,level-1,verbose);
            printLevel(root->right,level-1,verbose);
        }
        else{
            printLevel(root->right,level-1,verbose);
            printLevel(root->left,level-1,verbose);
        }
    }
}

int height(node* root){

    if(root == null)
        return 0;
    else
        return max(height(root->left)+1 , height(root->right)+1);
}

void levelOrderTraversal(node* root){

    int h = height(root);
    int i=0;
    for(i=1;i<=h;i++){
        printLevel(root , i , (i+1)%2);
        printf("\n");
    }
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
    levelOrderTraversal(root);
    return 0;
}
