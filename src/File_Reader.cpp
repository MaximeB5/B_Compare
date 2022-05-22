// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "File_Reader.h"

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

File_Reader::File_Reader(const std::string & file_name)
	: _file_stream(file_name, std::ifstream::in)
{
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// Destructor
/// </summary>
File_Reader::~File_Reader()
{
	_file_stream.close();
}

void File_Reader::read_file(void)
{
}

// ------------------------------------------------
// ------------------------------------------------
