#ifndef __C_TYPE_H__
#define __C_TYPE_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "C_Keyword.h"
#include "E_C_Keywords.h"

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class C_Type : public C_Keyword
{
	protected:
		E_C_TYPE _type;

	public:
		C_Type(E_C_TYPE qualifier);
		C_Type(const C_Type & C_Type);
		virtual ~C_Type() = default;

		std::string to_Str(void) const override;
};

#endif // __C_TYPE_H__