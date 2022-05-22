// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Helper_Functions.h"

#include <map>

// ------------------------------------------------
// Static Variables
// ------------------------------------------------

static const std::map<E_C_QUALIFIER, std::string> _qualifiers
{
	{ E_C_QUALIFIER::CONST,		"const" },
	{ E_C_QUALIFIER::STATIC,	"static" },
	{ E_C_QUALIFIER::VOLATILE,	"volatile" }
};

static const std::map<E_C_TYPE, std::string> _types
{
	// Regular Types

	{ E_C_TYPE::VOID,						"void" },

	{ E_C_TYPE::CHAR,						"char" },
	{ E_C_TYPE::SIGNED_CHAR,				"signed char" },
	{ E_C_TYPE::UNSIGNED_CHAR,				"unsigned char" },

	{ E_C_TYPE::SHORT,						"short" },
	{ E_C_TYPE::SHORT_INT,					"short int" },
	{ E_C_TYPE::SIGNED_SHORT,				"signed short" },
	{ E_C_TYPE::SIGNED_SHORT_INT,			"signed short int" },

	{ E_C_TYPE::UNSIGNED_SHORT,				"unsigned short" },
	{ E_C_TYPE::UNSIGNED_SHORT_INT,			"unsigned short int" },

	{ E_C_TYPE::INT,						"int" },
	{ E_C_TYPE::SIGNED,						"signed" },
	{ E_C_TYPE::SIGNED_INT,					"signed int" },

	{ E_C_TYPE::UNSIGNED,					"unsigned" },
	{ E_C_TYPE::UNSIGNED_INT,				"unsigned int" },

	{ E_C_TYPE::LONG,						"long" },
	{ E_C_TYPE::LONG_INT,					"long int" },
	{ E_C_TYPE::SIGNED_LONG,				"igned long" },
	{ E_C_TYPE::SIGNED_LONG_INT,			"igned long int" },

	{ E_C_TYPE::UNSIGNED_LONG,				"unsigned long" },
	{ E_C_TYPE::UNSIGNED_LONG_INT,			"unsigned long int" },

	{ E_C_TYPE::LONG_LONG,					"long long" },
	{ E_C_TYPE::LONG_LONG_INT,				"long long int" },
	{ E_C_TYPE::SIGNED_LONG_LONG,			"signed unsigned long long" },
	{ E_C_TYPE::SIGNED_LONG_LONG_INT,		"signed unsigned long long int" },

	{ E_C_TYPE::UNSIGNED_LONG_LONG,			"unsigned long long" },
	{ E_C_TYPE::UNSIGNED_LONG_LONG_INT,		"unsigned long long int" },

	{ E_C_TYPE::FLOAT,						"float" },

	{ E_C_TYPE::DOUBLE,						"double" },

	{ E_C_TYPE::LONG_DOUBLE,				"long double" },

	// Ptr Types

	{ E_C_TYPE::PTR_VOID,					"void*" },

	{ E_C_TYPE::PTR_CHAR,					"char*" },
	{ E_C_TYPE::PTR_SIGNED_CHAR,			"signed char*" },
	{ E_C_TYPE::PTR_UNSIGNED_CHAR,			"unsigned char*" },

	{ E_C_TYPE::PTR_SHORT,					"short*" },
	{ E_C_TYPE::PTR_SHORT_INT,				"short int*" },
	{ E_C_TYPE::PTR_SIGNED_SHORT,			"signed short*" },
	{ E_C_TYPE::PTR_SIGNED_SHORT_INT,		"signed short int*" },

	{ E_C_TYPE::PTR_UNSIGNED_SHORT,			"unsigned short*" },
	{ E_C_TYPE::PTR_UNSIGNED_SHORT_INT,		"unsigned short int*" },

	{ E_C_TYPE::PTR_INT,					"int*" },
	{ E_C_TYPE::PTR_SIGNED,					"signed*" },
	{ E_C_TYPE::PTR_SIGNED_INT,				"signed int*" },

	{ E_C_TYPE::PTR_UNSIGNED,				"unsigned*" },
	{ E_C_TYPE::PTR_UNSIGNED_INT,			"unsigned int*" },

	{ E_C_TYPE::PTR_LONG,					"long*" },
	{ E_C_TYPE::PTR_LONG_INT,				"long int*" },
	{ E_C_TYPE::PTR_SIGNED_LONG,			"signed long*" },
	{ E_C_TYPE::PTR_SIGNED_LONG_INT,		"signed long int*" },

	{ E_C_TYPE::PTR_UNSIGNED_LONG,			"unsigned long*" },
	{ E_C_TYPE::PTR_UNSIGNED_LONG_INT,		"unsigned long int*" },

	{ E_C_TYPE::PTR_LONG_LONG,				"long long*" },
	{ E_C_TYPE::PTR_LONG_LONG_INT,			"long long int*" },
	{ E_C_TYPE::PTR_SIGNED_LONG_LONG,		"signed long long*" },
	{ E_C_TYPE::PTR_SIGNED_LONG_LONG_INT,	"signed long long int*" },

	{ E_C_TYPE::PTR_UNSIGNED_LONG_LONG,		"unsigned long long*" },
	{ E_C_TYPE::PTR_UNSIGNED_LONG_LONG_INT,	"unsigned long long int*" },

	{ E_C_TYPE::PTR_FLOAT,					"float*" },

	{ E_C_TYPE::PTR_DOUBLE,					"double*" },

	{ E_C_TYPE::PTR_LONG_DOUBLE,			"long double*" }
};

// ------------------------------------------------
// Function Implementations
// ------------------------------------------------

std::string E_C_TYPE_to_Str(const E_C_TYPE & type)
{
	for (auto const & t : _types)
	{
		if (t.first == type) { return t.second; }
	}

	return "";
}

// ------------------------------------------------
// ------------------------------------------------

E_C_TYPE Str_to_E_C_TYPE(const std::string & type)
{
	for (auto const & t : _types)
	{
		if (t.second == type) { return t.first; }

	}
	return E_C_TYPE::NONE;
}

// ------------------------------------------------
// ------------------------------------------------

std::string E_C_QUALIFIER_to_Str(const E_C_QUALIFIER & qualifier)
{
	for (auto const & q : _qualifiers)
	{
		if (q.first == qualifier) { return q.second; }
	}

	return "";
}

// ------------------------------------------------
// ------------------------------------------------

E_C_QUALIFIER Str_to_E_C_QUALIFIER(const std::string & qualifier)
{
	for (auto const & q : _qualifiers)
	{
		if (q.second == qualifier) { return q.first; }
	}

	return E_C_QUALIFIER::NONE;
}
