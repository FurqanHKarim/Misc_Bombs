#include<iostream>
#include "queue.h"
#include "vectur.h"
#include "Stack.h"
using namespace std;


int main() {

	Stack<int> wut;
	Stack<int> ohkay;
	wut.push(90);
	wut.push(80);
	wut.push(60);
	wut.push(50);
	wut.push(40);
	wut.push(30);
	wut.push(60);
	wut.push(50);
	wut.push(40);
	wut.push(30);

	ohkay = wut;

	wut.pop();
	wut.peek(); 
	wut.pop();
	wut.peek();
	wut.pop();
	wut.pop();
	wut.pop();
	wut.pop();
	wut.pop();
	wut.pop();
	wut.pop();
	wut.pop();

	

	
}