#ifndef __DEFINE_H__
#define __INCLUDE_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Define : public Data
{
protected:
	std::string _define_name;
	std::string _define_value;

public:
	Define() = delete;
	Define(const std::string & define_name, const std::string & define_value);
	virtual ~Define() = default;

	inline std::string to_Str(void) const noexcept override { return _define_name + " " + _define_value; }
};

#endif // __INCLUDE_H__