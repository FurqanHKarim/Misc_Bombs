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

	void close()
	{
		for (size_t i = 0; i < no_of_smaller_files; i++)
		{
			grand_file_[i].close();
		}
	}
	void bigRead(char* _arr, int lenght_of_arr)
	{
		int offset = 0;
		int end_limit = 0;
		int files = lenght_of_arr / (1 << 17);
		end_limit = lenght_of_arr - files *(1 << 17);


		for (int i = 0; i < files; i++)
		{
			offset = i * (1 << 17);

			if ((i == files - 1)&&(end_limit>0))
			{
				grand_file_[i].ReadStr(_arr + offset, end_limit);
				continue;
			}

			grand_file_[i].ReadStr(_arr+offset, 1 << 17);
		}
		
	}

	void emptyFile() 
	{
		for (int i = 0; i < no_of_smaller_files; i++)
		{
			grand_file_[i].reOpen(ios::out | ios::in | ios::trunc);
			grand_file_[i].reOpen(ios::out | ios::in | ios::app);
		}


	}

	BigFile(const string& _filename_, const double& file_size_in_Mb)
	{
		file_size_ = file_size_in_Mb * 1024 * 1024;
		no_of_smaller_files = (file_size_ / (1 << 17));
		bacha_hua_maal = (file_size_ % (1 << 17));

		if (bacha_hua_maal > 0)
			no_of_smaller_files++;

		populate_em(_filename_);


	}
	
	void populate_em(const string &_filename_)
	{
		grand_file_.resize(no_of_smaller_files);
		for (int i = 0; i < no_of_smaller_files; i++)
		{	
			grand_file_[i].Open((_filename_ + to_string(i) + ".txt"), ios::out | ios::in);
			grand_file_[i].HowLong(1<<17);

		}

	}

	void bigWrite(const char* _arr_, size_t lenght)
	{
		int offset;
		int final = 0;

		
		for (size_t i = 0; i < (lenght / (1 << 17)); i++)
		{
			offset = i * (1 << 17);
			if (offset + (1 << 17) > lenght)
			{
				final = offset + (1 << 17) - lenght;
				grand_file_[i].Write(_arr_, i * (1 << 17), final);
				continue;
			}

			grand_file_[i].Write(_arr_, i * (1 << 17), 1 << 17);
		}
	}

	void bigWriteAnywhere(const char* _arr_, const int& lenght, const int& whereto)
	{
		int file_offset;
		int in_file_offset;
		
		int offset;
		int final = 0;


		file_offset = whereto / (1 << 17);
		in_file_offset = whereto % (1 << 17);

		for (size_t i = 0; i <= (lenght / (1 << 17)); i++)
		{
			offset = i * (1 << 17);
			if (offset + (1 << 17) > lenght)
			{
				final = offset + (1 << 17) - lenght;
				//Write(const char* input, const int& offset, const int& lenght,const int& offset_infile)

				grand_file_[i+file_offset].Write(_arr_, 0, lenght, in_file_offset);
				continue;
			}

			grand_file_[i + file_offset].Write(_arr_, i * (1 << 17), 1 << 17,in_file_offset);
			in_file_offset = 0;
		}
	}

};



#endif // !BIGBOY

