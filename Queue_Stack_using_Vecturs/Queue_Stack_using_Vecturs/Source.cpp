#include<iostream>
#include "queue.h"
#include "vectur.h"
#include "Stack.h"
using namespace std;


int main() {

	Stack<int> wut;
	wut.push(90);
	cout<<wut.peek();
	wut.push(80);
	cout<<wut.peek();
	wut.push(60);
	cout<<wut.peek();
	wut.push(50);
	cout<<wut.peek();
	wut.push(40);
	cout<<wut.peek();
	wut.push(30);
	cout<<wut.peek();
	wut.push(60);
	cout<<wut.peek();
	wut.push(50);
	cout<<wut.peek();
	wut.push(40);
	cout<<wut.peek();
	wut.push(30);

	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	wut.pop();
	cout << wut.peek();
	

	
}