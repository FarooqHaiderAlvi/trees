//#include <iostream>
//using namespace std;
//
//template<typename t>
//class treeNode {
//
//public:
//
//	t data;
//	treeNode* left;
//	treeNode* right;
//
//	treeNode(t val) {
//
//		this->data = val;
//		this->left = this->right = NULL;
//	}
//};
//
//template<typename t>
//class treeLinkList {
//
//	treeNode<t>* root;
//
//public:
//
//	void setRoot(t val) {
//		root = new treeNode<t>(val);
//	}
//	void setLeftChild(t val) {
//		treeNode<t>* temp = new treeNode<t>(val);
//		if (root) {
//			root->left = temp;
//		}
//	}
//
//	void setRightChild(t val) {
//		treeNode<t>* temp = new treeNode<t>(val);
//		if (root) {
//			root->right = temp;
//		}
//	}
//
//	void preOrder(treeNode<t>* parent) {
//
//			if (!parent)
//			return;
//			cout << parent->data;
//			preOrder(parent->left);
//			preOrder(parent->right);
//
//    }
//
//	treeNode<t>* returnRoot()
//	{
//		return root;
//	}
//		
//};
//
//int main() {
//
//
//	treeLinkList<int> tree;
//	tree.setRoot(1);
//	tree.setLeftChild(2);
//	tree.setRightChild(3);
//
//	cout << endl;
//	
//	tree.preOrder(tree.returnRoot());
//	return 0;
//	
//	
//
//
//}