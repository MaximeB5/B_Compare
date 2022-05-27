// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "File_Reader.h"

#include <stdexcept>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

File_Reader::File_Reader(const std::string & file_name)
	: _file_name(file_name), _file_stream(file_name, std::ifstream::in)
{
	if (!_file_stream.good()) { throw std::runtime_error("File_Reader object for the file '" + file_name + "' failed on constructor."); }

	// TODO ?
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

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// The purpose of this method is to fill the members of the class
/// It has to analyze the file in order to find the patterns of a function
/// </summary>
/// <param name=""></param>
void File_Reader::read_file(void) noexcept
{
	std::size_t dot_position = _file_name.find_last_of('.');

	// TODO for .c files and .h files
}

// ------------------------------------------------
// ------------------------------------------------
