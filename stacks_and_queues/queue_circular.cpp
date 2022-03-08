#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
	int data;
	node *next;
};

struct c_queue {
	node* tail;
};

/* --- CIRCULAR QUEUES */
/* It same as queue with no front and rear pointing to front 
 * ex: If a Counter gives both token and the items then first person 
 *     has to take items at the counter and last person has to take 
 *     token at the same counter.
 * Used in trafic lights, Buffer memory  management*/

/* Add Last */
void enqueue(c_queue *cq, int data) {

    node *new_node = new node;
	new_node->data = data;

	/* Empty */
	if(cq->tail == NULL) {
		new_node->next = new_node;
		cq->tail = new_node;
		return;
	}

	new_node->next = cq->tail->next;
	cq->tail->next = new_node;
	cq->tail = new_node;
}

/* Remove First */
void dequeue(c_queue *cq) {

	/* Empty */
    if(cq->tail == NULL){
		return;
	}

	/* One element */
    if(cq->tail == cq->tail->next) {
		cq->tail = NULL;
		return;
	}

	node *old_head = cq->tail->next;
	cq->tail->next = cq->tail->next->next;

	free(old_head);
}

void print(c_queue cq) {

	/* Empty */
	if(cq.tail == NULL){
		cout << "Its Empty\n";
		return;
	}

	node *temp = cq.tail->next;
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while(temp != cq.tail->next);

	cout << "\n";
}

int32_t main() {
	c_queue cq;
	cq.tail = NULL;

	for(int i = 0; i < 5; i++){
		enqueue(&cq, i);
	}
	print(cq);
	/* 0 1 2 3 4 */

	for(int i = 0; i < 4; i++){
		dequeue(&cq);
	}
	print(cq);
	/* 4 */

	dequeue(&cq);
	print(cq);
	/* Its Empty */
}

