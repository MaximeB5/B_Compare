// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "C_Type.h"

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="E_C_TYPE type"></param>
C_Type::C_Type(E_C_TYPE type)
	: C_Keyword(E_C_TYPE_to_Str(type)), _type(type)
{
}

// ------------------------------------------------
// ------------------------------------------------

/// <summary>
/// Copy Constructor
/// </summary>
/// <param name="const C_Type & type"></param>
C_Type::C_Type(const C_Type & type)
	: C_Keyword(type._data_content)
{
	_type = type._type;
}

// ------------------------------------------------
// ------------------------------------------------
