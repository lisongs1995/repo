#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int ele):
		data(ele),
		next(nullptr)
		{}
};
void test(Node*& p){
//	p = NULL;
	if(!p)
		p = new Node(10);
}

void test1(Node*& p){
	test(p);
}
int main(){
	Node* p;
	test1(p);
	cout << p->data << endl; // right 5

}
