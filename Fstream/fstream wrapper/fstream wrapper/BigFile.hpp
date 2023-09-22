#ifndef BIGBOY
#define BIGBOY

#include"FileHandler.h"
#include<vector>

class BigFile {
private:
	vector<FileHandler> grand_file_;
	int file_size_;
	int no_of_smaller_files;
	int bacha_hua_maal;
	unsigned int current_location_;

public:
	BigFile();
	
	BigFile(const string& _filename_, const double& file_size_in_Mb);
	
	void close();

	void bigRead(char* _arr, int lenght_of_arr);

	void emptyFile();

	void bigSeek(const int& location);

	int bigTell();
	
	void populate_em(const string& _filename_);

	void bigWriteStart(const char* _arr_, size_t lenght);

	void bigWriteAnywhere(const char* _arr_, const int& lenght);

};



#endif // !BIGBOY
