#include <iostream>
using namespace std;
#include <stack>
template<typename t>
class bstNode {
public:
	t data;
	int height;
	bstNode<t>* left;
	bstNode<t>* right;

	bstNode(int val) {
		data = val;
		left = right = nullptr;
		height = 1;

	}
};

template<typename t>
class BST {

	bstNode<t>* root;
public:
	BST() {
		root = nullptr;
	}

	int getHeight(bstNode<t>* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
	bstNode<t>* getRoot() {
		if (root) {
			return root;
		}
	}
    int max(int a, int b)
{
	return (a > b) ? a : b;
}

	void insert(t val) {
		stack<bstNode<t>*> st;
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
					st.push(prev);
					
				}
				else {
					prev = temp;
					temp = temp->right;
					st.push(prev);
				}

			}
			if (prev->data > val) {
				prev->left = new bstNode<t>(val);

				
			}
			else {
				prev->right = new bstNode<t>(val);
			}

			while (!st.empty())
			{
				bstNode<t>* current = st.top();
				st.pop();
				current->height = 1 + max(getHeight(current->left), getHeight(current->right));

				int balance = getHeight(current->left) - getHeight(current->right);

				bstNode<t>* leftArm = current->left;
				bstNode<t>* rightArm = current->right;

				//right right  
				if (balance < -1 && getHeight(rightArm->left) < getHeight(rightArm->right)) {
					leftRotate(current);
				}
				//right left		
				else if (balance < -1 && getHeight(rightArm->left) > getHeight(rightArm->right)) {

					rightRotate(current->right);
					leftRotate(current);
				}

				//left left
				else if (balance > 1 && getHeight(leftArm->left) > getHeight(leftArm->right))
				{
					rightRotate(current);
				}
				//left right
				else if (balance > 1 && getHeight(leftArm->left) < getHeight(leftArm->right)) {
					leftRotate(current->left);
					rightRotate(current);
				}

			}
			


		}


	}

	void deletion(t val) {

		stack<bstNode<t>*> st;

		bstNode<t>* tempNodePtr = nullptr;
		bstNode<t>* nodePtr = root;
		bstNode<t>* parent = nullptr;
		bstNode<t>* stNode = nullptr;
		// Search for the node to be deleted and keep track of its parent
		while (nodePtr) {
			if (nodePtr->data == val) {
				break;
			}
			else {
				parent = nodePtr;
				stNode = nodePtr;
				st.push(stNode);
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
		// Case 2: Node has only a left child
		else if (nodePtr->left != nullptr && nodePtr->right == nullptr) {
			tempNodePtr = nodePtr->left;
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
		// Case 3: Node has only a right child
		else if (nodePtr->left == nullptr && nodePtr->right != nullptr) {
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


		while (!st.empty())
		{
			bstNode<t>* current = st.top();
			st.pop();
			current->height = 1 + max(getHeight(current->left), getHeight(current->right));

			int balance = getHeight(current->left) - getHeight(current->right);

			bstNode<t>* leftArm = current->left;
			bstNode<t>* rightArm = current->right;

			//right right  
			if (balance < -1 && getHeight(rightArm->left) < getHeight(rightArm->right) ) {
				leftRotate(current );
			}
			//right left		
			else if (balance < -1 && getHeight(rightArm->left) > getHeight(rightArm->right) ) {

				rightRotate(current->right);
				leftRotate(current);
			}

			//left left
			else if (balance > 1 && getHeight(leftArm->left) > getHeight(leftArm->right) )
			{
				rightRotate(current);
			}
			//left right
			else if (balance > 1 && getHeight(leftArm->left) < getHeight(leftArm->right)) {
				leftRotate(current->left);
				rightRotate(current);
			}

		}
	}





	void leftRotate(bstNode<t>* x) {

		bstNode<t>* temp = root;
		bstNode<t>* prev = nullptr;
		while (temp) {
			if (temp->data == x->data)
				break;
			else if (temp->data > x->data)
			{
				prev = temp;
				if(temp->left)
				temp = temp->left;
			}

			else {
				prev = temp;
				if(temp->right)
				temp = temp->right;
			}
				

		}

			bstNode<t>* y = x->right;
		bstNode<t>* T2 = y->left;
	
		// Perform rotation 
		y->left = x;
		x->right = T2;
	
		// Update heights 
		x->height = max(getHeight(x->left),
			getHeight(x->right)) + 1;
		y->height = max(getHeight(y->left),
			getHeight(y->right)) + 1;

		if (prev) {
			if (y->data > prev->data)
				prev->right = y;
			else
				prev->left = y;
		}
			
		else
			root = y;

	}
	void rightRotate(bstNode<t>* y)
{
		bstNode<t>* temp = root;
		bstNode<t>* prev = nullptr;
		while (temp) {
			if (temp->data == y->data)
				break;
			else if (temp->data > y->data)
			{
				prev = temp;
				if(temp->left)
				temp = temp->left;
			}

			else
			{
				prev = temp;
				if (temp->right)
					temp = temp->right;
			}
				

		}

		bstNode<t>* x = y->left;
		bstNode<t>* T2 = x->right;

	// Perform rotation 
	x->right = y;
	y->left = T2; 

	// Update heights 
	y->height = max(getHeight(y->left),
		getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),
		getHeight(x->right)) + 1;
	 
	if (prev) {
		if (x->data > prev->data)
			prev->right = x;
		else
			prev->left = x;
	}
	else
		root = x;
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
    void preOrderTraversal(bstNode<t>* temp) {

		if (!temp)
			return;
		cout << temp->data << " " << temp->height << endl;
		preOrderTraversal(temp->left);
		preOrderTraversal(temp->right);

	}

};


int main() {


	BST<int> tree;
	//tree.insert(5);
	//tree.insert(3);
	//tree.insert(6);
	//tree.insert(4);
	//tree.deletion(6);
	
	/*tree.insert(65);
	tree.insert(60);
	tree.insert(25);
	tree.insert(32);
	tree.insert(43);
	tree.insert(11);
	tree.insert(9);
	tree.insert(70);
	tree.insert(68);
	tree.insert(46);*/




	tree.insert( 7);
	 tree.insert( 14);
	 tree.insert( 2);
	 tree.insert( 5);
	 tree.insert( 10);
	 tree.insert( 33);
	 tree.insert( 56);
	 tree.insert( 30);
	 tree.insert( 15);
	 tree.insert( 25);
	 tree.insert( 66);
	tree.insert( 70);
	 tree.insert( 4);
	
	tree.preOrderTraversal(tree.getRoot());

	

}