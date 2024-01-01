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
					if (balance < -1 && val>current->right->data) {
						leftRotate(current,val);
					}
						//right left		
					else if (balance < -1 && val < current->right->data) {

						rightRotate(current->right,val);
						leftRotate(current,val);
					}

					//left left
					else if (balance > 1 && val < current->left->data)
					{
						return rightRotate(current,val);
					}
								
				}
			


		}


	}
	void leftRotate(bstNode<t>* x, int val) {

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
			if (val > prev->data)
				prev->right = y;
			else
				prev->left = y;
		}
			
		else
			root = y;

	}


	void rightRotate(bstNode<t>* y,int val)
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
		if (val > prev->data)
			prev->right = x;
		else
			prev->left = x;
	}
	else
		root = x;
}


	bstNode<t>* getRoot() {
		if (root) {
			return root;
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