#include<iostream>
using namespace std;

struct node {
	int data;
    node* next = NULL;
};         

struct queue {
	node *front, *rear;
};


/* --- QUEUES ------  */
/* Queue is last in first out data structure 
 * ex: Similar to the long queues which we stand in
 * */

/* Add last */
void enqueue(queue *q, int data) {
	node* new_node = new node;
	new_node->data = data;
	
	/* Empty queue */
	if(q->front == NULL){
		q->front = new_node;
		q->rear = new_node;
		return;
	}

	/* Not Empty */
	q->rear->next = new_node;
	q->rear = new_node;
}

/* Remove the first */
void dequeue(queue *q) {
	
	/* Empty queue */
	if(q->front == NULL) {
		return;
	}

	/* With only one element */
    if(q->front == q->rear) {
		q->front = NULL;
		q->rear  = NULL;
		return;
	}

	q->front = q->front->next;
}

void print(queue q){
	
	/* Empty */
    if(q.front == NULL) {
		cout << "Its Empty\n";
		return;
	}

	node *temp = q.front; 
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n"; 
}

int main () {
	queue q;
	q.front = NULL;
	for(int i = 0; i < 5; i++){
		enqueue(&q, i);
	}
	print(q);
	/* 0 1 2 3 */


	for(int i = 0; i < 4; i++){
		dequeue(&q);
	}
	print(q);
    /*  */

	dequeue(&q);
	print(q);
	/* 1 2 3 */
}
