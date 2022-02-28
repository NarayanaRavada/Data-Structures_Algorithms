#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
} node;

/* Inserting at the End */
void insert(node **head, int data){

	node *new_node = new node;
	new_node->data = data;
	new_node->next = NULL;

	/* list is empty */
	if(*head == NULL){
		*head = new_node;
		return;
	}

	/* traverse to the last node */
	node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = new_node;
}

/* Inserting after a position */
void insertAfter(node **head, int data, int pos){

	node *new_node = new node;
	new_node->data = data;
	new_node->next = NULL;

	node *temp = *head;
	if(*head == NULL) return;

	/* move to node at pos */
	for(int i = 1; i < pos - 1 && temp != NULL; i++){
		temp = temp->next;
	}

	if(temp == NULL) return;

	new_node->next = temp->next;
	temp->next = new_node;
}

void deleteNode(node **head, int pos){

	if(head == NULL || pos < 0) return;

	node *temp = *head;
	if(pos == 1){
		*head = temp->next;
		free(temp);
		return;
	}

	for(int i = 1; i < pos-1 && temp != NULL ; i++){
		temp = temp->next;
	}

	/* pos is out of range */
	if(temp == NULL) return;

	node *next = NULL;
	if(temp->next != NULL){
		next = temp->next->next;
	}

	free(temp->next);
	temp->next = next;
}

void reverse(node **head){

	node *curr = *head;
	node *prev = NULL;
	while(curr != NULL){

		/* store current next */
		/* replace current next with prev */
		node* next = curr->next;
		curr->next = prev;
		prev = curr;

		curr = next;
	}

	*head = prev;
}

void print_list(node* head){

	while(head != NULL){
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "null\n";
}


/*  Insertion at head           O(1) 
 *  Insertion at end            O(n)
 *  Deletion  at head           O(1)
 *  Deletion at postion (pos)   O(pos)        
 *  _______________________________________________________________
 *  Insertions and Deletions are of O(1) except for accounting to 
 *  traversal, To achieve O(1) time complexity in the end insertion 
 *  on can maintain  a tail pointer similar to insertion at head.                                  
 * */

int main() {
	node *head = NULL;
	for(int i = 0; i < 5; i++){
		insert(&head, i);
	}
	print_list(head);
	/* 0-->2-->3-->4-->null */

	for(int i = 5; i > 1; i--){
		deleteNode(&head, i);
		print_list(head);
		insertAfter(&head, i - 1, i);
		print_list(head);
	}
	/* 0-->1-->2-->3-->4-->null
       0-->1-->2-->3-->null
       0-->1-->2-->3-->4-->null
       0-->1-->2-->4-->null
       0-->1-->2-->3-->4-->null
       0-->1-->3-->4-->null
       0-->1-->2-->3-->4-->null
       0-->2-->3-->4-->null
       0-->1-->2-->3-->4-->null
       1-->2-->3-->4-->null
       4-->3-->2-->1-->null */

	deleteNode(&head, 1);
	print_list(head);
    /* 1-->2-->3-->4-->null */

	reverse(&head);
	print_list(head);
	/* 4-->3-->2-->1-->0-->null */

	return 0;
}
