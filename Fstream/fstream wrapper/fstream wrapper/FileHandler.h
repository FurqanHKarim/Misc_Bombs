#ifndef wrapper
#define wrapper


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FileHandler {
private:
	fstream daFile;
	string file_name_;
	size_t file_lenght_;



public:
	FileHandler();
	FileHandler(const string& file_name) :file_name_(file_name), daFile(file_name, ios::out | ios::in | ios::app) { HowLong(); }//for opening directly in in and out mode;
	FileHandler(const string& file_name, ios_base::openmode mode) :file_name_(file_name), daFile(file_name, mode) { HowLong(); }//for opening in specified mode;
	bool Open(const string& file_name);
	bool Open(const string& file_name, ios_base::openmode mode);
	bool IsOpen();
	void Write(const string& input);
	void Write(const string& input, int where);
	void Write(const char* input, const int& offset, const int& lenght);
	void Write(const char* input, const int& offset, const int& lenght, const int& offset_infile);
	void Read(string& reader_);
	void Read(string& reader_, int where);
	void ReadStr(char* reader_, int where);
	void reOpen(ios_base::openmode mode);
	void HowLong();
	void HowLong(int dest_file_size);
	void close();
	int returnLenght();

};


#endif // !wrapper
