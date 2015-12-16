#define null NULL
#define max(x,y) (x)>(y)?(x):(y)
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag{
    int data;
    struct node_tag *left,*right;
}node;

void printArray(int [], int);
void printPathsRecur(node*, int [], int);
node* newNode(int );
void printPaths(node*);

/* Given a binary tree, print out all of its root-to-leaf
   paths, one per line. Uses a recursive helper to do the work.*/
void printPaths(node* node)
{
  int path[1000];
  printPathsRecur(node, path, 0);
}

/* Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths. */
void printPathsRecur(node* node, int path[], int pathLen)
{
  if (node==NULL) return;

  /* append this node to the path array */
  path[pathLen] = node->data;
  pathLen++;

  /* it's a leaf, so print the path that led to here */
  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
  /* otherwise try both subtrees */
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node* newNode(int data)
{
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return(newnode);
}

/* Utility that prints out an array on a line */
void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
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
    printPaths(root);
    return 0;
}
