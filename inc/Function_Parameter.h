#ifndef __FUNCTION_PARAMETER_H__
#define __FUNCTION_PARAMETER_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"
#include "Parameter_Type.h"

#include <string>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Function_Parameter : public Data
{
	protected:
		Parameter_Type _parameter_type;
		std::string _parameter_name;

	public:
		Function_Parameter(const std::string & content);
		virtual ~Function_Parameter() = default;

		inline std::string to_Str(void) const noexcept override { return _parameter_type.get_type() + " " + _parameter_name; }

		// ------------------------------------------------
		// Inline Getters
		// ------------------------------------------------
		inline auto get_type(void) const noexcept { return _parameter_type.get_type(); }
		inline auto get_name(void) const noexcept { return _parameter_name; }
};

#endif // __FUNCTION_PARAMETER_H__
