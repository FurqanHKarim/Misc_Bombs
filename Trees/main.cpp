#include<iostream>
#include<queue>
#include<stack>

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
    static void preOrderPrint(Node* boi);


public:
    BinaryTree();
    BinaryTree(int _Value);
    void insersion(int _Value); 
    void preOrderVisit();
};


bool palindromechecker(string input){
    
    string::iterator t1;
    string::reverse_iterator t2;
    t1 = input.begin();
    t2 = input.rbegin();
    for (int i = 0; i < input.length(); i++)
    {
        if(*t1 != *t2){
            return 0;
        }
        t1++;
        t2++;
    }
    return 1;
}


int main() {
    cout<<palindromechecker("racecar");



    queue<int> what;
    what.push(9);
    what.push(8);
    what.push(7);
    what.push(6);
    what.push(5);
    what.push(4);
    what.push(3);
    what.push(2);
    what.pop();
    int a = what.back();
    a = what.emplace();
    a = what.empty();
    a = what.front();
    what.pop();
    a = what.size();
    what.swap(what);

    stack<char> why;
    why.push('w');
    why.push('h');
    why.push('y');
    why.push(' ');
    why.push('i');
    why.push('s');
    why.push(' ');
    why.push('y');
    why.push('o');
    why.push('u');
    why.push('?');

    why.pop();
    cout<<why.empty();
    while(!why.empty())
    {
        cout<<why.top();
        why.pop();
    }

    

}














BinaryTree:: BinaryTree() {

	}
BinaryTree:: BinaryTree(int _Value) {
		DaNode = new Node(_Value);
	}
void BinaryTree:: insersion(int _Value) 
{


    //there are only a few cases where you can insert a new node
    //just make this new Node (first order of business)
    Node* new_boi = new Node(_Value);
    Node* inter;
    inter = this->DaNode;
    // 1) if there is no root
    if (inter == NULL)
    {
        DaNode = new_boi;
        return;
    }
    while (1)
    {
        

        if (_Value < inter->Value)
        {
            // 2) if there isnt a Node on the Left
            if (inter->L_Next == NULL)
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
            if (inter->R_Next == NULL)
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
void BinaryTree::  preOrderVisit(){
    BinaryTree::preOrderPrint(DaNode);
}
void BinaryTree:: preOrderPrint(Node* boi){

    if(boi == NULL)
    {
        return;
    }
    
    cout<<boi->Value<<endl;
    preOrderPrint(boi->L_Next);
    preOrderPrint(boi->R_Next);


    // if(boi->L_Next != NULL)
    // {
    //     preOrderPrint(boi->L_Next);
    // }
    // if (boi->R_Next != NULL)
    // {
    //     preOrderPrint(boi->R_Next);
    // }

    // cout<<boi->Value<<endl;

    // if(boi->L_Next == NULL)
    // {
    //     cout<<boi->Value<<endl;
    //     if (boi->R_Next == NULL)
    //     {
    //         return;
    //     }
    //     else
    //     {
    //         preOrderPrint(boi->R_Next);
    //         return;
    //     }
    // }else
    // {
    //     preOrderPrint(boi->L_Next);
    //     cout<<boi->Value<<endl;
    //     if (boi->R_Next != NULL)
    //     {
    //         preOrderPrint(boi->R_Next);
    //     }
    //     return;
    // }
}