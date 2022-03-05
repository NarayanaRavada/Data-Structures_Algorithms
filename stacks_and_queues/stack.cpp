#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct stack {
	node *top;
};


bool isEmpty(stack *st){
	return st->top == NULL;
}

/* push data to new node and adds to top */
void push(stack **st, int data) {

	node *new_node = new node;
	new_node->data = data;
	new_node->next = NULL;

    /* Add old top as next to new top */
	new_node->next = (*st)->top;
	(*st)->top = new_node;
}

/* Removes the data in top and returns it */
int pop(stack **st){

	if(isEmpty(*st)){
		cout << "Stack is Empty!\n";
		exit(1);
	}
   
	/* Make top->next as top and delete old top */
	node *old_top = (*st)->top;
	int top_data = old_top->data;
	(*st)->top = (*st)->top->next;
	free(old_top);

	return top_data;
}

/* Returns the data in top */
int peek(stack *st){

	if(!isEmpty(st)){
		return st->top->data;
	} else {
		cout << "Stack is Empty!\n";
		exit(1);
	}
}

void print(stack *st){
	
	node* top = st->top;
	while(top != NULL) {
		cout << top->data << " ";
		top = top->next;
	}
	cout << "\n";
}

int main() {
	stack *st = new stack;
	st->top = NULL;
	for(int i = 0; i < 5; i++) {
		push(&st, i);
	}
	print(st);
	/* 4 3 2 1 0 */

	cout << "popped : " << pop(&st) << "\n";
	/* popped : 4 */
	print(st);
	/* 3 2 1 0 */

	cout << "peek : " << peek(st) << "\n";
	/* peek : 3 */
	print(st);
	/* 3 2 1 0 */

	return 0;
}
