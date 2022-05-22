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
		std::vector<std::string> _comment_block;

		bool _is_static;

		bool _is_returned_value_const;
		std::string _returned_value_type;

		std::string _name;
		std::vector<Function_Parameter> _parameters;

	public:
		Function(const std::string & signature);
		virtual ~Function() = default;

		std::string to_Str(void) const override;

		// ------------------------------------------------
		// Inline Getters
		// ------------------------------------------------
		inline std::vector<std::string>			get_comment_block(void) const			{ return _comment_block; }
		inline bool								get_is_static(void) const				{ return _is_static; }
		inline bool								get_is_returned_value_const(void) const	{ return _is_returned_value_const; }
		inline std::string						get_returned_value_type(void) const		{ return _returned_value_type; }
		inline std::string						get_name(void) const					{ return _name; }
		inline std::vector<Function_Parameter>	get_parameters(void) const				{ return _parameters; }
};

#endif // __FUNCTION_H__
