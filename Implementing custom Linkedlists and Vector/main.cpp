#include <iostream>
#include "vectur.h"
using namespace std;


int main() {
	vectur<int> halo;
    cout<<"hello"<<endl;
	halo.pushback(90);
	halo.pushback(80);
	halo.pushback(70);
	halo.pushback(60);
	halo.pushback(50);
	halo.pushback(40);
	halo.pushback(30);
	halo.pushback(20);
	halo.pushback(10);
	halo.pushback(5);
	halo.pushback(0);
	
	vectur<int> wut(halo);
	wut = halo;





}

