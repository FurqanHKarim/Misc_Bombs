#include"FileHandler.h"
#include"BigFile.hpp"


int main1() {
	fstream ragnarok;
	ragnarok.open("test.txt", ios::in);
	//BigFile bruno("File",1);

	string intermidiate;

	char* korg = new char[1 << 20];

	for (size_t i = 0; i < 1<<20; i++)
	{
		korg[i] = 'W';
	}
	char* korgJr = new char[1 << 20];


	//bruno.bigWrite(korg, 1 << 20);
	//bruno.close();
	BigFile brunoJr("File", 1);
	brunoJr.bigWriteAnywhere("hell with this prob\n\n\n", 22, 150000);

	brunoJr.bigRead(korgJr, 1 << 20);
	for (size_t i = 0; i < 1<<20; i++)
	{
		if (korg[i] != korgJr[i]);
			//cout << "problem ho gai" << i << endl;

	}


	cout << "Done!     :" << endl;
	return 1;
}

int main() {
	/*fstream File("test.txt",ios::in);
	File.seekp(20);*/


	char* wut = new char[(1 << 17)*2];
	fill(wut, wut + (1 << 17) *2, 'K');
	BigFile brutus("File", 1);
	brutus.bigWriteAnywhere(wut, (1 << 17) *2,(1<<17)-500);

	return 0;

}