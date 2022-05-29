#ifndef __C_KEYWORD_H__
#define __C_KEYWORD_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

/// <summary>
/// Wrapper class
/// </summary>
class C_Keyword : public Data
{
	public:
		C_Keyword(const std::string & content) : Data(content) {}
		virtual ~C_Keyword() = default;

		std::string to_Str(void) const noexcept override = 0;
};

#endif // __C_KEYWORD_H__
