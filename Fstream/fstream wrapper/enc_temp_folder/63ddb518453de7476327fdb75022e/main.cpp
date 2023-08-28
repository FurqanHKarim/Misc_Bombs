#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FileHandler {
private:
	fstream daFile;


public:
	FileHandler();
	FileHandler(const string& file_name) :daFile(file_name, ios::in || ios::out) {}//for opening directly in in and out mode;
	FileHandler(const string& file_name, ios_base::openmode mode) :daFile(file_name, mode) {}//for opening in specified mode;
	bool Open(const string& file_name);
	bool Open(const string& file_name,ios_base::openmode mode);
	bool IsOpen();
	void Write(const string& input);
	void Write(const string& input, int where);
	void Read(string& reader_);
	void Read(string& reader_, int where);
	int EndofFile();

	
};

int FileHandler::EndofFile() 
{
	streampos hello;
	hello = daFile.tellg();
	string sacrificial;
	int end_position;
	while (!daFile.eof()) {
		getline(daFile, sacrificial);
		cout << sacrificial<<endl;
	}
	end_position = (int)daFile.tellg() - 2;
	daFile.seekg(hello);

	return end_position;
	

}

void FileHandler::Read(string& reader_, int where)
{
	if (daFile.is_open())
	{
		cout << "No file is open :" << endl;
		return;
	}
	daFile.seekg(where);
	reader_.clear();
	getline(daFile, reader_);
	return;

}


void FileHandler::Read(string& reader_)
{
	if (!daFile.is_open())
	{
		cout << "No file is open :" << endl;
		return;
	}
	string test;
	test = reader_;
	reader_.clear();
	getline(daFile, reader_);
	if (test == reader_)
		cout << "Reached File end" << endl;
	return;

}

void FileHandler::Write(const string& input, int where)
{
	if (daFile.is_open())
	{
		cout << "No file is open :" << endl;
		return;
	}

	daFile.seekp(where);
	daFile.write(input.c_str(), input.size());
}

void FileHandler::Write(const string& input) 
{

	if (daFile.is_open())
	{
		cout << "No file is open :" << endl;
		return ;
	}

	daFile.write(input.c_str(),input.size());
	

}

bool FileHandler::Open(const string& file_name, ios_base::openmode mode) {
	daFile.open(file_name, mode);
	if (daFile.is_open())
	{
		cout << "File " << file_name << " didn't open :" << endl;
		return 0;
	}

	return 1;
}

bool FileHandler:: Open(const string& file_name)
{
	daFile.open(file_name, ios::out || ios::in);
	if (daFile.is_open())
	{
		cout << "File " << file_name << " didn't open :" << endl;
		return 0;
	}

	return 1;
}

bool FileHandler::IsOpen() {
	return daFile.is_open();
}

void printCompleteCharArray(const char* arr_) 
{	
	for (size_t i = 0; (i < 90) && (arr_[i] != '\0'); i++)
	{
		cout << arr_[i];
	}
	return;
}
int main() {
	FileHandler ragnarok("life_of_pi.txt");
	string intermidiate;
	char korg[90] = {};

	while(1)
	{
		ragnarok.Read(intermidiate);
		cout << intermidiate << endl;
		cout << ragnarok.EndofFile();
//		ragnarok >> intermidiate;
	//	cout << intermidiate << " ";

	}
	
	//ragnarok.Write()


	cout << "Done!     :" << endl;
}