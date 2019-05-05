#include <iostream>
#include <string>
#define IDX 11
using namespace std;
template <class K, class E> class BST;
template <class K, class E>
class TreeNode {
	friend class BST<K, E>;
public:
	TreeNode(K d1 = 0, E d2 = 0, TreeNode<K, E> *l = NULL, TreeNode<K, E> *r = NULL) : key(d1), data(d2), leftChild(l), rightChild(r) {};
private:
	K key; E data;
	TreeNode<K, E> *leftChild;
	TreeNode<K, E> *rightChild;
};
template <class K, class E>
class BST {
private:
	TreeNode<K, E> *root;
public:
	BST(TreeNode<K, E> *r = NULL) :root(r) {}
	bool isEmpty() const { return root == NULL; }
 	//E SearchBST(const K inputkey);
 	void Insert(const K keyData, const E stringData);
 	void Delete(K delKey);
 	void Preorder(); void Preorder(TreeNode<K, E> *currentNode);
};
template<class K, class E>
void BST<K, E>::Insert(const K keyData, const E stringData) {
 	TreeNode<K, E> *current = root, *parent = NULL;
 	while (current) {
  		parent = current;
  		if (keyData < current->key) {
   			current = current->leftChild;
  		}
 	 	else if (keyData > current->key) 
			current = current->rightChild;
 	 	else {
   			current->data = stringData;
   			return;
  		}	
 	}
 	current = new TreeNode<K, E>(keyData, stringData);
 	if (root)
  		if (keyData < parent->key)parent->leftChild = current;
  		else parent->rightChild = current;
	else
  		root = current;
}
template <class K, class E>
void BST<K, E>::Delete(const K delKey) {
	bool found = false;
	TreeNode<K, E> *parent = NULL;
	TreeNode<K, E> *current = root;
	if (current == NULL) {
  		cout << "Tree is empty" << endl; return;
 	}
 	while (current != NULL) {
  		if (current->key == delKey) {
   			found = true; break;
 		}
  		else {
   			parent = current;
   			if (delKey > (current->key)) 
				current = current->rightChild;
   			else 
				current = current->leftChild;
  		}		
 	}
 	if (found) {
  		cout << endl;
  		cout << "Key값:" << current->key << ", Data값:" << current->data << "을 삭제하였습니다." << endl;
  		cout << endl;
 	}
 	else {
  		cout << endl;
  		cout << "Tree에는 찾는 값이 없습니다" << endl;
  		cout << endl;
 	}

 	//Case1 : Removing a Leaf Node
 	if (current->leftChild == NULL && current->rightChild == NULL) {
 		if (parent->leftChild == current)
   			parent->leftChild = NULL;
  		else
   			parent->rightChild = NULL;

  		delete current;

  		cout << endl;
  		cout << "Key value " << delKey << "Node has been moved from the Tree." << endl;
  		cout << endl;
  		return;
 	}
	 //Case2 : 자식노드가 1개
 	if ((current->leftChild == NULL && current->rightChild != NULL) || 
  		(current->leftChild != NULL && current->rightChild == NULL)) {
  		//삭제노드의 자식노드가 오른쪽에 있는 경우
  		if (current->leftChild == NULL && current->rightChild != NULL) {
   			//부모노드의 왼쪽이 삭제노드인 경우
			if (parent->leftChild == current) {
    				parent->leftChild = current->rightChild;
    				delete current;
   			}
			//부모노드의 오른쪽이 삭제노드인 경우
   			else {
    				parent->rightChild = current->rightChild;
    				delete current;
   			}
  		}
  		//삭제노드의 자식노드가 왼쪽인 경우
  		else {
   			if (parent->leftChild == current) {
    				parent->leftChild = current->leftChild;
    				delete current;
   			}
   			else {
    				parent->rightChild = current->leftChild;
    				delete current;
   			}
  		}
	}
 	//Case3: 자식노드가 2개인 경우 왼쪽 서브트리 중 가장 작은 값을 검색
 	if (current->leftChild != NULL && current->rightChild != NULL) {
  		//삭제노드 중 자식노드가 오른쪽노드를 갖지 않는 경우
  		if ((current->leftChild)->rightChild == NULL) {
   			TreeNode<K, E> *nextNode = current->leftChild;
   			current->key = nextNode->key;
   			current->data = nextNode->data;
   			current->leftChild = nextNode->leftChild; 
			delete nextNode;
  		}
  		else {
   			//왼쪽 서브트리에서 가장 큰노드 검색
   			TreeNode<K, E>* rightCurrent; 
			TreeNode<K, E> *rightCurrentParent;
   			rightCurrentParent = current->leftChild;
   			rightCurrent = (current->leftChild)->rightChild;
   			while(rightCurrent->rightChild != NULL){ //오른쪽노드 중 가장 오른쪽노드
    				rightCurrentParent = rightCurrent; 
     				rightCurrent = rightCurrent->rightChild;
   			} //가장 오른쪽에 있는 노드값을 삭제노드로 이동
   			current->key = rightCurrent->key; 
			current->data = rightCurrent->data;
   			if(rightCurrent->leftChild == NULL) { //왼쪽 자식이 없는 경우 삭제
    				rightCurrentParent->rightChild = NULL; 
				delete rightCurrent;
 			}
 			else if(rightCurrent->leftChild !=NULL) { //가장 오른쪽노드가 왼쪽 노드가 있는 경우 증조부에 노드 연결
 				if(rightCurrentParent->leftChild !=NULL) { //증조부에 왼쪽 노드가 있는경우 증조부 오른쪽에 연결
					rightCurrentParent->rightChild = rightCurrent->leftChild;
  					delete rightCurrent;
				}
				else { //증조부에 왼쪽노드가 없는경우 증조부 왼쪽에 연결
					rightCurrentParent->leftChild = rightCurrent->leftChild;
					delete rightCurrent;
				}
			}	
		} 
	}
}
template <class K, class E>
void BST<K, E>::Preorder() {
	Preorder(root);
}
template <class K, class E>
void BST<K, E>::Preorder(TreeNode<K, E> *currentNode) {
	if (currentNode) {
 		cout << currentNode->data << " "<<endl;
  		Preorder(currentNode->leftChild);
  		Preorder(currentNode->rightChild);
 	}
}
int main() {
 	BST<int, string> *bst = new BST<int, string>();
 	int insertArrKey[6] = { 50, 15, 80, 30, 59, 90 };
 	string insertArrValue[6] = { "King","Queen", "Good", "List", "Value", "Global" };
 	for (int i = 0; i < 6; i++) {
  		bst->Insert(insertArrKey[i], insertArrValue[i]);
 	}
 	cout << "===자료 검색===" << endl;
 	//bst->SearchBst(30);

 	cout << "===전위 표기===" << endl;
 	bst->Preorder();
 	bst->Delete(15);
 	bst->Preorder();
} 
