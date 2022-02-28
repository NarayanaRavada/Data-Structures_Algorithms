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
	
	/* list is empty */
	if(*head == NULL){
		new_node->next = new_node;
		*head = new_node;
		return;
	}

	/* traverse to the last node */
	node *temp = *head;
	while(temp->next != *head){
		temp = temp->next;
	}

	new_node->next = *head;
	temp->next = new_node;
}

/* Inserting after a position */
void insertAfter(node **head, int data, int pos){

    node *new_node = new node;
	new_node->data = data;

	node *temp = *head;
	if(*head == NULL){
		new_node->next = new_node;
		*head = new_node;
	}

	/* move to node at pos */
    for(int i = 1; i < pos -1; i++){
		temp = temp->next;
	}

	new_node->next = temp->next;
	temp->next = new_node;
}

void deleteNode(node **head, int pos){

	if(head == NULL || pos < 0) return;

	if(pos == 1){
	    node *temp = *head;

		while(temp->next != *head){
			temp = temp->next;
		}

        *head = (*head)->next;
		free(temp->next);
		temp->next = *head; 
		return;
	}
	node *temp = *head;
    
	for(int i = 1; i < pos-1 && temp != NULL ; i++){
		temp = temp->next;
	}

	/* pos is out of range */
	if(temp == NULL || temp->next == NULL) return;

	node *next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

void reverse(node **head){

	if(*head == NULL) return;

	node *curr = *head;
	node *prev = NULL;
	node *next;
	do{
		/* store current next */
		/* replace current next with prev */
		next = curr->next;
		curr->next = prev;
		prev = curr;
        
		curr = next;

	}while(curr != *head);

	/* point last to head */
	(*head)->next = prev;
	*head = prev;
}

void print_list(node* head){

	node *temp = head;
	do{
	    cout << temp->data << " ";
	    temp = temp->next;

	}while(temp != head);
	cout << "\n";
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
	/* 0 1 2 3 4 */

	for(int i = 5; i > 1; i--){
		deleteNode(&head, i);
		print_list(head);
		insertAfter(&head, i - 1, i);
		print_list(head);
	}
	/* 0 1 2 3 4
       0 1 2 3
       0 1 2 3 4
       0 1 2 4
       0 1 2 3 4
       0 1 3 4
       0 1 2 3 4
       0 2 3 4
       0 1 2 3 4 */

	deleteNode(&head, 1);
	print_list(head);
	/* 1 2 3 4 */
	
	reverse(&head);
	print_list(head);
	/* 4 3 2 1 */
   
	return 0;
}
