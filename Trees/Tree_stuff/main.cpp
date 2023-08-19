#include <iostream>
#include "BinaryTree.h"
#include "queue.h"
#include "Stack.h"
using namespace std;

void check_neighbour(MyQueue<Node*>& inter);
void printstack(Stack<Node*>& hello);

void printMeDepthPreorder(BinaryTree& sent) {
    Stack<Node*> stack(sent.getRoot());
    cout << endl;   
    do {

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

    } while (stack.getSize());
}

void printMeInorder(BinaryTree& sent) {
    Stack<Node*> stack(sent.getRoot());
    cout << endl;
    Node* inter = stack.peek();
    while(stack.getSize())
    {
        if (stack.peek()->L_Next != nullptr)
        {
            stack.push(stack.peek()->L_Next);
            continue;

        }
       
        cout << stack.peek()->Value<<endl;
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
void printstack(Stack<Node*>& hello) {
    Stack<Node*> wut(hello);
    cout << "printing stack :";
    while (wut.getSize()) {
        cout << wut.peek()->Value << "  ";
        wut.pop();
    }
    cout << endl;
    return;
    
}

void printMeBreath(BinaryTree &sent) {
    MyQueue<Node*> ohkay;
    ohkay = sent.getRoot();
    do
    {
        check_neighbour(ohkay);
        cout << ohkay.peek()->Value << endl;
        ohkay.pop();

    } while (ohkay.getCount());


}

void check_neighbour(MyQueue<Node*> &inter) {
    if (inter.peek()->L_Next != nullptr)
    {
        inter.push(inter.peek()->L_Next);
    }
    

    if (inter.peek()->R_Next != nullptr)
    {
        inter.push(inter.peek()->R_Next);
    }


}




int main() {
  
    BinaryTree hello(4);
    hello.insersion(2);
    hello.insersion(6);
    hello.insersion(5);
    hello.insersion(7);
    hello.insersion(1);
    hello.insersion(3);
    hello.insersion(1.5);
    hello.insersion(1.7);
    hello.insersion(1.8);
    hello.insersion(3.3);
    hello.insersion(4.1);
    hello.preOrderVisit();
    printMeDepthPreorder(hello);
    printMeInorder(hello);

    cout << "Done :  " << endl;




}


