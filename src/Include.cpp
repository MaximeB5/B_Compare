// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Include.h"

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & content"></param>
/// <param name="const bool &  is_user_defined"></param>
Include::Include(const std::string & content, const bool & is_user_defined)
	: Data(content), _content(content), _is_user_defined(is_user_defined)
{
}