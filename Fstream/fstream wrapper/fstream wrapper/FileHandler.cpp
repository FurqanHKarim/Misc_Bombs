#include"FileHandler.h"


void FileHandler:: reOpen(ios_base::openmode mode)
{
	daFile.close();
	daFile.open(file_name_, mode);
	IsOpen();

	return;
}


int FileHandler::returnLenght()
{
	return this->file_lenght_;
}

void FileHandler::HowLong()
{
	if (!this->IsOpen())
		return;

	daFile.seekg(0,daFile.end);
	this->file_lenght_ = daFile.tellg();
	daFile.seekg(0, daFile.beg);
	return ;

}

void FileHandler::HowLong(int dest_file_size)
{
	if (!this->IsOpen())
		return;
	this->file_lenght_ = dest_file_size;
	return;

}

void FileHandler::Read(string& reader_, int where)
{
	if (!this->IsOpen())
		return;
	daFile.seekg(where);
	reader_.clear();
	getline(daFile, reader_);
	return;

}


void FileHandler::Read(string& reader_)
{
	string test;
	test = reader_;
	reader_.clear();
	getline(daFile, reader_);

	if (daFile.tellg() == -1)
	{
		cout << "Reached File end" << endl;
		daFile.clear();
	}
	return;

}

void FileHandler::Write(const string& input, int where)
{
	if (!this->IsOpen())
		return;

	daFile.seekp(where);
	daFile.write(input.c_str(), input.size());
	HowLong();
}

void FileHandler::Write(const string& input)
{
	
	if (!this->IsOpen())
		return;

	daFile.write(input.c_str(), input.size());
	HowLong();


}

bool FileHandler::Open(const string& file_name, ios_base::openmode mode) {
	
	this->file_name_ = file_name;
	daFile.open(file_name_, mode);
	if (!this->IsOpen())
		return 0;

	return 1;
}

bool FileHandler::Open(const string& file_name)
{
	this->file_name_ = file_name;
	daFile.open(file_name_, ios::out | ios::in);
	HowLong();

	if (!this->IsOpen())
		return 0;

	return 1;
}

bool FileHandler::IsOpen() {

	if (!daFile.is_open())
	{
		cout << "File is not Open:";
		return 0;
	}

	return 1;
}

void printCompleteCharArray(const char* arr_)
{
	for (size_t i = 0; (i < 90) && (arr_[i] != '\0'); i++)
	{
		cout << arr_[i];
	}
	return;
}


FileHandler::FileHandler() {}
