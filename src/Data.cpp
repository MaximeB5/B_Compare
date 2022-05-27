// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"

#include <utility>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="std::string content"></param>
Data::Data(std::string content)
	: _data_content(content)
{
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// Copy Constructor
/// </summary>
/// <param name="const Data & data"></param>
Data::Data(const Data & data)
{
	_data_content = data._data_content;
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// Returns the content of the Data instance
/// </summary>
/// <param name=""></param>
/// <returns></returns>
std::string Data::data_to_Str(void) const
{
	return _data_content;
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// to_Str returns the content of the Data instance as a std::string
/// </summary>
/// <returns>_data_content as std::string</returns>
std::string Data::to_Str(void) const
{
	return _data_content;
}
