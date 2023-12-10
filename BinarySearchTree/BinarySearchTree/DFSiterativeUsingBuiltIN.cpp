//#include <iostream>
//using namespace std;
//
//#include <stack>
//
//
//template<typename t>
//class bstNode {
//public:
//	t data;
//	bstNode<t>* left;
//	bstNode<t>* right;
//
//	bstNode(int val) {
//		data = val;
//		left = right = nullptr;
//
//	}
//};
//
//template<typename t>
//class BST {
//
//	bstNode<t>* root;
//public:
//	BST() {
//		root = nullptr;
//	}
//
//	void insert(t val) {
//
//		if (!root) {
//			root = new bstNode<t>(val);
//		}
//		else {
//			bstNode<t>* temp = root;
//			bstNode<t>* prev = temp;
//			while (temp) {
//
//				if (temp->data > val) {
//					prev = temp;
//					temp = temp->left;
//				}
//				else {
//					prev = temp;
//					temp = temp->right;
//				}
//
//			}
//			if (prev->data > val) {
//				prev->left = new bstNode<t>(val);
//			}
//			else {
//				prev->right = new bstNode<t>(val);
//			}
//
//
//		}
//
//
//	}
//	bstNode<t>* getRoot() {
//		if (root) {
//			return root;
//		}
//	}
//
//	void iterativePreOrder() {
//		
//		stack<bstNode<t>*> st;
//		bstNode<t>* temp = root;
//		st.push(temp);
//		
//
//		while (!st.empty()) {
//			temp = st.top();
//			st.pop();
//			cout << temp->data << endl;
//
//			if (temp->right)
//				st.push(temp->right);
//			if (temp->left)
//				st.push(temp->left);
//		}
//	}
//
//	void iterativeInOrder() {
//		
//
//		stack<bstNode<t>*> st;
//		bstNode<t>* temp = root;
//
//		while (temp || !st.empty()) {
//
//			while (temp) {
//				st.push(temp);
//				temp = temp->left;
//			}
//
//			temp = st.top();
//			st.pop();
//			cout << temp->data << "  ";
//
//			
//				temp = temp->right;
//
//		}
//	}
//
//
//	void iterativePostOrder() {
//		stack<bstNode<t>*> st;
//		bstNode<t>* current = root;
//		bstNode<t>* temp = root;
//
//		while (current) {
//
//			while (current->left) {
//				st.push(current);
//				current = current->left;
//			}
//
//			while (current && (!current->right || current->right == temp)) {
//
//				cout << current->data << " ";
//				temp = current;
//				if (st.empty()) {
//					return;
//				}
//				current = st.top();
//
//				st.pop();
//
//			}
//			st.push(current);
//
//			if (current && current->right)
//				current = current->right;
//			else
//				current = nullptr;
//		}
//
//		
//	}
//
//};
//
//
//int main() {
//
//
//	BST<int> tree;
//	tree.insert(20);
//	tree.insert(10);
//	tree.insert(25);
//	tree.insert(8);
//	tree.insert(12);
//	tree.insert(22);
//	tree.insert(30);
//
//
//	tree.iterativePostOrder();
//
//
//
//
//
//}