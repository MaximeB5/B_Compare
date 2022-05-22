#ifndef __FUNCTION_H__
#define __FUNCTION_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"
#include "Function_Parameter.h"

#include <string>
#include <vector>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Function : public Data
{
	protected:
		bool _is_static;

		bool _is_returned_value_const;
		std::string _returned_value_type;

		std::string _name;
		std::vector<Function_Parameter> _parameters;

	public:
		Function(const std::string & signature);
		virtual ~Function() = default;

		std::string to_Str(void) const override;
};

#endif // __FUNCTION_H__