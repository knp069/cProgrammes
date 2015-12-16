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

void widthLevel(node* root , int level , int* sum){

    if (root == null)
        return;

    if (level == 1)
        (*sum)++;

    else{
        widthLevel(root->left,level-1 , sum);
        widthLevel(root->right,level-1 , sum);
    }
}

int height(node* root){

    if(root == null)
        return 0;
    else
        return max(height(root->left)+1 , height(root->right)+1);
}

int getwidth(node* root){

    int h = height(root);
    int i=0;
    int width = -1;
    for(i=1;i<=h;i++){
        int sum = 0;
        widthLevel(root , i , &sum);

        if(width<sum)
            width = sum;
    }

    return width;
}


int main()
{
    int maxSumPath=-9999;
    node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    printf("Width of tree is %d\n",getwidth(root));
    return 0;
}
