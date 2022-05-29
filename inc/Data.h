#ifndef __DATA_H__
#define __DATA_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include <string>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class Data
{
	protected:
		std::string _data_content;
	
	public:
		Data(std::string content);
		Data(const Data & data);
		virtual ~Data() = default;

		std::string data_to_Str(void) const noexcept;
		virtual std::string to_Str(void) const noexcept;
};

#endif // __DATA_H__
