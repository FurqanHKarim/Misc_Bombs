#include <iostream>
#include <cstdlib>
#include <fstream>
#include <array>
#include <list>
#include<vector>
#include<chrono>
#include <algorithm>    // std::sort


using namespace std;

struct Node; 
class vectur;
class linkedList;
void bharlo(int* leh);


class vectur {
private:
    int *array;
    int capacity;
    int size;

public:
    vectur();
    vectur(int input);
    void pushback(int inter);
    void resize();
    int get(int a);
    void printVector();
    
};

struct Node {
    int integer;
    Node* next;

    Node() {
        next = NULL;
    }
};


class linkedList{
    Node* list;
public:

    linkedList() {
        list = NULL;
    }

    linkedList(int alpha) {
        list = new Node;
        list->integer = alpha;
        list->next = NULL;
    }


    void pushback(int alpha) {
        Node* temp;
        temp = list;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        Node* new_bacha;
        new_bacha = new Node;
        new_bacha->integer = alpha;
        temp->next = new_bacha;

    }

    void print_list() {
        Node* iterator;
        iterator = list;
        while (iterator != NULL) {
            cout << iterator->integer << endl;
            iterator = iterator->next;
        }

    }
};

void bharlo(int* leh) {
    for (int i = 0; i < 512; i++)
    {
        leh[i] = i;
    }
}









int main() {

}

vectur:: vectur(){
    array = NULL;
    capacity = 0;
    size = 0;
}

vectur:: vectur(int input){
    array = new int[1];
    *array = input;
    capacity = 1;
    size = 1;
}

void vectur::  resize() {
    int* temp = new int[(capacity+1)];
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = array[i];
    }
    delete array;
    array = temp;
    capacity += 1;
}

void vectur:: pushback(int inter) {

    if (size == capacity) {
        resize();
    }

    array[size] = inter;
    size++;
    
}

int vectur:: get(int a) {
    return array[a];
}

void vectur:: printVector() {
    for (int i = 0; i < size; i++)
    {
        cout << array[i]<<endl;
    }
}




