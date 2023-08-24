#ifndef TREE
#define TREE
#include<iostream>
#include "queue.h"
#include "Stack.h"
using namespace std;

enum class Color { Red, Black };
template<class T>
struct Node {
    T Value;
    Node* R_Next;
    Node* L_Next;
    Color current_color;
    int depth;

    Node();
    Node(T _Value);
};

template<class T>
class BinaryTree {
private:
    int max_depth;
    Node<T>* DaNode;

    static void preOrderPrint(Node<T>* boi);


public:
    T getshortest(Node<T>*& sample);
    BinaryTree();
    BinaryTree(T _Value);
    void insersion(T _Value);
    void preOrderVisit();
    Node<T>* search(T sample);
    Node<T>* searchparent(T sample);
    void remove(T value);
    Node<T>* getRoot();
    void printMeBreath();
    void check_neighbour(MyQueue<Node<T>*>& inter);
    void printMeDepthPreorder();
    void printMeInorder();


    class iteratorBFS {
    private:
        Node<T>* existance;
        MyQueue<Node<T>*> tree_;
        void iterate_BreathFirst();
        
        

    public:
        iteratorBFS& operator= (Node<T>* inter)
        {
            tree_.push(inter);
            existance = inter;
            this->iterate_BreathFirst();
            return *this;
        }

        T operator*() {
            return existance->Value;
        }

        iteratorBFS& operator++() 
        {
            if(tree_.getCount() == 0)
            {
                cout << "end of tree" << endl;
                return *this;
            }
            if (tree_.peek()->L_Next != nullptr)
                tree_.push(tree_.peek()->L_Next);

            if (tree_.peek()->R_Next != nullptr)
                tree_.push(tree_.peek()->R_Next);

            existance = tree_.peek();
            tree_.pop();
            return *this;
        }

    };

    class iteratorDFS {
    private:
        Node<T>* existance;
        Stack<Node<T>*> tree_;
        void iterate_DepthFirst();


    public:
        iteratorDFS& operator= (Node<T>* inter)
        {
            this->existance = inter;
            this->tree_.push(inter);
            return *this;
        }

        T operator*() {
            return existance->Value;
        }

        iteratorDFS& operator++()
        {
            if (tree_.getSize() == 0)
            {
                cout << "end of the tree" << endl;
                return *this;
            }
            iterate_DepthFirst();

            return *this;
        }



    };
};


template<class T>
void BinaryTree<T>::iteratorBFS::iterate_BreathFirst()
{

    if (tree_.peek()->L_Next != nullptr)
        tree_.push(tree_.peek()->L_Next);

    if (tree_.peek()->R_Next != nullptr)
        tree_.push(tree_.peek()->R_Next);

    tree_.pop();
 
}


template<class T>
void BinaryTree<T>::iteratorDFS::iterate_DepthFirst() {
   
    
    Node<T>* inter = tree_.peek();

    if (tree_.peek()->L_Next != nullptr)
    {
        tree_.push(tree_.peek()->L_Next);
        existance = tree_.peek();
        return;

    }

    inter = tree_.peek();
    tree_.pop();

    if (tree_.getSize() == 0)
    {
        cout << "end of tree";
        return;
    }

    if (inter->R_Next != nullptr)
    {
        tree_.push(inter->R_Next);
        existance = tree_.peek();
        return;
    }


    

    if (tree_.peek()->R_Next == nullptr) {
        tree_.pop();
        inter = tree_.peek();
        tree_.pop();
        tree_.push(inter->R_Next);
        existance = tree_.peek(); 
        return;
    }
    else
    {
        inter = tree_.peek();
        tree_.pop();
        tree_.push(inter->R_Next);
        existance = tree_.peek();
        return;
    }
    inter = tree_.peek();
    tree_.pop();
    tree_.push(inter->R_Next);
    existance = tree_.peek();
    return;

}




template<class T>
Node<T>:: Node() {
    R_Next = nullptr;
    L_Next = nullptr;
    depth = 0;
    current_color = Color::Red;
}

template<class T>
Node<T>:: Node(T _Value) {
    Value = _Value;
    R_Next = nullptr;
    L_Next = nullptr;
    depth = 0;
    current_color = Color::Red;
}



template<class T>
T BinaryTree<T>::getshortest(Node<T>*& sample)
{
    T temp1;

    if (sample->L_Next == nullptr) {
        temp1 = sample->Value;
        delete sample;
        return temp1;
    }
    Node<T>* temp = nullptr;

    while (sample->L_Next->L_Next != nullptr)
    {
        sample = sample->L_Next;
    }

    temp = sample->L_Next;
    sample->L_Next = temp->R_Next;
    temp->R_Next = nullptr;
    temp1 = temp->Value;
    delete temp;
    return temp1;


}


template<class T>
void BinaryTree<T>::remove(T value)
{
    Node<T>* temp = this->DaNode;


    temp = search(value);

    if (temp == nullptr)
    {
        return;
    }

    if (temp == DaNode) {
        delete DaNode;
        DaNode = nullptr;
        return;
    }

    if (temp->R_Next == nullptr) {
        Node* temp1 = temp->L_Next;
        if (temp1 == nullptr)
        {
            temp->L_Next = nullptr;
            delete temp;
            return;
        }
        if (temp->L_Next->Value == value) {
            temp1 = temp->L_Next;
            temp->L_Next = nullptr;
            delete temp1;
            return;
            //this is fix check this and work on it
        }

        temp->L_Next = temp1->L_Next;
        temp->R_Next = temp1->R_Next;
        temp->current_color = temp1->current_color;
        temp->Value = temp1->Value;
        delete temp1;
        return;
    }

    if (temp->R_Next->Value == value) {
        delete temp->R_Next;
        temp->R_Next = nullptr;
        return;
    }
    temp->Value = getshortest(temp->R_Next);
}


template<class T>
Node<T>* BinaryTree<T>::searchparent(T sample) {
    Node<T>* inter;
    Node<T>* parent_iter;
    inter = DaNode;
    while (1) {
        parent_iter = inter;
        if (inter == nullptr) {
            cout << "sample not found" << endl;
            return nullptr;
        }

        if (sample > inter->Value) {
            inter = inter->R_Next;
            continue;
        }
        else if (sample < inter->Value)
        {
            inter = inter->L_Next;
            continue;
        }

        if (inter->Value == sample) {
            return parent_iter;
        }
    }
}


template<class T>
Node<T>* BinaryTree<T>::search(T sample) {
    Node<T>* inter;
    Node<T>* edge_case;
    inter = DaNode;
    edge_case = DaNode;
    while (1) {
        if (inter == nullptr) {
            cout << "sample not found" << endl;
            return nullptr;
        }

        if (inter->Value == sample) {
            //cout<<"Sample Found:: at depth"<<inter->depth;
            if ((inter->L_Next == nullptr) && (inter->R_Next == nullptr))
                return edge_case;

            return inter;
        }
        edge_case = inter;

        if (sample > inter->Value) {
            inter = inter->R_Next;
            continue;
        }
        else if (sample < inter->Value)
        {
            inter = inter->L_Next;
            continue;
        }

    }
}


template<class T>
BinaryTree<T>::BinaryTree() {
    DaNode = nullptr;
    max_depth = 0;
}


template<class T>
BinaryTree<T>::BinaryTree(T _Value) {
    max_depth = 0;
    DaNode = new Node<T>(_Value);
}


template<class T>
void BinaryTree<T>::insersion(T _Value)
{
    //there are only a few cases where you can insert a new node
    //just make this new Node (first order of business)
    Node<T>* new_boi = new Node<T>(_Value);
    Node<T>* inter;
    inter = this->DaNode;
    // 1) if there is no root
    if (inter == nullptr)
    {
        new_boi->current_color = Color::Black;
        DaNode = new_boi;

        return;
    }
    while (1)
    {
        new_boi->depth++;
        if (new_boi->depth > max_depth)
            max_depth = new_boi->depth;


        if (_Value < inter->Value)
        {
            // 2) if there isnt a Node on the Left
            if (inter->L_Next == nullptr)
            {
                inter->L_Next = new_boi;
                return;
            }
            else
            {
                // 3) if there is Node to the Left
                inter = inter->L_Next;
                continue;
            }
        }
        // 4 & 5) if there is a root and the value is greater than the root
        if (_Value > inter->Value || _Value == inter->Value)
        {
            // 4) if there is no Node on the Right
            if (inter->R_Next == nullptr)
            {
                inter->R_Next = new_boi;
                return;
            }
            else
            { // 5) is there is a Node to the Right
                inter = inter->R_Next;
                continue;
            }

        }
    }
}


template<class T>
void BinaryTree<T>::preOrderVisit() {
    BinaryTree::preOrderPrint(DaNode);
}


template<class T>
void BinaryTree<T>::preOrderPrint(Node<T>* boi) {

    if (boi == nullptr)
    {
        return;
    }

    preOrderPrint(boi->L_Next);
    cout << boi->Value << endl;
    preOrderPrint(boi->R_Next);
}


template<class T>
Node<T>* BinaryTree<T>:: getRoot() {
    return this->DaNode;
}


template<class T>
void BinaryTree<T>::printMeBreath() {
    MyQueue<Node<T>*> ohkay;
    ohkay.push(this->DaNode);
    while (ohkay.getCount())
    {
        this->check_neighbour(ohkay);
        cout << ohkay.peek()->Value << endl;
        ohkay.pop();

    }

}


template<class T>
void BinaryTree<T>::check_neighbour(MyQueue<Node<T>*>& inter) {
    if (inter.peek()->L_Next != nullptr)
        inter.push(inter.peek()->L_Next);


    if (inter.peek()->R_Next != nullptr)
        inter.push(inter.peek()->R_Next);

}


template<class T>
void BinaryTree<T>::printMeDepthPreorder() {
    Stack<Node<T>*> stack(this->DaNode);

    cout << endl;

    while (stack.getSize())
    {

        Node<T>* inter = stack.peek();
        cout << inter->Value << endl;
        stack.pop();

        if (inter->R_Next != nullptr)
        {
            stack.push(inter->R_Next);
        }

        if (inter->L_Next != nullptr)
        {
            stack.push(inter->L_Next);
        }

    }
}


template<class T>
void BinaryTree<T>::printMeInorder() {
    Stack<Node<T>*> stack(this->DaNode);
    cout << endl;
    Node<T>* inter = stack.peek();
    while (stack.getSize())
    {
        if (stack.peek()->L_Next != nullptr)
        {
            stack.push(stack.peek()->L_Next);
            continue;

        }

        cout << stack.peek()->Value << endl;
        inter = stack.peek();
        stack.pop();

        if (inter->R_Next != nullptr)
        {
            stack.push(inter->R_Next);
            continue;
        }

        if (stack.getSize() == 0)
            return;

        if (stack.peek()->R_Next == nullptr) {
            cout << stack.peek()->Value << endl;
            stack.pop();
        }
        cout << stack.peek()->Value << endl;
        inter = stack.peek();
        stack.pop();
        stack.push(inter->R_Next);
        continue;

    }
}

#endif // !TREE
