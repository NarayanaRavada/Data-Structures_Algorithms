#include <bits/stdc++.h>
using namespace std;

typedef struct node  {
	int val;
	struct node *prev;
	struct node *next;
} node;

/* Inserts at the End */
void insert(node **head, int val) {
	node *new_node = new node;
	new_node->next = NULL;
	new_node->val = val;
    
	/* list is empty : assign new node to head*/
	if(*head == NULL) {
		new_node->prev = NULL;
		*head = new_node;
		return;
	}	

	node *temp = *head;
   
	/* Traverse to the (Last Node)*/
	while(temp->next != NULL) {
		temp = temp->next;
	}	
	
	new_node->prev = temp;
	temp->next = new_node;
}	

/* Traversing a list */
void print_list(node *head) {
    
	/*First and Last nodes point to null*/
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";
}

void print_reverse(node* head){
	
	while(head->next != NULL){
		head = head->next;
	}

	while(head != NULL){
		cout << head->val << " ";
		head = head->prev;
	}
	cout << "\n";
}

/* Inserts after a specific node */
void insertAfter(node **head, int val, int pos){
	
	node *new_node = new node;
	new_node->val = val;
	
	/* List is empty */
    if(*head == NULL) return;

	node *temp = *head;
	for(int i = 1; i < pos - 1 && temp != NULL; i++){
		temp = temp->next;
	}
  
	/* pos is out of range */
	if(temp == NULL) return;

	new_node->next = temp->next;
    new_node->prev = temp;
	
	/* Insertion after last node */
	if(new_node->next != NULL){
		new_node->next->prev = new_node;
	}

	temp->next = new_node;
}

void deleteNode(node **head, int pos){

	/* List is emppty */
	if(*head == NULL || pos < 0) return;

	if(pos == 1){
		*head = (*head)->next;
		(*head)->prev = NULL;
		return;
	}

	node* curr = *head;
	for(int i = 1; i < pos && curr != NULL; i++){
		curr = curr->next;
	}

	/* reaches end */
	if(curr == NULL) return;
     
	/* If last node */
	if(curr->next != NULL){
		curr->next->prev = curr->prev;
	}

	curr->prev->next = curr->next;
	free(curr);
}

/* Reverses the list */
void reverse(node **head){
	
	node *curr = *head;
	node *temp = NULL;

	/* Swap current->next with current->prev */
	while(curr != NULL){
		temp = curr->prev;
        curr->prev = curr->next;
		curr->next = temp;
        
		curr = curr->prev;
	}
    
	if(temp != NULL)
		*head = temp->prev;
}

int main() {
	node *head = NULL;
    for (int i = 0; i < 5; i++){
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
   
	print_reverse(head);
	/* 1 2 3 4 */

	return 0;
} 		

