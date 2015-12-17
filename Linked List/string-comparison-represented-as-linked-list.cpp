#include <iostream>
using namespace std;

/* this is a class for holding the indivisual character of string
 *  and point to the next alphabet in the string */
 
class Node{
public:
	char data;   // variable for alphabet
	Node* next;  // pointer to next variable

	Node(char data){      // conatructor for creating a node
		this->data = data;
		this->next = NULL;
	}
	Node(); // default constructor
};

/* class for holding the indivisuals nodes in a cluster so that it can form a word 
 * we can access the word by the start node and cna traverse the word in forward 
 * direction using the next variable  */

class linkedList{
public:
	Node* head;   // head node which allows access to the complete word

	linkedList(){
		this->head = NULL;  // initialising the word to null a constructor
	}

	void append(char data){  // function for appending a alphabet at he end of the word
		Node* ptr = this->head;

		if (ptr == NULL){    // if the word is null then just add the node and point the head to the new node
            head = new Node(data);
			return;
		}

		while(ptr->next){     // if the word already contains some apphabet then traverse until the pointer comes at the end of the  
			ptr=ptr->next;    // word and then appent the new node at this point
		}
		Node* temp = new Node(data);
		ptr->next = temp;
		return;
	}
    void print(){
        Node* ptr = this->head;
        while(ptr!=NULL){
            cout<<ptr->data;
            ptr=ptr->next;
        }
        cout<<endl;
    }
    int cmp(linkedList string){

        Node* ptr1;
        Node* ptr2;
        ptr1 = this->head;
        ptr2 = string.head;
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

};

int main(){
	// Linked List for holding Strings

	linkedList string1;
	linkedList string2;

	// let the first string is abacus

	string1.append('a');
	string1.append('b');
	string1.append('a');
	string1.append('c');
	string1.append('u');
	string1.append('s');
    string1.print();

	// let the second string be aback

	string2.append('a');
	string2.append('b');
	string2.append('a');
	string2.append('c');
	string2.append('u');
	string2.append('s');
    string2.print();

	switch(string1.cmp(string2)){
		case -1:{
			cout<<"string 1 is less than string 2"<<endl;
			break;
		}
		case 0:{
			cout<<"string 1 is equal to string 2"<<endl;
			break;
		}
		case 1:{
			cout<<"string 1 is greater than string 2"<<endl;
			break;
		}
	}
	return 0;
}
