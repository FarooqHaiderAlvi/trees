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

	bstNode<t>* getRoot() {
		if (root) {
			return root;
		}
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

	bstNode<t>* search(t val) {

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

	void postOrderTraversal(bstNode<t>* temp) {

		if (!temp)
			return;

		postOrderTraversal(temp->left);
		postOrderTraversal(temp->right);
		cout << temp->data << endl;

	}

	void preOrderTraversal(bstNode<t>* temp) {

		if (!temp)
			return;
		cout << temp->data << endl;
		preOrderTraversal(temp->left);
		preOrderTraversal(temp->right);

	}
	
	//these three function contribute to delete node from book
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

	void makeDeletion(bstNode<t> *& nodePtr) {
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
			 tempNodePtr = nullptr;
		 }
	 }

	void deletion(t val) {
		bstNode<t>* tempNodePtr = nullptr;
		bstNode<t>* nodePtr = root;
		bstNode<t>* parent = nullptr;

		// Search for the node to be deleted and keep track of its parent
		while (nodePtr) {
			if (nodePtr->data == val) {
				break;
			}
			else {
				parent = nodePtr;
				if (nodePtr->data > val) {
					nodePtr = nodePtr->left;
				}
				else {
					nodePtr = nodePtr->right;
				}
			}
		}

		if (nodePtr == nullptr) {
			cout << "Cannot delete empty node.\n";
			return;
		}

		// Case 1: Node has no children
		if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
			if (parent == nullptr) {
				root = nullptr;
			}
			else if (parent->left == nodePtr) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
			delete nodePtr;
		}

		// Case 2: Node has only one child
		else if ( (nodePtr->left == nullptr) != (nodePtr->right == nullptr) ) {

			if (nodePtr->left)
				tempNodePtr = nodePtr->left;
			else
				tempNodePtr = nodePtr->right;

			if (parent == nullptr) {
				root = tempNodePtr;
			}
			else if (parent->left == nodePtr) {
				parent->left = tempNodePtr;
			}
			else {
				parent->right = tempNodePtr;
			}
			delete nodePtr;
		}
		

		// Case 3: Node has both left and right children
		else {
			bstNode<t>* successorParent = nodePtr;
			bstNode<t>* successor = nodePtr->right;

			while (successor->left != nullptr) {
				successorParent = successor;
				successor = successor->left;
			}

			if (successorParent != nodePtr) {
				successorParent->left = successor->right;
			}
			else {
				successorParent->right = successor->right;
			}

			nodePtr->data = successor->data;
			delete successor;
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
	tree.insert(68);
	tree.insert(46);
	tree.insert(66);
	tree.insert(67);

	tree.deletion(20);
	tree.preOrderTraversal(tree.getRoot());

	

}