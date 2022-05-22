#ifndef __FUNCTION_PARAMETER_H__
#define __FUNCTION_PARAMETER_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"
#include "C_Type.h"
#include "C_Qualifier.h"

#include <vector>
#include <memory>
#include <string>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Function_Parameter : public Data
{
	protected:
		std::vector<std::unique_ptr<Data>> _content;
		std::string _parameter_name;

	public:
		Function_Parameter(const std::string & content);
		virtual ~Function_Parameter() = default;

		std::string to_Str(void) const override;
};

#endif // __FUNCTION_PARAMETER_H__