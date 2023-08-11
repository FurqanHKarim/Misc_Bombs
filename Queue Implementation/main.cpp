#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;

    Node();
    Node(int const &_value);
};

class Stack{
    private: 
    Node* head;
    Node* tail;

    public:
    Stack();
    Stack(int &_Value);
    void push(int const &_Value);
    int pop();
};

Stack:: Stack(){
    this->head = nullptr;
}
Stack:: Stack(int &_Value){
    head = new Node(_Value);
}
Node:: Node(){

}
Node:: Node(int const &_value){
        
    value = _value;
    next = nullptr;

}
void Stack:: push(int const &_Value){
    Node* temp = new Node(_Value);
    temp->next = this->head;
    this->head = temp;
    return;
}
int Stack:: pop(){
    if(this->head == nullptr)
        return 0;
    
    int inter = 0;
    Node* temp = this->head;
    inter = temp->value;
    this->head = temp->next;
    delete temp;
    return inter;
}

class MyQueue{
private:
    Node* DaBoi;
    Node* Tail;

public:
    MyQueue();
    MyQueue(int const &_value);
    void push(int const &_value);
    int pop();

};

MyQueue:: MyQueue(){
    DaBoi = nullptr;
    Tail = nullptr;
}

MyQueue:: MyQueue(int const &_value){
    DaBoi = new Node(_value);
    Tail = DaBoi;
}

void MyQueue:: push(int const &_value){
    Node* new_boi = new Node(_value);

    if(this->Tail == nullptr){
        this->Tail = new_boi;
        return;
    }

    this->Tail->next = new_boi;
    this->Tail = new_boi;
    return;
}

int MyQueue:: pop(){
    int inter;
    Node* temp = this->DaBoi;
    if(this->DaBoi == nullptr){
        return 0;
    }

    if(this->DaBoi == this->Tail){
        inter = this->DaBoi->value;
        this->DaBoi = nullptr;
        this->Tail = nullptr;
        delete temp;
        return inter;
    }

    
    inter = this->DaBoi->value;
    this->DaBoi = this->DaBoi->next;
    delete temp;
    return inter;
}



int main(){
    MyQueue hello(9);
    hello.push(90);
    hello.push(80);
    hello.push(70);
    hello.push(60);
    hello.push(50);
    hello.push(40);

    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;
    cout<<hello.pop()<<endl;


}