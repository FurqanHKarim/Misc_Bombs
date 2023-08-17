#include <iostream>
#include "BinaryTree.h"
#include "queue.h"
#include "Stack.h"
using namespace std;

void check_neighbour(MyQueue<Node*>& inter);

void printMeDepth(BinaryTree& sent) {
    Stack<Node*> stack(sent.getRoot());
    do {
        if (stack.peek()->L_Next != nullptr)
        {
            stack.push(stack.peek()->L_Next);
        }
        else if (stack.peek()->R_Next != nullptr)
        {
            stack.push(stack.peek()->R_Next);
        }
        else
        {
            cout << stack.peek()->Value;
            stack.pop();
        }

    } while (stack.getSize());
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
  
    Stack<int> hel(4);
    hel.push(5);
    hel.push(6);
    hel.push(7);
    hel.push(8);
    hel.push(9);
    hel.push(10);
    hel.push(11);
    hel.push(12);
    hel.push(13);
    hel.push(14);
    hel.pop();
    cout<<hel.peek();
    hel.pop();
    cout << hel.peek();
    hel.pop();
    cout << hel.peek();

    BinaryTree hello(4);
    hello.insersion(2);
    hello.insersion(6);
    hello.insersion(1);
    hello.insersion(3);
    hello.insersion(5);
    hello.insersion(7);
    //hello.preOrderVisit();
    printMeDepth(hello);

    






    hello.preOrderVisit();
    hello.remove(12);
    //  Node* wut = hello.getshortest(hello.search(12));


    hello.preOrderVisit();

    hello.search(88);

    cout << "Done :  " << endl;




}


