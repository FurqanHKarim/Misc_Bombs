#ifndef TREE
#define TREE
#include<iostream>
#include "queue.h"
#include "Stack.h"
using namespace std;

enum class Color { Red, Black };
struct Node {
    double Value;
    Node* R_Next;
    Node* L_Next;
    Color current_color;
    int depth;

    Node();
    Node(double _Value);
};

class BinaryTree {
private:
    int max_depth;
    Node* DaNode;

    static void preOrderPrint(Node* boi);


public:
    double getshortest(Node*& sample);
    BinaryTree();
    BinaryTree(double _Value);
    void insersion(double _Value);
    void preOrderVisit();
    Node* search(double sample);
    Node* searchparent(double sample);
    void remove(double value);
    Node* getRoot();
    void printMeBreath();
    void check_neighbour(MyQueue<Node*>& inter);
    void printMeDepthPreorder();
    void printMeInorder();
};


Node:: Node() {
    R_Next = nullptr;
    L_Next = nullptr;
    depth = 0;
    current_color = Color::Red;
}



Node:: Node(double _Value) {
    Value = _Value;
    R_Next = nullptr;
    L_Next = nullptr;
    depth = 0;
    current_color = Color::Red;
}



double BinaryTree::getshortest(Node*& sample)
{
    double temp1;

    if (sample->L_Next == nullptr) {
        temp1 = sample->Value;
        delete sample;
        return temp1;
    }
    Node* temp = nullptr;

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



void BinaryTree::remove(double value)
{
    Node* temp = this->DaNode;


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



Node* BinaryTree::searchparent(double sample) {
    Node* inter;
    Node* parent_iter;
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



Node* BinaryTree::search(double sample) {
    Node* inter;
    Node* edge_case;
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



BinaryTree::BinaryTree() {
    DaNode = nullptr;
    max_depth = 0;
}



BinaryTree::BinaryTree(double _Value) {
    max_depth = 0;
    DaNode = new Node(_Value);
}



void BinaryTree::insersion(double _Value)
{
    //there are only a few cases where you can insert a new node
    //just make this new Node (first order of business)
    Node* new_boi = new Node(_Value);
    Node* inter;
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



void BinaryTree::preOrderVisit() {
    BinaryTree::preOrderPrint(DaNode);
}



void BinaryTree::preOrderPrint(Node* boi) {

    if (boi == nullptr)
    {
        return;
    }

    preOrderPrint(boi->L_Next);
    cout << boi->Value << endl;
    preOrderPrint(boi->R_Next);
}



Node* BinaryTree:: getRoot() {
    return this->DaNode;
}



void BinaryTree::printMeBreath() {
    MyQueue<Node*> ohkay;
    ohkay.push(this->DaNode);
    while (ohkay.getCount())
    {
        this->check_neighbour(ohkay);
        cout << ohkay.peek()->Value << endl;
        ohkay.pop();

    }

}



void BinaryTree::check_neighbour(MyQueue<Node*>& inter) {
    if (inter.peek()->L_Next != nullptr)
        inter.push(inter.peek()->L_Next);


    if (inter.peek()->R_Next != nullptr)
        inter.push(inter.peek()->R_Next);

}



void BinaryTree::printMeDepthPreorder() {
    Stack<Node*> stack(this->DaNode);

    cout << endl;

    while (stack.getSize())
    {

        Node* inter = stack.peek();
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



void BinaryTree::printMeInorder() {
    Stack<Node*> stack(this->DaNode);
    cout << endl;
    Node* inter = stack.peek();
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
