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

void print(node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}

int insert(node** root , int data){

    node* temp = newNode(data);

    if (temp == null)
        return 0;

    if( (*root) == null){
        *root = temp;
        return 1;
    }

    node* ptr = *root;
    int done = 0;

    while (!done) {
        if(ptr->data < data){
            if(ptr->right == null){
                ptr->right = temp;
                done = 1;
            }
            else
                ptr = ptr->right;
        }

        else{
            if(ptr->left == null){
                ptr->left = temp;
                done = 1;
            }
            else
                ptr = ptr->left;
        }
    }
    return 1;
}


int delete(node** root , int data){

    if (root == null)
        return 0;

    int done = 0;
    node* parent = null;
    node* ptr = *root;
    while(!done){

        if(ptr->data == data){

            if(ptr->right == null && ptr->left == null) { // if the node is a leaf
                free(ptr);
                parent->right->data
            }

        }
        else if(ptr->data < data){
            parent = ptr;
            ptr = ptr->right;
        }
        else{
            parent = ptr;
            ptr = ptr->left;
        }
    }
}
int main(){

    node* tree = null;
    insert(&tree,4);
    insert(&tree,9);
    insert(&tree,1);
    insert(&tree,5);
    insert(&tree,2);
    insert(&tree,6);
    insert(&tree,8);
    insert(&tree,3);
    insert(&tree,7);
    print(tree);
    printf("\n");
    return 0;
}
