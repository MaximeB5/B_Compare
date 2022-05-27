// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Function.h"
#include "Helper_Functions.h"

#include <stdexcept>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & signature"></param>
Function::Function(const std::string & signature, const std::vector<std::string> & comment_block, const std::vector<std::string> & function_content)
	:	Data(signature), _comment_block(comment_block), _function_content(function_content)
{
	// First part of the function's signature is defined by the first occurence of '('. It contains the following :
	// (1) Staticness
	// (2) Constness of the returned value
	// (3) Function's name
	// (4) Returned value

	// Get the first part of the function's signature
	std::size_t pos_open_parenthesis = signature.find_first_of("(");
	
	if (pos_open_parenthesis == std::string::npos) { throw std::runtime_error("Error 001 when analyzing Function '" + signature + "'"); }
	
	std::string first_part = signature.substr(0, pos_open_parenthesis);

	// ------------------------------------------------
	// (1) and (2)
	// ------------------------------------------------
	_is_static					= first_part.find( E_C_QUALIFIER_to_Str(E_C_QUALIFIER::STATIC) ) != std::string::npos ? true : false;
	_is_returned_value_const	= first_part.find( E_C_QUALIFIER_to_Str(E_C_QUALIFIER::CONST)  ) != std::string::npos ? true : false;

	// ------------------------------------------------
	// (3)
	// ------------------------------------------------
	std::size_t pos_space_before_name = first_part.find_last_of(" ");
	
	if (pos_space_before_name == std::string::npos) { throw std::runtime_error("Error 002 when analyzing Function '" + signature + "'"); }
	
	_name = first_part.substr(pos_space_before_name + 1, pos_open_parenthesis);

	// ------------------------------------------------
	// (4)
	// ------------------------------------------------
	std::string returned_value = first_part.substr(0, pos_space_before_name);

	if (_is_static)
	{
		// Remove the static qualifier from the string  'static ' located at the beginning of the string (!) THIS IS MANDATORY (!)
		returned_value.erase(0, 7);
	}

	_returned_value_type = returned_value;
}

// ------------------------------------------------
// ------------------------------------------------

std::string Function::to_Str(void) const
{
	return _name;
}

// ------------------------------------------------
// ------------------------------------------------
