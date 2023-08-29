#include"FileHandler.h"
#include"BigFile.hpp"


int main() {
	FileHandler ragnarok;
	BigFile bruno(1.5);

	ragnarok.Open("life_of_pi.txt", ios::in);

	string intermidiate;
	char korg[90] = {};
	//cout<<ragnarok.HowLong();
	int i = 5;
	while(i)
	{
		ragnarok.Read(intermidiate);
		cout << endl;
		cout.write(intermidiate.c_str(), intermidiate.size());
		//ragnarok >> intermidiate;
		//cout << intermidiate << " ";

	}

	string whatever = { "\nI suppose this is nothing worth while to explore \n" };
	while (1)
	{
		ragnarok.Write(whatever,0);
		cout << endl << ragnarok.returnLenght();

	}
	
	//ragnarok.Write()


	cout << "Done!     :" << endl;
}