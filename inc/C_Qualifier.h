#ifndef __C_QUALIFIER_H__
#define __C_QUALIFIER_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "C_Keyword.h"
#include "E_C_Keywords.h"

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

		std::string to_Str(void) const override;
};

#endif // __C_QUALIFIER_H__