#ifndef Linked
#define Linked
#include<iostream>
using namespace std;


void bharlo(int* leh);

struct Node {
    int integer;
    Node* next;

    Node();
    Node() {
        next = NULL;
    }
};


class linkedList {
    Node* list;
public:
    linkedList();
    linkedList(int alpha);
    void pushback(int alpha);
    void print_list();

};

///////////////////////////////////////////////////////functions///////////////////////////////////////////////////////
void bharlo(int* leh) {
    for (int i = 0; i < 512; i++)
    {
        leh[i] = i;
    }
}


linkedList:: linkedList() {
    list = NULL;
}


linkedList::linkedList(int alpha) {
    list = new Node;
    list->integer = alpha;
    list->next = NULL;
}


void linkedList:: pushback(int alpha) {
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


void linkedList:: print_list() {
    Node* iterator;
    iterator = list;
    while (iterator != NULL) {
        cout << iterator->integer << endl;
        iterator = iterator->next;
    }

}

#endif // !Linked
