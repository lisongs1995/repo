#include <stack>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
typedef char elemType;
struct BiNode {
	elemType data;
	BiNode *left, *right;	
	BiNode(int elem):
		data(elem),
		left(nullptr),
		right(nullptr) 
		{}
};
void rPreOrder(BiNode* root){
	if(!root)
		return;
	cout << root->data;
	rPreOrder(root->left);
	rPreOrder(root->right);
}
void preOrder(BiNode* root){
	stack<BiNode*> S;
	BiNode* worker = root;
	while(worker || !S.empty()){
		while(worker){
			cout << worker->data << endl;
			S.push(worker);
			worker = worker->left;
		}
		if(!S.empty()){	
			worker = S.top();
			S.pop();
			worker = worker->right;
		}
	}
}
void rInOrder(BiNode* root){
	if(!root)
		return;
	rInOrder(root->left);
	cout << root->data << endl;
	rInOrder(root->right);
}
void inOrder(BiNode* root){
	BiNode* worker = root;
	stack<BiNode* > S;
	while(worker || !S.empty()){
		while(worker){
			S.push(worker);
			worker = worker->left;
		}
		if(!S.empty()){
			worker = S.top();
			S.pop();
			cout << worker->data << endl;
			worker = worker->right;
		}
	}
}
void postOrder(BiNode* root){
	stack<BiNode* > S;
	BiNode* worker = root;
	BiNode* helper = nullptr;
	while(worker || !S.empty()){
		if(worker){
			S.push(worker);
			worker = worker->left;
		}
		else{
			worker = S.top();
			//  right still not be visited, and right is not empty.
			if(worker->right && worker->right != helper)
				worker = worker->right;
			// right visited or be empty, pop stack to visit.
			else{
				worker = S.top();
				S.pop();
				cout << worker->data << endl;
				helper = worker;
				worker = nullptr;
			} 
		}
	} 
}
void rPostOrder(BiNode* root){
	if(!root)
		return;
	rPostOrder(root->left);
	rPostOrder(root->right);
	cout << root->data << endl;
}
void levelOrder(BiNode* root){
	if(!root)
		return;
	BiNode* worker = root;
	queue<BiNode* > Q;
	Q.push(worker);
	while(!Q.empty()){
		worker = Q.front();
		Q.pop();
		cout << worker->data << endl;
		if(worker->left)
			Q.push(worker->left);
		if(worker->right)
			Q.push(worker->right);
	}
}
int main(){
	BiNode a1('A');
	BiNode a2('B');
	BiNode a3('C');
	BiNode a4('D');
	BiNode a5('E');
	BiNode a6('F');
	BiNode a7('G');
	a1.left = &a2;
	a1.right = &a3;
	a2.left = &a4;
	a3.left = &a5;
	a3.right = &a6;
	a4.right = &a7;
	BiNode* root = &a1;
	//preOrder(root);
	//inOrder(root);
	//postOrder(root);
	levelOrder(root);

}
