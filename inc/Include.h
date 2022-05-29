#ifndef __INCLUDE_H__
#define __INCLUDE_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Include : public Data
{
	protected:
		std::string _content;
		bool _is_user_defined; // true for includes of the form #include "my_file.h", false for includes such as #include <stdio.h>

	public:
		Include() = delete;
		Include(const std::string & content, const bool & is_user_defined);
		virtual ~Include() = default;

		inline std::string to_Str(void) const noexcept override { return _content; }
		inline auto get_is_user_defined(void) const noexcept { return _is_user_defined; }
};

#endif // __INCLUDE_H__