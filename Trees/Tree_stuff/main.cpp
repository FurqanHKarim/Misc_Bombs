#include <iostream>
#include "BinaryTree.h"
#include "queue.h"
#include "Stack.h"
using namespace std;

void check_neighbour(MyQueue<Node*>& inter);

void printme(BinaryTree &sent) {
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
        inter.push(inter.peek()->L_Next);
    }

}




int main() {
    BinaryTree hello(4);
    hello.insersion(2);
    hello.insersion(6);
    hello.insersion(1);
    hello.insersion(3);
    hello.insersion(5);
    hello.insersion(7);
    hello.preOrderVisit();
    printme(hello);

    






    hello.preOrderVisit();
    hello.remove(12);
    //  Node* wut = hello.getshortest(hello.search(12));


    hello.preOrderVisit();

    hello.search(88);

    cout << "Done :  " << endl;




}


