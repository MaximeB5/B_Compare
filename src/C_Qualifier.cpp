// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "C_Qualifier.h"
#include "Helper_Functions.h"

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="E_C_QUALIFIER qualifier"></param>
C_Qualifier::C_Qualifier(E_C_QUALIFIER qualifier)
	: C_Keyword(E_C_QUALIFIER_to_Str(qualifier)), _qualifier(qualifier)
{
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// Copy Constructor
/// </summary>
/// <param name="const C_Qualifier & c_qualifier"></param>
C_Qualifier::C_Qualifier(const C_Qualifier & c_qualifier)
	: C_Keyword(c_qualifier._data_content)
{
	_qualifier = c_qualifier._qualifier;
}

std::string C_Qualifier::to_Str(void) const
{
	return _data_content;
}

// ------------------------------------------------
// ------------------------------------------------
