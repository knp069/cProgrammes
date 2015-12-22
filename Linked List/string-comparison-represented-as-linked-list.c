#include <stdio.h>
#include <stdlib.h>


typedef struct node_tag{
    char data;
    struct node_tag *next;
}node;


node* append(node* head , char data){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;

    if (head == NULL)
        return tmp;

    node* ptr = head;

    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = tmp;

    return head;
}

void print(node* head){
    node* ptr = head;

    while(ptr != NULL){
        printf("%c",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int cmp(node* str1 , node* str2){

     node* ptr1 = str1;
     node* ptr2 = str2;

    while(ptr1 && ptr2 && ptr1->data == ptr2->data){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    if(ptr1==NULL && ptr2==NULL){
        return 0;
    }
    else if (ptr1==NULL){
        return -1;
    }
    else if (ptr2 == NULL){
        return 1;
    }
    else if (ptr1->data < ptr2->data){
        return -1;
    }
    else{
        return 1;
    }
}


int main(){
	// Linked List for holding Strings

	node* string1 = NULL;
	node* string2 = NULL;

	// let the first string is abacus

	string1 = append(string1,'a');
	string1 = append(string1,'b');
	string1 = append(string1,'a');
	string1 = append(string1,'c');
	string1 = append(string1,'u');
	string1 = append(string1,'s');
    print(string1);

	// let the second string be abacus

	string2 = append(string2,'a');
	string2 = append(string2,'b');
	string2 = append(string2,'a');
	string2 = append(string2,'c');
	string2 = append(string2,'d');
	string2 = append(string2,'s');
    print(string2);

	switch(cmp(string1,string2)){
		case -1:{
			printf("string 1 is less than string 2\n");
			break;
		}
		case 0:{
			printf("string 1 is equal to string 2\n");
			break;
		}
		case 1:{
			printf("string 1 is greater than string 2\n");
			break;
		}
	}
	return 0;
}
