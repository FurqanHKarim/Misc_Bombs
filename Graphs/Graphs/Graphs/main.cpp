#include<iostream>
#include"Graphs.h"
using namespace std;


int main() {
	MyGraph<double> hello(4);

	Node<double>* node_ptr1 = new Node<double>(6);
	Node<double>* node_ptr2 = new Node<double>(5);
	Node<double>* node_ptr3 = new Node<double>(4.1);
	Node<double>* node_ptr4 = new Node<double>(3.3);
	Node<double>* node_ptr5 = new Node<double>(3);
	Node<double>* node_ptr6 = new Node<double>(2);
	Node<double>* node_ptr7 = new Node<double>(1);
	Node<double>* node_ptr8 = new Node<double>(7);
	Node<double>* node_ptr9 = new Node<double>(1.5);
	Node<double>* node_ptr10 = new Node<double>(1.7);
	Node<double>* node_ptr11 = new Node<double>(1.8);

	hello.connectNode(node_ptr1,1);
	hello.connectNode(node_ptr6,1);

	node_ptr1->connectNode(node_ptr2,1);
	node_ptr1->connectNode(node_ptr8,1);
	node_ptr1->connectNode(hello.returnRoot(), 1);

	node_ptr2->connectNode(node_ptr3,1);
	node_ptr2->connectNode(node_ptr1, 1);

	node_ptr3->connectNode(node_ptr2, 1);

	node_ptr4->connectNode(node_ptr5, 1);

	node_ptr6->connectNode(node_ptr5,1);
	node_ptr6->connectNode(node_ptr7,1);
	node_ptr6->connectNode(hello.returnRoot(), 1);

	node_ptr5->connectNode(node_ptr4,1);
	node_ptr5->connectNode(node_ptr6, 1);


	node_ptr7->connectNode(node_ptr9,1);
	node_ptr7->connectNode(node_ptr6, 1);

	node_ptr9->connectNode(node_ptr10,1);
	node_ptr9->connectNode(node_ptr7, 1);

	node_ptr10->connectNode(node_ptr11,1);
	node_ptr10->connectNode(node_ptr9, 1);

	//node_ptr8->connectNode(node_ptr11,1);
	node_ptr8->connectNode(node_ptr1, 1);





	/*Node<int>* node_ptr1 = new Node<int>(1);
	Node<int>* node_ptr2 = new Node<int>(1);
	Node<int>* node_ptr3 = new Node<int>(2);
	Node<int>* node_ptr4 = new Node<int>(3);
	Node<int>* node_ptr5 = new Node<int>(5);
	Node<int>* node_ptr6 = new Node<int>(5);
	Node<int>* node_ptr7 = new Node<int>(7);
	Node<int>* node_ptr8 = new Node<int>(100);
	

	
	hello.connectNode(node_ptr1,1);
	hello.connectNode(node_ptr2,1);
	hello.connectNode(node_ptr3, 1);
	hello.connectNode(node_ptr4, 1);
	hello.connectNode(node_ptr5, 1);
	hello.connectNode(node_ptr6, 1);
	hello.connectNode(node_ptr8, 1);

	node_ptr1->connectNode(node_ptr7, 1);
	node_ptr1->connectNode(node_ptr3, 1);
	node_ptr1->connectNode(node_ptr4, 1);
	node_ptr1->connectNode(hello.returnRoot(), 1);


	node_ptr2->connectNode(node_ptr4, 1);
	node_ptr2->connectNode(node_ptr5, 1);
	node_ptr2->connectNode(hello.returnRoot(), 1);

	node_ptr3->connectNode(node_ptr1, 1);
	node_ptr3->connectNode(node_ptr8, 1);
	node_ptr3->connectNode(node_ptr7, 1);
	node_ptr3->connectNode(hello.returnRoot(), 1);

	node_ptr4->connectNode(node_ptr1, 1);
	node_ptr4->connectNode(node_ptr2, 1);
	node_ptr4->connectNode(hello.returnRoot(), 1);

	node_ptr5->connectNode(node_ptr6, 1);
	node_ptr5->connectNode(node_ptr8, 1);
	node_ptr5->connectNode(hello.returnRoot(), 1);

	node_ptr6->connectNode(node_ptr5, 1);
	node_ptr6->connectNode(node_ptr8, 1);
	node_ptr6->connectNode(hello.returnRoot(), 1);

	node_ptr7->connectNode(node_ptr1, 1);
	node_ptr7->connectNode(node_ptr3, 1);
	node_ptr7->connectNode(node_ptr8, 1);

	node_ptr8->connectNode(node_ptr7, 1);
	node_ptr8->connectNode(node_ptr3, 1);
	node_ptr8->connectNode(node_ptr5, 1);
	node_ptr8->connectNode(hello.returnRoot(), 1);*/



	hello.printDFS();
	hello.printBFS();
	hello.searchBFS(7);
	hello.greedySearch(1.8);
	cout << "Done   :" << endl;


	return 0;
}



















