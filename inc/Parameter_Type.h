#ifndef __PARAMETER_TYPE_H__
#define __PARAMETER_TYPE_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"

#include <string>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Parameter_Type : public Data
{
	protected:
		std::string _content;

	public:
		Parameter_Type() = delete;
		Parameter_Type(const std::string & content);
		virtual ~Parameter_Type() = default;

		inline std::string to_Str(void) const noexcept override { return _content; }

		inline void set_type(std::string type)	noexcept		{ _content = type; _data_content = type; };
		inline auto get_type(void)				const noexcept	{ return _content; };
};

#endif // __PARAMETER_TYPE_H__
