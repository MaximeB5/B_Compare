// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Define.h"

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & define_name"></param>
/// <param name="const std::string & define_value"></param>
Define::Define(const std::string & define_name, const std::string & define_value)
	: Data(_define_name + " " + _define_value), _define_name(define_name), _define_value(define_value)
{
}