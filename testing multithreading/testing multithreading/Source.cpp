#include<iostream>
#include<thread>
#include<fstream>
#include<mutex>
#include<string>
#include<cstring>
using namespace std;

mutex m;
char* input;

bool compare_char(char* one, char* two,int lenght) {
	/*if (input.length() != lenght)
		return 0;*/


	for (size_t i = 0; i < lenght; i++)
	{
		if (one[i] != two[i]) {
			return 0;
		}

	}
	
	return(1);
}
int check_end(char* arr, int length) {
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == '\0')
			return i;
	}
	cout << "nahi Laba" << endl;
	return 1;
}


void writefile(fstream& file) {

	char* tester = new char[90];
	while (1) {
		if (compare_char(input, tester,check_end(input,90)))
			continue;

		memcpy(tester, input, 90);

		m.lock();
		file.write(input, check_end(input, 90));
		file.write("\n", 1);
		file.flush();
		m.unlock();
	}
	return;
}


void readme(fstream& file, char* arra, int lenght) {
	m.lock();
	cout << "reader called start" << endl;
	file.seekg(0);
	file.read(arra, lenght);
	cout << "reader called end" << endl;
	m.unlock();
	return;
}
void check_again() {
	while (1) {
		cout << endl;
		cout << "Whats next :";
		m.lock();
		cin.getline(input, 90);
		m.unlock();
		//this_thread::sleep_for(chrono::milliseconds(100));
	
	}
}

int main() {
	fstream Dafile("hello.txt", ios::in|ios::out|ios::trunc);
	input = new char[90];
	cout << "Let the games begin:   ";
	cin.getline(input,90,'\n');
	//strcat(input, "\n");
	int a = check_end(input, 90);
	Dafile.write(input, a);
	Dafile.flush();
	thread t1(writefile, std::ref(Dafile));
	thread t2(check_again);

	
	t2.join();
	t1.join();


	return 0;
}