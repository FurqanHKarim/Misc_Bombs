#ifndef vectar
#define vectar
#include<iostream>
using namespace std;



template <class T>
class vectur {
private:
    T* array;
    int capacity;
    int size;

public:
    vectur();
    vectur(T input);
    T* get_head_ref();
    void pushback(T inter);
    void poptop();
    void resize();
    T get(T const a);
    void printVector();
    int get_size();
    int get_capacity();
    
};

template<class T>
vectur<T>::vectur() : array(nullptr), capacity(0), size(0) {
}

template<class T>
vectur<T>::vectur(T input) : capacity(1), size(1) {
    array = new T[1];
    *array = input;
}

template<class T>
void vectur<T>::resize() {
    T* temp = new T[(capacity+1) * 2];
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = array[i];
    }
    delete array;
    array = temp;
    capacity++;
    capacity *= 2;
}

template<class T>
T* vectur<T>::get_head_ref() {
    return array;
}
template<class T>
void vectur<T>::pushback(T inter) {

    if (size == capacity) {
        resize();
    }

    array[size] = inter;
    size++;

}

template<class T>
void vectur<T>::poptop() {

    if (size == 0) {
        cout << "EMPTY: " << endl;
        return;
    }
    size--;
    capacity--;
    T* temp;
    temp = new T[capacity];
    for (int i = 1; i < size+1; i++)
    {
        temp[i-1] = array[i];
    }

    delete array;
    array = temp;
}

template<class T>
T vectur<T>::get(T const a) {
    return array[a];
}

template <class T>
void vectur<T>::printVector() {
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}


template<class T>
int vectur<T>::get_size() {
    return this->size;
}


template <class T>
int vectur<T>::get_capacity() {
    return this->capacity;
}

#endif // !vectar
