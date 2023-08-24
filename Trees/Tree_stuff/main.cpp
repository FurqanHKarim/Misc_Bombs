#include <iostream>
#include "BinaryTree.h"
using namespace std;

template<class T>
void printstack(Stack<Node<T>*>& hello) {
    Stack<Node*> wut(hello);
    cout << "printing stack :";
    while (wut.getSize()) {
        cout << wut.peek()->Value << "  ";
        wut.pop();
    }
    cout << endl;
    return;
    
}




int main() {
  
    BinaryTree<double> hello(4);
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
    hello.printMeBreath();
    hello.preOrderVisit();
    hello.printMeDepthPreorder();
    hello.printMeInorder();

    BinaryTree<double>::iteratorDFS wut;
    wut = hello.getRoot();
    for (size_t i = 0; i < 12; i++)
    {
        cout<<*wut<<" ";
        ++wut;

    }
    cout << "Done :  " << endl;




}


