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

public:
	BigFile() {

	}

	BigFile(const double& file_size_in_Mb)
	{
		file_size_ = file_size_in_Mb*1024*1024 ;
		no_of_smaller_files = (file_size_ / (1 << 17));
		bacha_hua_maal = (file_size_ % (1 << 17));

		if (bacha_hua_maal > 0)
			no_of_smaller_files++;
		
		populate_em();


	}
	
	void populate_em()
	{
		grand_file_.resize(no_of_smaller_files);
		for (int i = 0; i < no_of_smaller_files; i++)
		{	
			grand_file_[i].Open(("File" + to_string(i) + ".txt"), ios::out | ios::in | ios::trunc);
			grand_file_[i].HowLong(1<<17);

		}

	}


	
};



#endif // !BIGBOY

