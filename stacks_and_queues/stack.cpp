#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct stack {
	node *top;
};

/* --- STACK --- */
/* stack is a First in first out data structure 
 * ex: A cd stack the last cd kept will be first to be out
 * Used in Undo and Redo applications */

bool isEmpty(stack st){
	return st.top == NULL;
}

/* push data to new node and adds to top */
void push(stack *st, int data) {

	node *new_node = new node;
	new_node->data = data;
	new_node->next = NULL;

    /* Add old top as next to new top */
	new_node->next = st->top;
	st->top = new_node;
}

/* Removes the data in top and returns it */
int pop(stack *st){

	/* Empty */
	if(isEmpty(*st)){
		cout << "Stack Underflow!\n";
		exit(1);
	}
   
	/* Make top->next as top and delete old top */
	node *old_top = st->top;
	int top_data = old_top->data;
	st->top = st->top->next;
	free(old_top);

	return top_data;
}

/* Returns the data in top */
int peek(stack st){

	if(!isEmpty(st)){
		return st.top->data;
	} else {
		cout << "Stack Underflow\n";
		exit(1);
	}
}

void print(stack st){

	node* top = st.top;

	/* Empty */
	if(isEmpty(st)) {
		cout << "Stack Underflow\n";
		return;
	}
	while(top != NULL) {
		cout << top->data << " ";
		top = top->next;
	}
	cout << "\n";
}

int main() {
	stack st;
	st.top = NULL;
	for(int i = 0; i < 5; i++) {
		push(&st, i);
	}
	print(st);
	/* 4 3 2 1 0 */

	for(int i = 0; i < 4; i++){
		pop(&st);
	}
	print(st);
	/* 0 */

	cout << "peek : " << peek(st) << "\n";
	/* peek : 3 */

	cout << "popped : " << pop(&st) << "\n";
	/* popped : 3 */
	print(st);
	/* Stack Underflow */

    peek(st);
	/* Stack Underflow */

	return 0;
}
