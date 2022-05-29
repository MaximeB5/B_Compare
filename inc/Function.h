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

		inline std::string to_Str(void) const noexcept override { return _name; }

		// ------------------------------------------------
		// Inline Getters
		// ------------------------------------------------
		inline auto get_comment_block(void)				const noexcept	{ return _comment_block; }
		inline auto get_is_static(void)					const noexcept	{ return _is_static; }
		inline auto get_is_returned_value_const(void)	const noexcept	{ return _is_returned_value_const; }
		inline auto get_returned_value_type(void)		const noexcept	{ return _returned_value_type; }
		inline auto get_name(void)						const noexcept	{ return _name; }
		inline auto get_parameters(void)				const noexcept	{ return _parameters; }
		inline auto get_function_content(void)			const noexcept	{ return _function_content; }
};

#endif // __FUNCTION_H__
