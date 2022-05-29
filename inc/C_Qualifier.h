#ifndef __C_QUALIFIER_H__
#define __C_QUALIFIER_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "C_Keyword.h"
#include "E_C_Keywords.h"
#include "Helper_Functions.h"

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class C_Qualifier : public C_Keyword
{
	protected:
		E_C_QUALIFIER _qualifier;

	public:
		C_Qualifier(E_C_QUALIFIER qualifier = E_C_QUALIFIER::NONE);
		C_Qualifier(const C_Qualifier & c_qualifier);
		virtual ~C_Qualifier() = default;

		inline std::string to_Str(void) const noexcept override { return E_C_QUALIFIER_to_Str(_qualifier); }
};

#endif // __C_QUALIFIER_H__
