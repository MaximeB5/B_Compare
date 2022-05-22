// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Function_Parameter.h"
#include "Helper_Functions.h"

#include <exception>

// ------------------------------------------------
// Class Implementation
// ------------------------------------------------

/// <summary>
/// Constructor
/// </summary>
/// <param name="const std::string & content"></param>
Function_Parameter::Function_Parameter(const std::string & content)
	: Data(content)
{
    std::vector<std::string> words;

    // ------------------------------------------------
    // Parse the string 'content' to get words
    {
        std::string s;

        for (auto & c : content)
        {
            if (c == ' ') {
                words.push_back(s);
                s.clear();
            }
            else {
                s += c;
            }
        }
    }
    // ------------------------------------------------
    // Identify the words : are they type, qualifier or is it the name
    {
        for (auto const & str : words)
        {
            E_C_TYPE t      = Str_to_E_C_TYPE(str);
            E_C_QUALIFIER q = Str_to_E_C_QUALIFIER(str);

            if (t != E_C_TYPE::NONE)            { _content.push_back(std::make_unique<C_Type>(t)); }
            else if (q != E_C_QUALIFIER::NONE)  { _content.push_back(std::make_unique<C_Qualifier>(q)); }
            else if (_parameter_name.empty())   {
                _parameter_name = str;
                _content.push_back(std::make_unique<Data>(str));
            }
            else {
                throw std::exception(
                    std::string("Function_Parameter - Constructor : Words identification failed. Initial string is '" + content + "'").c_str()
                );
            }
        }
    }
}

// ------------------------------------------------
// ------------------------------------------------

std::string Function_Parameter::to_Str(void) const
{
	return _data_content;
}

// ------------------------------------------------
// ------------------------------------------------
