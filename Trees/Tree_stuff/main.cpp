#include <iostream>
#include "BinaryTree.h"
using namespace std;

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
    hello.printMeBreath();
    hello.preOrderVisit();
    hello.printMeDepthPreorder();
    hello.printMeInorder();

    cout << "Done :  " << endl;




}


