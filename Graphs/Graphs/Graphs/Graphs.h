#ifndef Graphs
#define Graphs

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;






template<class T>
struct Node {

	struct Edge {
		Node<T>* _node;
		uint64_t _distance;
	};

	T value;
	vector<Edge> neighbours;// Contains who neighbours & dist to reach

	Node();
	
	Node(const T& value_);

	void connectNode(Node<T>* inter);

	void connectNode(Node<T>* inter, int _distance_);

	
	Node<T>* checkNeighbour(const T& suspect);
	Node<T>* exctractMinimumDist();
};

template<class T>
Node<T>* Node<T>::exctractMinimumDist() {
	int iteration_no = 0;
	uint64_t _distance = -1;

	for (size_t i = 0; i < neighbours.size(); i++)
	{
		if (_distance > neighbours[i]._distance)
		{
			_distance = neighbours[i]._distance;
			iteration_no = i;
		}

	}
	return neighbours[iteration_no]._node;

}

template<class T>
Node<T>* Node<T>::checkNeighbour(const T& suspect) {
	for (size_t i = 0; i < neighbours.size(); i++)
	{
		if(neighbours[i]._node->value == suspect)
		{
			return neighbours[i]._node;
		}

	}
	
	return this;
}



template<class T>
class MyGraph {

private:
	Node<T>* root_node_;


public:
	MyGraph();

	MyGraph(const T& value);

	void connectNode(Node<T>* inter);

	void connectNode(Node<T>* inter,int distance);

	Node<T>* returnRoot();

	void printBFS();

	void printDFS();

	
	void searchBFS(T key);

	void greedySearch(T key);

};



template<class T>
void MyGraph<T>:: greedySearch(T key) {

	Node<T>* temp;
	temp = root_node_;
	vector<T> path;

	while (1)
	{

		path.push_back(temp->value);
		if (temp != temp->checkNeighbour(key))
		{
			cout << "Found stuff:";
			break;

		}
		temp = temp->exctractMinimumDist();
	}

	cout << "The Path is :";
	for (size_t i = 0; i < path.size(); i++)
	{
		cout << path[i] << "  ";
	}
	cout << endl;

}
template<class T>
void MyGraph<T>::searchBFS(T key)
{	
	unordered_map<Node<T>*, bool> visited;
	queue<Node<T>*> cur_queue;
	Node<T>* temp;
	vector<T> path_record;

	cur_queue.push(this->root_node_);
	visited.insert_or_assign(this->root_node_, true);
	temp = cur_queue.front();

	while (!cur_queue.empty())
	{
		temp = cur_queue.front();
		path_record.push_back(temp->value);
		cur_queue.pop();

		if (temp != temp->checkNeighbour(key))
		{
			for (size_t i = 0; i < path_record.size(); i++)
			{
				cout << path_record[i] << "  ";
			}
			cout << endl;
			return;

		}

		for (size_t i = 0; i < temp->neighbours.size(); i++)
		{
			if (!visited[temp->neighbours[i]._node])
			{
				cur_queue.push(temp->neighbours[i]._node);
				visited.insert_or_assign(temp->neighbours[i]._node, true);

			}


		}

	}

}

template<class T>
void MyGraph<T>:: printDFS()
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
			if (!visited[temp->neighbours[i]._node])
			{
				curr_queue.push(temp->neighbours[i]._node);
				visited.insert_or_assign(temp->neighbours[i]._node, true);
			}
		}
	}
	cout << endl;
}

template<class T>
void MyGraph<T>::printBFS()
{
	unordered_map<Node<T>*, bool> visited;
	queue<Node<T>*> cur_queue;
	Node<T>* temp;

	cur_queue.push(this->root_node_);
	visited.insert_or_assign(this->root_node_, true);
	temp = cur_queue.front();

	while (!cur_queue.empty())
	{
		temp = cur_queue.front();
		cout << cur_queue.front()->value << " ";
		cur_queue.pop();
		for (size_t i = 0; i < temp->neighbours.size(); i++)
		{
			if (!visited[temp->neighbours[i]._node])
			{
				cur_queue.push(temp->neighbours[i]._node);
				visited.insert_or_assign(temp->neighbours[i]._node, true);

			}


		}
	}

	cout << endl;
}



template<class T>
Node<T>* MyGraph<T>:: returnRoot()
{
	return this->root_node_;

}


template<class T>
void MyGraph<T>:: connectNode(Node<T>* inter)
{
	root_node_->connectNode(inter);

}


template<class T> 
void MyGraph<T>::connectNode(Node<T>* inter, int distance) {
	root_node_->connectNode(inter,distance);
	

}

template<class T>
MyGraph<T>:: MyGraph(const T& value)
{
	Node<T>* temp = new Node<T>(value);
	root_node_ = temp;
}


template<class T>
MyGraph<T>::MyGraph()
{
	root_node_ = {};

}

template<class T>
Node<T>::Node()
{
	value = NULL;
	neighbours.clear();

}

template<class T>
Node<T>::Node(const T& value_)
{
	value = value_;
	neighbours.clear();

}

template <class T>
void Node<T>:: connectNode(Node<T>* inter)
{
	
	Edge test;
	test._node = inter;
	neighbours.push_back(test);

	return;

}

template<class T>
void Node<T>:: connectNode(Node<T>* inter, int _distance_) {

	Edge test;
	test._node = inter;
	test._distance = _distance_;
	neighbours.push_back(test);

	return;
}





#endif // !Graphs

