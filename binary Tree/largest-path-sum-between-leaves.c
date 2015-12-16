#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
    int data;
    struct node_tag *left,*right;
}node;

int max(int x , int y){
	return x>y?x:y;
}

node* newNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left=newnode->right = NULL;
    return newnode;
}

int largestSumPath(node* root , int *sum){


    if(root == NULL)
        return 0;

    if( root->right==NULL && root->left==NULL)
        return root->data;

    int leftsum = largestSumPath(root->left,sum);
    int rightsum = largestSumPath(root->right,sum);

    int currentSum = leftsum+rightsum+root->data;

    if (*sum<currentSum)
        *sum = currentSum;

    if(leftsum==0 || rightsum==0)
        return (leftsum==0)? rightsum + root->data : leftsum + root->data;
    else
        return max(leftsum,rightsum) + root->data ;

}

int main()
{
    int maxSumPath=-9999;
    node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    printf("Max pathSum of the given binary tree is %d \n",largestSumPath(root,&maxSumPath));
    return 0;
}
