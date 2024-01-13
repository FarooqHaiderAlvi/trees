//#include <iostream>
//#include <queue>
//using namespace std;
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
//
//public:
//
//	BST() {
//
//		root = nullptr;
//	}
//
//	bstNode<t>* getRoot() {
//		if (root) {
//			return root;
//		}
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
//		}
//	}
//
//	void iterativeLevelOrderTraversal() {
//		queue<bstNode<t>*> q;
//		bstNode<t>* temp = root;
//
//		if (temp) {
//			q.push(temp);
//			while (!q.empty()) {
//
//				temp = q.front();
//				q.pop();
//				cout << temp->data << " ";
//
//				if (temp->left)
//					q.push(temp->left);
//				if (temp->right)
//					q.push(temp->right);
//			}
//		}
//	}
//};
//
//
//int main() {
//
//	    BST<int> tree;
//	    tree.insert(20);
//		tree.insert(22);
//		tree.insert(65);
//		tree.insert(60);
//		tree.insert(25);
//		tree.insert(32);
//		tree.insert(43);
//		tree.insert(11);
//		tree.insert(9);
//		tree.insert(70);
//		tree.insert(68);
//		tree.insert(46);
//
//	    tree.iterativeLevelOrderTraversal();
//
//}