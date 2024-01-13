//#include <iostream>
//using namespace std;
//#include <stack>
//class bstNode {
//public:
//	int data;
//	bstNode* left;
//	bstNode* right;
//	bstNode* next;
//	bstNode(int val) {
//		data = val;
//		left = nullptr;
//		right = nullptr;
//		next = nullptr;
//	}
//};
//class Queue {
//	bstNode* front, * rear;
//public:
//	Queue() {
//		front = rear = NULL;
//	}
//	void enque(bstNode* temp) {
//
//
//		if (front == NULL) {
//			front = rear = temp;
//		}
//		else {
//			rear->next = temp;
//			rear = temp;
//		}
//	}
//	bstNode* deque() {
//		bstNode* temp = front;
//		if (front)
//			front = front->next;
//		return temp;
//	}
//};
//class Bst :public Queue {
//	bstNode* root;
//public:
//	Bst() {
//		root = nullptr;
//	}
//
//	bstNode* getRoot() {
//		return root;
//	}
//
//	void insert(int val) {
//
//		if (!root)
//			root = new bstNode(val);
//		else {
//			bstNode* temp = root;
//			bstNode* prev = temp;
//			while (temp) {
//				if (temp->data > val) {
//					prev = temp;
//					temp = temp->left;
//				}
//				else {
//					prev = temp;
//					temp = temp->right;
//				}
//			}
//			if (prev->data > val)
//				prev->left = new bstNode(val);
//			else prev->right = new bstNode(val);
//
//		}
//	}
//
//	
//
//	
//	void breathFirstTraversal() {
//
//		Queue q;
//		bstNode* temp = root;
//		if (temp) {
//			q.enque(temp);
//			while (temp) {
//				temp = q.deque();
//				if (temp) {
//					cout << temp->data << " ";
//					if (temp->left)
//						q.enque(temp->left);
//					if (temp->right)
//						q.enque(temp->right);
//				}
//			}
//		}
//	}
//	
//
//
//
//};
//
//int main() {
//
//
//
//		Bst tree;
//		tree.insert(20);
//		tree.insert(10);
//		tree.insert(25);
//		tree.insert(8);
//		tree.insert(12);
//		tree.insert(22);
//		tree.insert(30);
//		
//		tree.breathFirstTraversal();
//
//
//}
//
//
