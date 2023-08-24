#include<iostream>
#include"Graphs.h"
using namespace std;


int main() {
	MyGraph<int> hello(4);
	Node<int>* node_ptr1 = new Node<int>(1);
	Node<int>* node_ptr2 = new Node<int>(1);
	Node<int>* node_ptr3 = new Node<int>(2);
	Node<int>* node_ptr4 = new Node<int>(3);
	Node<int>* node_ptr5 = new Node<int>(5);
	Node<int>* node_ptr6 = new Node<int>(5);
	Node<int>* node_ptr7 = new Node<int>(7);
	Node<int>* node_ptr8 = new Node<int>(100);
	

	
	hello.connectNode(node_ptr1);
	hello.connectNode(node_ptr2);
	hello.connectNode(node_ptr3);
	hello.connectNode(node_ptr4);
	hello.connectNode(node_ptr5);
	hello.connectNode(node_ptr6);
	hello.connectNode(node_ptr8);

	node_ptr1->connectNode(node_ptr7);
	node_ptr1->connectNode(node_ptr3);
	node_ptr1->connectNode(node_ptr4);
	node_ptr1->connectNode(hello.returnRoot());


	node_ptr2->connectNode(node_ptr4);
	node_ptr2->connectNode(node_ptr5);
	node_ptr2->connectNode(node_ptr6);
	node_ptr2->connectNode(hello.returnRoot());

	node_ptr3->connectNode(node_ptr1);
	node_ptr3->connectNode(node_ptr8);
	node_ptr3->connectNode(node_ptr7);
	node_ptr3->connectNode(hello.returnRoot());

	node_ptr4->connectNode(node_ptr1);
	node_ptr4->connectNode(node_ptr2);
	node_ptr4->connectNode(hello.returnRoot());

	node_ptr5->connectNode(node_ptr6);
	node_ptr5->connectNode(node_ptr8);
	node_ptr5->connectNode(hello.returnRoot());

	node_ptr6->connectNode(node_ptr5);
	node_ptr6->connectNode(node_ptr2);
	node_ptr6->connectNode(hello.returnRoot());

	node_ptr7->connectNode(node_ptr1);
	node_ptr7->connectNode(node_ptr3);
	node_ptr7->connectNode(node_ptr8);

	node_ptr8->connectNode(node_ptr7);
	node_ptr8->connectNode(node_ptr3);
	node_ptr8->connectNode(node_ptr5);
	node_ptr8->connectNode(hello.returnRoot());

	hello.printDFS();
	hello.printBFS();
	hello.searchBFS(100);
	cout << "Done   :" << endl;


	return 0;

}



















