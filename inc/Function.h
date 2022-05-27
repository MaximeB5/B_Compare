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

		/* Function's Signature - Begin */
		bool _is_static;

		bool _is_returned_value_const;
		std::string _returned_value_type;

		std::string _name;
		std::vector<Function_Parameter> _parameters;
		/* Function's Signature - End */

		std::vector<std::string> _function_content;

	public:
		Function() = delete;
		Function(const std::string & signature, const std::vector<std::string> & function_content, const std::vector<std::string> & comment_block);
		virtual ~Function() = default;

		std::string to_Str(void) const override;

		// ------------------------------------------------
		// Inline Getters
		// ------------------------------------------------
		inline std::vector<std::string>					get_comment_block(void) const			{ return _comment_block; }
		inline bool										get_is_static(void) const				{ return _is_static; }
		inline bool										get_is_returned_value_const(void) const	{ return _is_returned_value_const; }
		inline std::string								get_returned_value_type(void) const		{ return _returned_value_type; }
		inline std::string								get_name(void) const					{ return _name; }
		inline std::vector<Function_Parameter>			get_parameters(void) const				{ return _parameters; }
		inline std::vector<std::string>					get_function_content(void) const		{ return _function_content; }
};

#endif // __FUNCTION_H__
