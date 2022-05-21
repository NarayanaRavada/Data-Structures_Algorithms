/**
 *        BINARY SEARCH TREE
 .* 	  author: narayana_r
 .* 	  created: 18.04.2022 11:56:04
 **/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

/*-- Creating a node --*/

node* createNode(int data) {
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

/*-- PREORDER Travesal --*/

/* root -> left -> right */
void preorder(node *root) {
	if(root != NULL) {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

/*-- INORDER Travesal --*/

/* left -> root -> right */
void inorder(node *root) {
	if(root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

/*-- POSTORDER Travesal --*/

/* left -> right -> root */
void postorder(node *root) {
	if(root != NULL) {
		inorder(root->left);
		inorder(root->right);
		cout << root->data << " ";
	}
}

/*-- Level order Travesal --*/

void levelorder(node *root) {
	
	if(root == NULL)
		return;

	queue<node*> q;
	// push the root to initialise
	q.push(root);

	while(!q.empty()) {
    	// print the the first element and remove it
		node *n = q.front();
        cout << n->data << " ";
		q.pop();

		// push left child
		if(n->left != NULL)
			q.push(n->left);

		// push right child
		if(n->right != NULL)
			q.push(n->right);
	}
}

/*-- Search in BST --*/

node* search(node *root, int data) {
	if(root == NULL || data == root->data) 
		return root;
	else if(data < root->data) 
		return search(root->left, data);
	else
		return search(root->right, data);
}

/*-- Insertion in BST --*/

node* insert(node *root, int data) {
	if(root == NULL) 
		root = createNode(data);
	else if(data < root->data) 
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);
	return root;
}

/*-- Deletion in BST --*/

node* deleteNode(node *root, int data) {
	if(root == NULL)
		return NULL;
	else if(data < root->data) 
		root->left = deleteNode(root->left, data);
	else if(data > root->data) 
		root->right = deleteNode(root->right, data);
	else {
		/* Node with no child*/
		if(root->left == NULL && root->right == NULL)
			return NULL;

		/* Node with one child*/
		else if(root->left == NULL) {
			node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL) {
			node *temp = root->left;
			delete root;
			return temp;
		} 

		/* Node with two child */
		/* replace with Largest in left subtree (OR) Smallest in the right subtree */

		node *inpre = root->left;

		while(inpre->right != NULL) 
			inpre = inpre->right;

		root->data = inpre->data;
		root->left = deleteNode(root->left, inpre->data);
	}

	return root;
}

int main() {
	node *root = NULL;
	vector<int> data = {6,4,5,3,8,7,9,10};
	for(auto &num: data) {
		root = insert(root, num);
	}
	/*         6
	       4__/ \__8
	      / \     / \
	     3   5   7   9
	                  \
	                  10
	 */

	preorder(root);
    // 6 4 3 5 8 7 9 10
	cout << "\n";
	inorder(root);
    // 3 4 5 6 7 8 9 10
	cout << "\n";
	postorder(root);
    // 3 4 5 7 8 9 10 6
	cout << "\n";
	levelorder(root);
    // 6 4 8 3 5 7 9 10
	cout << "\n";

	deleteNode(root, 5);
	/* leaf node
	           6
	       4__/ \__8
	      /       / \
	     3       7   9
	                  \
	                  10
	 */

	deleteNode(root, 4);
    /* only left child
	           6
	       3__/ \__8
	              / \
	             7   9
	                  \
	                  10
	 */

	deleteNode(root, 9);
	/* only right child
	 *         6
	       3__/ \__8
	              / \
	             7   10
	 */

	deleteNode(root, 8);
    /* with two children
	 *         6
	       3__/ \__7
	                \
					 10
	 */

	preorder(root);
	// 6 3 10 7

	return 0;
}
