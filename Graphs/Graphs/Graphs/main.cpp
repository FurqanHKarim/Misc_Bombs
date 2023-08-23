#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;



template<class T>
struct Node {
	T value;
	vector<Node*> neighbours;
	unordered_map<Node*, bool> check;
	
	Node() 
	{
		value = NULL;
		neighbours.clear();

	}

	Node(const T& value_) 
	{
		value = value_;
		neighbours.clear();

	}

	void connectNode(Node<T> *inter) 
	{
		if (checkNeighbour(inter))
		{
			neighbours.push_back(inter);
			check.insert_or_assign(inter, true);
		}
		else
		{
			cout << "Already connected :" << endl;
		}

		return;

	}

	bool checkNeighbour(Node<T>* suspect)
	{
		if (check[suspect])
			return 0;


		return 1;
	}


};

template<class T>
class MyGraph {


private:
	Node<T>* root_node_;



public:
	MyGraph() 
	{
		root_node_ = {};

	}

	MyGraph(const T& value) 
	{
		Node<T>* temp = new Node<T>(value);
		root_node_ = temp;
	}

	void connectNode(Node<T> *inter) 
	{
		root_node_->connectNode(inter);

	}

	Node<T>* returnRoot() 
	{
		return this->root_node_;
		
	}

	void printBFS()
	{
		unordered_map<Node<T>*, bool> visited;
		queue<Node<T>*> cur_queue;
		Node<T>* temp;

		cur_queue.push(this->root_node_);
		visited.insert_or_assign(this->root_node_,true);
		temp = cur_queue.front();
		
		while (!cur_queue.empty())
		{
			temp = cur_queue.front();
			cout << cur_queue.front()->value<<" ";
			cur_queue.pop();
			for (size_t i = 0; i < temp->neighbours.size(); i++)
			{	
				if(!visited[temp->neighbours[i]])
				{
					cur_queue.push(temp->neighbours[i]);
					visited.insert_or_assign(temp->neighbours[i], true);

				}
				

			}
		}
	}

	void printDFS() 
	{
		unordered_map<Node<T>*, bool> visited;
		stack<Node<T>*> curr_queue;
		Node<T>* temp;

		visited.insert_or_assign(this->root_node_, true);
		temp = this->root_node_;
		curr_queue.push(temp);

		while (curr_queue.size())
		{
			cout << curr_queue.top()->value << " ";
			temp = curr_queue.top();
			curr_queue.pop();

			for (size_t i = 0; i < temp->neighbours.size(); i++)
			{
				if (!visited[temp->neighbours[i]])
				{
					curr_queue.push(temp->neighbours[i]);
					visited.insert_or_assign(temp->neighbours[i], true);
				}
			}
		}
		cout << endl;
	}
};


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
	cout << "Done   :" << endl;


	return 0;

}



















