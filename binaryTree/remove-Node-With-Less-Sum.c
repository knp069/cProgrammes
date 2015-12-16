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
    newnode->left=newnode->right = NULL;
    return newnode;
}

// print the tree in LVR (Inorder traversal) way.
void print(node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}

node* deleteNodeLessSum(node* root , int *sum , int k){

    if (root == null)
        return null;

    int lsum,rsum;
    lsum = rsum = *sum + root->data ;

    root->left = deleteNodeLessSum(root->left , &lsum , k);
    root->right = deleteNodeLessSum(root->right , &rsum , k);

    *sum = max(lsum,rsum);

    if(*sum < k){
        free(root);
        root = NULL;
    }
    return root;
}

node *prune(node *root, int k)
{
    int sum = 0;
    return deleteNodeLessSum(root,&sum,k);
}

int main()
{
    int k = 45;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);

    printf("Tree before truncation\n");
    print(root);

    root = prune(root, k); // k is 45

    printf("\n\nTree after truncation\n");
    print(root);

    return 0;
}
