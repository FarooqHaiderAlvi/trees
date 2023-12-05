#include <iostream>
using namespace std;

template<typename t>
class bstNode {
public:
	t data;
	bstNode<t>* left;
	bstNode<t>* right;

	bstNode(int val) {
		data = val;
		left = right = nullptr;

	}
};

template<typename t>
class BST {

	bstNode<t>* root;
public:
	BST() {
		root = nullptr;
	}

	void insert(t val) {

		if (!root) {
			root = new bstNode<t>(val);
		}
		else {
			bstNode<t>* temp = root;
			bstNode<t>* prev = temp;
			while (temp) {

				if (temp->data > val) {
					prev = temp;
					temp = temp->left;
				}
				else {
					prev = temp;
					temp = temp->right;
				}

			}
			if (prev->data > val) {
				prev->left = new bstNode<t>(val);
			}
			else {
				prev->right = new bstNode<t>(val);
			}


		}


	}
	bstNode<t>* getRoot() {
		if (root) {
			return root;
		}
	}

	bstNode<t>*& search(t val) {

		bstNode<t>* temp = root;
		while (temp) {

			if (temp->data == val) {
				return temp;
			}
			else if (temp->data > val) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return NULL;
	}
	void inOrderTraversal(bstNode<t>* temp) {

		if (!temp)
			return;
		
		inOrderTraversal(temp->left);
		cout << temp->data << endl;
		inOrderTraversal(temp->right);

	}

	void remove(int num)
		 {

		 deleteNode(num, root);

		 }
		
	 void deleteNode(int num, bstNode<t> * &nodePtr)
		 {
		 if (nodePtr && num < nodePtr->data)
			 deleteNode(num, nodePtr->left);
		 else if (nodePtr && num > nodePtr->data)
			 deleteNode(num, nodePtr->right);
		 else
			 makeDeletion(nodePtr);
		 }

	 void makeDeletion(bstNode<t>*& nodePtr) {
		 // Define a temporary pointer to use in reattaching
		 // the left subtree.
		 bstNode<t>* tempNodePtr = nullptr;
		
		

		 if (nodePtr == nullptr)
			 cout << "Cannot delete empty node.\n";
		 else if (nodePtr->right == nullptr) {
			 tempNodePtr = nodePtr;
			 nodePtr = nodePtr->left; // Reattach the left child.
			 delete tempNodePtr;
			 tempNodePtr=nullptr;
		 }
		 else if (nodePtr->left == nullptr) {
			 tempNodePtr = nodePtr;
			 nodePtr = nodePtr->right; // Reattach the right child.
			
		 }
		 // If the node has two children.
		 else {
			 // Move one node to the right.
			 tempNodePtr = nodePtr->right;
			 // Go to the end left node.
			 while (tempNodePtr->left)
				 tempNodePtr = tempNodePtr->left;
			 // Reattach the left subtree.
			 tempNodePtr->left = nodePtr->left;
			 tempNodePtr = nodePtr;
			 // Reattach the right subtree.
			 nodePtr = nodePtr->right;
			 delete tempNodePtr;
		 }
	 }

};

int main() {


	BST<int> tree;
	tree.insert(20);
	tree.insert(22);
	tree.insert(65);
	tree.insert(60);
	tree.insert(25);
	tree.insert(32);
	tree.insert(43);
	tree.insert(11);
	tree.insert(9);
	tree.insert(70);
	tree.insert(46);
	tree.remove(20);
	tree.inOrderTraversal(tree.getRoot());
	
	

}