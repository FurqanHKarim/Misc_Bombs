#ifndef vectar
#define vectar

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <array>
#include <list>
#include<vector>
#include<chrono>
#include <algorithm>    // std::sort
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
    void pushtop(T inter);
    void pop();
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
    T* temp = new T[(capacity + 1) * 2];
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    capacity++;
    capacity *= 2;
    array = temp;
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
void vectur<T>::pushtop(T inter) {


    if (capacity == size) {
        resize();
    }

    size++;
    for (int i = 0; i < size; i++)
    {
        array[size - i] = array[size - 2];
    }
    array[0] = inter;
    return;

}


template<class T>
T vectur<T>::get(T const a) {
    if (a > size)
    {
        cout << "Out of Bounds: \n";
        return 0;
    }
    else {
        return array[a];

    }

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


template<class T>
void vectur<T>::pop() {
    if (size == 0) {
        cout << "Empty :";
        return;
    }

    this->array[size - 1] = NULL;
    size--;
    return;
}


#endif // !vectar