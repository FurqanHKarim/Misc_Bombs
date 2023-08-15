#include<iostream>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node* next;

    Node();
    Node(T const &_value);
};

template <typename T>
class Stack{
    private: 
    Node<T>* head;
    Node<T>* tail;

    public:
    Stack();
    Stack(T &_Value);
    void push(T const &_Value);
    void pop();
};

template <typename T>
class MyQueue{
private:
    Node<T>* DaBoi;
    Node<T>* Tail;

public:
    MyQueue();
    MyQueue(T const &_value);
    void push(T const &_value);
    void pop();

};

template <typename T>
Node<T>:: Node() : next(nullptr){
}

template <typename T>
Node<T>:: Node(T const &_value): value(_value), next(nullptr){
}

template <typename T>
Stack<T>:: Stack(){
    this->head = nullptr;
}

template <typename T>
Stack<T>:: Stack(T &_Value){
    head = new Node(_Value);
}

template <typename T>
void Stack<T>:: push(T const &_Value){
    Node<T>* temp = new Node(_Value);
    temp->next = this->head;
    this->head = temp;
    return;
}

template <typename T>
void Stack<T>:: pop(){
    if(this->head == nullptr)
        return;
    
    Node<T>* temp = this->head;
    this->head = temp->next;
    delete temp;
    return;
}


template <typename T>
MyQueue<T>:: MyQueue(){
    DaBoi = nullptr;
    Tail = nullptr;
}


template <typename T>
MyQueue<T>:: MyQueue(T const &_value){
    DaBoi = new Node(_value);
    Tail = DaBoi;
}

template <typename T>
void MyQueue<T>:: push(T const &_value){
    Node<T>* new_boi = new Node(_value);

    if(this->Tail == nullptr){
        this->Tail = new_boi;
        return;
    }

    this->Tail->next = new_boi;
    this->Tail = new_boi;
    return;
}


template <typename T>
void MyQueue<T>:: pop(){
    Node<T>* temp = this->DaBoi;
    if(this->DaBoi == nullptr){
        cout<<"Queue Empty: \n";
        return ;
    }

    if(this->DaBoi == this->Tail){
        this->DaBoi = nullptr;
        this->Tail = nullptr;
        delete temp;
        return;
    }

    
    this->DaBoi = this->DaBoi->next;
    delete temp;
    return;
}








int main(){
    MyQueue hello(9);
    hello.push(90);
    hello.push(80);
    hello.push(70);
    hello.push(60);
    hello.push(50);
    hello.push(40);

    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;
    // cout<<hello.pop()<<endl;


}