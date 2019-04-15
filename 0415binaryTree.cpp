#include <iostream>
using namespace std;
template <class T> class Tree;
template <class T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
public:
	TreeNode(T element, TreeNode<T> *lChild = NULL, TreeNode<T> *rChild = NULL) :data(element), leftChild(lChild), rightChild(rChild) {};
};
template <class T>
class Tree {
private:
	TreeNode<T> *root;
public:
	Tree(TreeNode<T> *r = NULL) :root(r) {};
	void InsertNode(const T &insertData);
	void Inorder(); void Inorder(TreeNode<T> *currentNode);
	void Preorder(); void Preorder(TreeNode<T> *currentNode);
	void Postorder(); void Postorder(TreeNode<T> *currentNode);
	
};
template <class T>
void Tree<T>::Preorder() {
	Preorder(root);
}
template <class T>
void Tree<T>::Preorder(TreeNode<T> *currentNode) {
	if (currentNode) {
		cout << currentNode->data << " ";
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}
template <class T>
void Tree<T>::Inorder() {
	Inorder(root);
}
template <class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		cout << currentNode->data << " ";
		Inorder(currentNode->rightChild);
	}
}
template <class T>
void Tree<T>::Postorder() {
	Postorder(root);
}
template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		cout << currentNode->data << " ";
	}
}
template <class T>
void Tree<T>::InsertNode(const T &insertData) {
	TreeNode<T> *current = root, *parent = NULL;
	TreeNode<T> *insertNode = new TreeNode<T>(insertData);
	cout << insertData << "";
	while (current) {
		parent = current;
		if (insertData < current->data) {
			current = current->leftChild;
		}
		else if (insertData > current->data)current = current->rightChild;
		else {
			current->data = insertData;
			return;
		}
	}
	if (root)
		if (insertData < parent->data)parent->leftChild = insertNode;
		else parent->rightChild = insertNode;
	else
		root = insertNode;
}

int main() {
	Tree<char> *tree = new Tree<char>();
	char inputChar[10] = { 'g', 'q', 'A', 'E', 't', '0', 'k', 'm', 'x', '!' };
	cout << "=====입력값=====" << endl;
	for (char i = 0; i < 10; i++)
		tree->InsertNode(inputChar[i]);

	tree->Preorder();
	cout << "====Preorder 출력값====" << endl;
	
	tree->Inorder();
	cout << "====Inorder 출력값====" << endl;
	
	tree->Postorder();
	cout << "===Postorder 출력값====" << endl;
	
}
