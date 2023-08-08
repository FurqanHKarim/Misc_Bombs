#include<iostream>
using namespace std;



struct Node {
	int Value;
	Node* R_Next;
	Node* L_Next;



	Node() {
		R_Next = NULL;
		L_Next = NULL;
	}

	Node(int _Value) {
		Value = _Value;
		R_Next = NULL;
		L_Next = NULL;
	}
    
};

class BinaryTree {
private:
	Node* DaNode;


public:
	BinaryTree() {

	}

	BinaryTree(int _Value) {
		DaNode = new Node(_Value);
	}


	void insersion(int _Value) {


		//there are only a few cases where you can insert a new node
		//just make this new Node (first order of business)
		Node* new_boi = new Node(_Value);

		//1) if there is no root
		if (DaNode == NULL) 
		{
			DaNode = new_boi;
			return;
		}

		//since the first condition isnt working so now you need to traverse
		BinaryTree traverser;
		
		traverser.DaNode = this->DaNode;

		//2 & 3)if there is a Root and the value is smaller than the root
		if (_Value < traverser.DaNode->Value)
		{
			//2) if there isnt a Node on the Left
			if (traverser.DaNode->L_Next == NULL) 
			{
				traverser.DaNode->L_Next = new_boi;
				return ;
			}
			else
			{	
				//3) if there is Node to the Left
				traverser.DaNode = traverser.DaNode->L_Next;
				traverser.insersion(_Value);
				return;
			}

		}
		//4 & 5) if there is a root and the value is greater than the root
		if (_Value > traverser.DaNode->Value) {
			//4) if there is no Node on the Right
			if (traverser.DaNode->R_Next == NULL) {
				traverser.DaNode->R_Next = new_boi;
				return;
			}
			else
			{//5) is there is a Node to the Right
				traverser.DaNode = traverser.DaNode->R_Next;
				traverser.insersion(_Value);
				return;
			}

		}

		if (_Value == DaNode->Value) {
			return;
		}


	}

};













int main() {

	BinaryTree hello;
	BinaryTree wut(90);
	hello.insersion(90);
	wut.insersion(80);
	wut.insersion(100);
	wut.insersion(60);
	wut.insersion(110);
	wut.insersion(70);
}