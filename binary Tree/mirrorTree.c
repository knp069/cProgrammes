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

void mirrorTree(node* root){


    if(root == null)
        return;

    if (root->left == null && root->right == null)
        return;

    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main()
{
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  /* Print inorder traversal of the input tree */
  printf("\nInorder traversal of the constructed tree is \n");
  print(root);

  /* Convert tree to its mirror */
  mirrorTree(root);

  /* Print inorder traversal of the mirror tree */
  printf("\nInorder traversal of the mirror tree is \n");
  print(root);
  printf("\n");
  return 0;
}
