#ifndef staacK
#define staacK
#include "vectur.h"

template<class T>
class Stack {
private:
    vectur<T> halo;

public:
    Stack();
    Stack(T _Value);
    int getSize();
    void push(T const _Value);
    void pop();
    T peek();
};

template<class T>
Stack<T>::Stack() {}

template<class T>
Stack<T>::Stack(T _Value) {
    halo.pushback(_Value);
}

template<class T>
int Stack<T>::getSize() {
    return halo.get_size();
}

template<class T>
void Stack<T>::push(T const _Value) {
    halo.pushback(_Value);
}

template <class T>
void Stack<T>::pop() {
    halo.pop();
    return;
}

template <class T>
T Stack<T>::peek() {
    return halo.get(halo.get_size() - 1);
}



#endif // !staacK
