#ifndef __HELPER_FUNCTIONS_H__
#define __HELPER_FUNCTIONS_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "E_C_Keywords.h"

#include <string>

// ------------------------------------------------
// Function Definitions
// ------------------------------------------------

std::string E_C_STATEMENT_to_Str(const E_C_STATEMENT & type);
E_C_STATEMENT Str_to_E_C_STATEMENT(const std::string & type);

std::string E_C_TYPE_to_Str(const E_C_TYPE & type);
E_C_TYPE Str_to_E_C_TYPE(const std::string & type);

std::string E_C_QUALIFIER_to_Str(const E_C_QUALIFIER & qualifier);
E_C_QUALIFIER Str_to_E_C_QUALIFIER(const std::string & qualifier);

#endif // __HELPER_FUNCTIONS_H__
