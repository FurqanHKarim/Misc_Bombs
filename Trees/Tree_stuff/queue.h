#ifndef queue
#define queue

#include"vectur.h"


template <typename T>
class MyQueue {
private:
	vectur<T> DaBoi;
	T* Head;
	T* Tail;



public:
	MyQueue();
	MyQueue(T const _value);
	void push(T const _value);
	void pop();
	int getCount();
	T peek();




};


template<class T>
MyQueue<T>::MyQueue() {}

















template<class T>
MyQueue<T>::MyQueue(T const _value)
{
	this->DaBoi.pushback(_value);
	Head = DaBoi.get_head_ref();
	Tail = (DaBoi.get_head_ref() + DaBoi.get_size() - 1);
}















template<class T>
void MyQueue<T>::push(T const _value)
{
	this->DaBoi.pushtop(_value);
	this->Head = this->DaBoi.get_head_ref();
	//this->Tail = (this->DaBoi.get_head_ref() + this->DaBoi.get_size() - 1);
	return;

}










template<class T>
void MyQueue<T>::pop() 
{
	this->DaBoi.pop();
	this->Head = this->DaBoi.get_head_ref();
	this->Tail = this->DaBoi.get_head_ref() + this->DaBoi.get_size() - 1;
	return;
}













template<class T>
T MyQueue<T>::peek() {
	//if (this->DaBoi.array == nullptr)
	//	return NULL;

	return this->DaBoi.get(this->DaBoi.get_size()-1);
}






template<class T>
int MyQueue<T>::getCount() {
	return this->DaBoi.get_size();
}
#endif // !queue

