//-//-//-//-//-//-//-//-//
//-/   Binary Trees   /-//
//-//-//-//-//-//-//-//-//

/* Binary trees are those which have atmost 2 child nodes */

#include<iostream>
using namespace std;

struct node {
	int data;
	node *left, *right;

	node(int val = 0) {
		data = val;

		left = NULL;
		right = NULL;
	}
};

int main () {

	node *root = NULL;

	root = new node(1);
	/* Tree is    1
	             / \
	          NULL  NULL 
	*/

	root->left = new node(2);
	root->right = new node(3);
	/* Tree is   1
	            / \
			   2   3
	*/
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left =new node(6);
	root->right->right = new node(7);
	/* Tree is   1
	            / \
			   2   3
			  / \ / \
			 4  5 6  7
	*/

	return 0;
}
