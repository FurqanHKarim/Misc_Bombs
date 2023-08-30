#include"FileHandler.h"
#include"BigFile.hpp"


int main() {
	fstream ragnarok;
	ragnarok.open("test.txt", ios::in);
	BigFile bruno("File",1);

	string intermidiate;

	char* korg = new char[1 << 20];

	for (size_t i = 0; i < 1<<20; i++)
	{
		korg[i] = 'W';
	}
	char* korgJr = new char[1 << 20];


	bruno.bigWrite(korg, 1 << 20);
	bruno.close();
	BigFile brunoJr("File", 1);
	brunoJr.bigWriteAnywhere("hell with this prob\n\n\n", 22, 150000);

	brunoJr.bigRead(korgJr, 1 << 20);
	for (size_t i = 0; i < 1<<20; i++)
	{
		if (korg[i] != korgJr[i])
			cout << "problem ho gai" << i << endl;

	}
	bruno.emptyFile();
	int i = 5;
	//while(i)
	//{
	//	ragnarok.Read(intermidiate);
	//	cout << endl;
	//	cout.write(intermidiate.c_str(), intermidiate.size());
	//	//ragnarok >> intermidiate;
	//	//cout << intermidiate << " ";

	//}

	//string whatever = { "\nI suppose this is nothing worth while to explore \n" };
	//while (1)
	//{
	//	ragnarok.Write(whatever,0);
	//	cout << endl << ragnarok.returnLenght();

	//}
	//
	//ragnarok.Write()


	cout << "Done!     :" << endl;
}