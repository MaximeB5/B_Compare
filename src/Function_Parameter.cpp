// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Function_Parameter.h"
#include "Helper_Functions.h"

#include <utility>
#include <exception>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & content"></param>
Function_Parameter::Function_Parameter(const std::string & content)
	: Data(content), _parameter_type(content)
{
	std::size_t pos = content.find_last_of(" ");

	if (pos == std::string::npos)
	{
		// Case where we'd have void
		_parameter_type.set_type("void");
		_parameter_name = "";
	}
	else
	{
		_parameter_type.set_type(content.substr(0, pos));
		_parameter_name = content.substr(pos + 1);
	}
}

// ------------------------------------------------
// ------------------------------------------------
