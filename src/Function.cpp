// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Function.h"
#include "Helper_Functions.h"

#include <stdexcept>
#include <algorithm>
#include <iostream>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & signature"></param>
/// <param name="const std::vector<std::string> & function_content"></param>
/// <param name="const std::vector<std::string> & comment_block"></param>
Function::Function(const std::string & signature, const std::vector<std::string> & function_content, const std::vector<std::string> & comment_block)
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

	// What's now left of the signature's function is/are the parameter(s) of the function
	// They're representated by what's inside the parenthesis
	// The open parenthesis position is known from the steps above
	// The closing parenthesis is the last character of the signature string
	// The string inside both parenthesis can be parsed on the ',' to define the different parameters
	
	std::string inside_parenthesis	= signature.substr(pos_open_parenthesis + 1, signature.find_last_of(')'));
	size_t number_of_comma			= std::count(inside_parenthesis.begin(), inside_parenthesis.end(), ',');

	// '+ 1' allows to handle the last parameter, or the only one in the case where there is no comma
	for (unsigned int i{ 0 }; i != number_of_comma + 1 ; ++i)
	{
		// Delete all leading spaces and tabs
		inside_parenthesis.erase(0, inside_parenthesis.find_first_not_of(" \t"));

		std::size_t pos_comma = inside_parenthesis.find_first_of(',');

		if (pos_comma == std::string::npos)
		{
			// Push back the last parameter OR the only one
			_parameters.push_back(Function_Parameter(inside_parenthesis.substr(0, inside_parenthesis.find(')'))));
			break;
		}
		else
		{
			_parameters.push_back(Function_Parameter( inside_parenthesis.substr(0, pos_comma) ));
			inside_parenthesis = inside_parenthesis.substr(pos_comma + 1);
		}
	}
}

// ------------------------------------------------
// ------------------------------------------------
