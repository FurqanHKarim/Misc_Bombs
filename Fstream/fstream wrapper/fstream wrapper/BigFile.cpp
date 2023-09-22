
#include"BigFile.hpp"

BigFile:: BigFile() {

};


BigFile:: BigFile(const string& _filename_, const double& file_size_in_Mb)
{
	file_size_ = file_size_in_Mb * 1024 * 1024;
	no_of_smaller_files = (file_size_ / (1 << 17));
	bacha_hua_maal = (file_size_ % (1 << 17));

	if (bacha_hua_maal > 0)
		no_of_smaller_files++;

	current_location_ = 0;
	populate_em(_filename_);
	

}


void BigFile::bigSeek(const int& location)
{
	current_location_ = location;
	return;
}


int BigFile::bigTell()
{
	return current_location_;
}

void BigFile::close()
{
	for (size_t i = 0; i < no_of_smaller_files; i++)
	{
		grand_file_[i].close();
	}
}


void BigFile::bigRead(char* _arr, int lenght_of_arr)
{
	int offset = 0;
	int end_limit = 0;
	int files = lenght_of_arr / (1 << 17);
	end_limit = lenght_of_arr - files * (1 << 17);

	int file_offset = 0;
	int in_file_offset = 0;

	file_offset = current_location_ / (1 << 17);
	in_file_offset = current_location_ % (1 << 17);
	for (int i = 0; i < files; i++)
	{

		if ((i == files - 1) && (end_limit > 0))
		{
			grand_file_[i + file_offset].ReadStr(_arr + offset, end_limit);
			continue;
		}
		grand_file_[i + file_offset].seeker(in_file_offset);
		grand_file_[i + file_offset].ReadStr(_arr + offset, 1 << 17);
		offset += (1 << 17) - in_file_offset;
		in_file_offset = 0;
		grand_file_[i + file_offset].seeker(0);
	}
	current_location_ += lenght_of_arr;
}


void BigFile::emptyFile()
{
	for (int i = 0; i < no_of_smaller_files; i++)
	{
		grand_file_[i].reOpen(ios::out | ios::in | ios::trunc);
		grand_file_[i].reOpen(ios::out | ios::in | ios::app);
	}


}


void BigFile::populate_em(const string& _filename_)
{

	grand_file_.resize(no_of_smaller_files);
	for (int i = 0; i < no_of_smaller_files; i++)
	{
		grand_file_[i].Open((_filename_ + to_string(i) + ".txt"), ios::out | ios::in);
		grand_file_[i].HowLong(1 << 17);
		grand_file_[i].seeker(0);
	}

}


void BigFile::bigWriteStart(const char* _arr_, size_t lenght)
{
	int offset;
	int final = 0;


	for (size_t i = 0; i <= (lenght / (1 << 17)); i++)
	{
		offset = i * (1 << 17);
		if (offset + (1 << 17) > lenght)
		{
			if ((1 << 17) > lenght) {
				final = lenght;
			}
			else {
				final = lenght - offset;
			}
			grand_file_[i].Write(_arr_, offset, final);
			continue;
		}

		grand_file_[i].Write(_arr_, offset, 1 << 17);
	}
}


void BigFile:: bigWriteAnywhere(const char* _arr_, const int& lenght)
{

	if (current_location_ + lenght > file_size_)
	{
		cout << "Exceeds File size, Command Aborted:" << endl;
		return;
	}

	int file_offset;
	int in_file_offset;

	int offset = 0;
	int final = 0;


	file_offset = current_location_/ (1 << 17);
	in_file_offset = current_location_ % (1 << 17);

	for (size_t i = 0; i <= (lenght / (1 << 17)); i++)
	{

		if (offset + (1 << 17) > lenght)
		{
			if ((1 << 17) > lenght) {
				final = lenght;
			}
			else {
				final = lenght - offset;
			}
			grand_file_[i + file_offset].seeker(in_file_offset);
			grand_file_[i + file_offset].Write(_arr_, offset, final);
			continue;
		}

		grand_file_[i + file_offset].seeker(in_file_offset);
		grand_file_[i + file_offset].Write(_arr_, offset, (1 << 17) - in_file_offset);
		offset += (1 << 17) - in_file_offset;
		in_file_offset = 0;
		grand_file_[i + file_offset].seeker(0);
	}
	current_location_ += lenght;

}
