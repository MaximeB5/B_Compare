// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Function.h"

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & signature"></param>
Function::Function(const std::string& signature) :
	Data(signature)
{
}

std::string Function::to_Str(void) const
{
	return _data_content;
}

// ------------------------------------------------
// ------------------------------------------------
