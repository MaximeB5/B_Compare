#ifndef __FILE_READER_H__
#define __FILE_READER_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"

#include <string>
#include <fstream>
#include <vector>
#include <memory>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class File_Reader
{
	protected:
		std::string _file_name;
		std::ifstream _file_stream;
		std::vector<std::unique_ptr<Data> > _file_data;

	public:
		File_Reader(const std::string & file_name);
		~File_Reader();

		void read_file(void) noexcept;

		inline bool is_ready_to_read(void) const { return _file_stream.is_open(); }
};

#endif // __FILE_READER_H__
