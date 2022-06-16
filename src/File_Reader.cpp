// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "File_Reader.h"

#include <stdexcept>
#include <algorithm>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

File_Reader::File_Reader(const std::string & file_name)
	: _file_name(file_name), _file_stream(file_name, std::ifstream::in)
{
	if (!_file_stream.good()) { throw std::runtime_error("File_Reader object for the file '" + file_name + "' failed on constructor."); }

	std::size_t dot_position = _file_name.find_last_of('.');
	
	if (dot_position == std::string::npos) { throw std::runtime_error("File_Reader object for the file '" + file_name + 
																		"' failed on constructor a file due to a lack of extension."); }
	
	_file_extension = _file_name.substr(dot_position + 1);
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
/// This method is the public interface for the user
/// It performs blocking checks if they fail before reading the file
/// </summary>
/// <param name=""></param>
void File_Reader::read_file(void) noexcept
{
	if (_file_extension != "h" && _file_extension != "c")
	{
		throw std::runtime_error("File_Reader object cannot read_file for the '" + _file_name + 
									"' because this extension is NOT supported yet.");
	}

	_read_file();
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// This functions reads the file
/// 
/// Common stuff between .c and .h files are the following :
///		- Includes
///		- Defines
///
/// Differences are listed below :
///		- Function handling :
///			For .h files, get the signature and the comment block if it exists
///			For .c files, get the signature, the comment block if it exists, and then get the content
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
void File_Reader::_read_file(void) noexcept
{
	// Patterns to match
	const std::string INCLUDE{ "#include" };
	const std::string DEFINE{ "#define" };
	const std::string COMMENT_START{ "/*" };
	const std::string COMMENT_END{ "*/" };
	const std::string LEFT_CURLY_BRACKET{ "{" };
	const std::string RIGHT_CURLY_BRACKET{ "}" };

	// Variables to help
	std::string line;
	std::vector<std::string> comment_block;
	std::vector<std::string> function_content;
	bool line_is_in_a_comment_block{ false };
	bool line_is_in_a_function{ false };
	unsigned int counter_left_curly_bracket{ 0 };
	unsigned int counter_right_curly_bracket{ 0 };

	while (std::getline(_file_stream, line))
	{
		// Include
		if (line.find(INCLUDE) != std::string::npos && !line_is_in_a_comment_block && !line_is_in_a_function)
		{
			_includes.push_back(_get_include_from_str(line));
		}

		// Define
		else if (line.find(DEFINE) != std::string::npos && !line_is_in_a_comment_block && !line_is_in_a_function)
		{
			_defines.push_back(_get_define_from_str(line));
		}

		// Comment block start
		else if (line.find(COMMENT_START) != std::string::npos && !line_is_in_a_comment_block && !line_is_in_a_function)
		{
			line_is_in_a_comment_block = true;
			comment_block.push_back(line.substr(line.find(COMMENT_START) + COMMENT_START.size()));
		}

		// Comment block end
		else if (line.find(COMMENT_END) != std::string::npos && line_is_in_a_comment_block && !line_is_in_a_function)
		{
			line_is_in_a_comment_block = false;
		}

		// Inside a comment block
		else if (line_is_in_a_comment_block)
		{
			comment_block.end()->append(" \n" + line);
		}

		// Inside a function - only .c file
		else if (line_is_in_a_function)
		{
			counter_left_curly_bracket  += std::count(line.begin(), line.end(), LEFT_CURLY_BRACKET);
			counter_right_curly_bracket += std::count(line.begin(), line.end(), RIGHT_CURLY_BRACKET);

			function_content.push_back(line);

			// Exit case - we met the last right curly bracket
			if (counter_left_curly_bracket == counter_right_curly_bracket)
			{
				line_is_in_a_function = false;
			}
		}

		// Detect a function signature
		else if (_is_a_function(line))
		{
			// Only .c file
			if (_file_extension == "c")
			{
				line_is_in_a_function = true;
			}
		}

		// Analyze the case ?
		else
		{
			// TODO
		}
	}
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// This method parses the given line to construct an Include
/// 
/// -----------
/// MANDATORY :
/// -----------
/// The line must contain an include preprocessor instruction
/// 
/// </summary>
/// <param name="const std::string & line"></param>
/// <returns>An Include object</returns>
Include File_Reader::_get_include_from_str(const std::string & line) const noexcept
{
	const std::string INCLUDE{ "#include" };

	std::string result = line.substr(line.find(INCLUDE) + INCLUDE.size());
	bool is_user_defined{ result.find("\"") != std::string::npos };

	if (is_user_defined)
	{
		return Include( result.substr(result.find_first_of("\"") + 1, result.find_last_of("\"")), is_user_defined );
	}
	else
	{
		return Include( result.substr(result.find("<") + 1, result.find(">")), is_user_defined );
	}
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// This method parses the given line to construct a Define
/// 
/// -----------
/// MANDATORY :
/// -----------
/// The line must contain a define preprocessor instruction
/// 
/// </summary>
/// <param name="const std::string & line"></param>
/// <returns>A Define object</returns>
Define File_Reader::_get_define_from_str(const std::string & line) const noexcept
{
	const std::string DEFINE{ "#define" };

	std::string result = line.substr(line.find(DEFINE) + DEFINE.size());

	std::replace(result.begin(), result.end(), '\t', ' ');	// Replace tabs by spaces
	result.erase(0, result.find_first_not_of(" "));			// Delete all leading spaces

	// Now, the result string is formated, so we can get the define's name
	std::string define_name{ result.substr(0, result.find_first_of(" ")) };

	// Delete the define's name and all leading spaces after the name and its value
	result.erase(define_name.size());
	result.erase(0, result.find_first_not_of(" "));

	std::string define_value{ result };

	// Delete the spaces at the end if there are any
	std::size_t pos = define_value.find(" ");
	if (pos != std::string::npos)
	{
		define_value.erase(pos);
	}

	return Define(define_name, define_value);
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// 
/// </summary>
/// <param name="const std::string & line"></param>
/// <returns>True if the line is a function's signature, else false</returns>
bool File_Reader::_is_a_function(const std::string & line) const noexcept
{
	std::size_t pos_open_parenthesis = line.find_first_of("(");

	if (pos_open_parenthesis == std::string::npos) { return false; }	// A function's signature must contain at least one '('

	// ------------------------------------------------

	std::string first_part = line.substr(0, pos_open_parenthesis);		// Get all chars from 0 to the '(' after the function's name
	std::replace(first_part.begin(), first_part.end(), '\t', ' ');		// Replace tabs by spaces
	first_part.erase(0, first_part.find_first_not_of(" "));				// Delete all leading spaces
	std::size_t pos_space_before_name = first_part.find_last_of(" ");	// Used to get the function's name

	if (pos_space_before_name == std::string::npos) { return false; }	// If no space, then it might be a function's call (e.g. myStruct.Func();)

	// ------------------------------------------------

	if (first_part.find("=") != std::string::npos)	{ return false; }	// If there is a '=' in the first part, so this is not a function

	// ------------------------------------------------

	// All checks didn't fail, so we assume by default it's a function
	// This way, if there is a lack of checks, we can add them
	return true;
}

// ------------------------------------------------
// ------------------------------------------------
