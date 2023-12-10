//#include <iostream>
//using namespace std;
//
//
//template<typename t>
//class stackNode {
//public:
//	t data;
//	stackNode<t>* next;
//public:
//	stackNode() {
//		data = nullptr;
//		next = nullptr;
//	}
//};
//
//
//template<typename t>
//class MyStack {
//	
//	stackNode<t>* top;
//public:
//	MyStack() {
//		top = nullptr;
//	}
//
//
//	void push(stackNode<t>* node) {
//		stackNode<t>* stackNodePtr = new stackNode<t>();
//		stackNodePtr = node;  // Assigning the pointer directly
//
//		if (!top)
//			top = stackNodePtr;
//		else {
//			stackNodePtr->next = top;
//			top = stackNodePtr;
//		}
//	}
//
//	void pop() {
//		
//		if (!isEmpty()) {
//			
//			top = top->next;
//			
//		}
//	
//	}
//
//	stackNode<t>* returnTop() {
//		return top;
//	}
//	bool isEmpty() {
//		return top == nullptr;
//	}
//
//};
//
//
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
//		if (!root)
//			return;
//
//		MyStack<bstNode<t>*>* stack = new MyStack<bstNode<t>*>();
//
//		stackNode<bstNode<t>*>* stackNodePtr = new stackNode<bstNode<t>*>();
//		stackNodePtr->data = root;
//
//		//first push the root;
//		stack->push(stackNodePtr);
//
//		while (!stack->isEmpty()) {
//
//			// then store the top in a object and then pop that object
//			stackNodePtr = stack->returnTop();
//			stack->pop();
//
//			cout << stackNodePtr->data->data << " ";
//
//			if (stackNodePtr->data->right) {
//				stackNode<bstNode<t>*>* rightNode = new stackNode<bstNode<t>*>();
//				rightNode->data = stackNodePtr->data->right;
//				stack->push(rightNode);
//			}
//
//			if (stackNodePtr->data->left) {
//				stackNode<bstNode<t>*>* leftNode = new stackNode<bstNode<t>*>();
//				leftNode->data = stackNodePtr->data->left;
//				stack->push(leftNode);
//			}
//		}
//	} 
//
//	void iterativeInOrder() {
//		if (!root)
//			return;
//
//		MyStack<bstNode<t>*>* stack = new MyStack<bstNode<t>*>();
//
//		stackNode<bstNode<t>*>* stackNodePtr = new stackNode<bstNode<t>*>();
//		stackNodePtr->data = root;
//
//		while (stackNodePtr->data || !stack->isEmpty()) {
//
//			while (stackNodePtr->data) {
//				stack->push(stackNodePtr);
//				stackNode<bstNode<t>*>* leftNode = new stackNode<bstNode<t>*>();
//				leftNode->data = stackNodePtr->data->left;
//				stackNodePtr = leftNode;
//
//			}
//
//			
//				stackNodePtr = stack->returnTop();
//				stack->pop();
//
//				if(stackNodePtr->data)
//				cout << stackNodePtr->data->data << " ";
//
//				if (stackNodePtr->data && stackNodePtr->data->right)
//					stackNodePtr->data = stackNodePtr->data->right;
//				else
//					stackNodePtr->data = nullptr;
//			
//		}
//	}
//
//
//
//	void iterativePostOrder() {
//		if (!root)
//			return;
//
//		MyStack<bstNode<t>*>* st = new MyStack<bstNode<t>*>();
//
//		stackNode<bstNode<t>*>* current = new stackNode<bstNode<t>*>();
//		stackNode<bstNode<t>*>* temp = new stackNode<bstNode<t>*>();
//		current->data = root;
//		temp->data = root;
//
//		while (current && current->data) {
//
//			while (current->data->left) {
//				st->push(current);
//				stackNode<bstNode<t>*>* helper = new stackNode<bstNode<t>*>();
//				helper->data= current->data->left;
//				current = helper;
//			}
//
//
//			while (current->data && (!current->data->right || current->data->right == temp->data))
//			{
//				cout << current->data->data << " ";
//				temp = current;
//				if (st->isEmpty())
//					return;
//
//				current = st->returnTop();
//				st->pop();
//			}
//
//			st->push(current);
//
//			if (current->data && current->data->right)
//			{
//				stackNode<bstNode<t>*>* helper = new stackNode<bstNode<t>*>();
//				helper->data = current->data->right;
//				current = helper;
//				
//			}
//				
//			else
//			{
//				stackNode<bstNode<t>*>* helper = new stackNode<bstNode<t>*>();
//				helper->data = nullptr;
//				current = helper;
//			}
//              
//
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