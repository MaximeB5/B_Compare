// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "File_Reader.h"

#include <stdexcept>

// ------------------------------------------------
// Debug & Tests
// ------------------------------------------------

// Uncomment the following define if you need it for some tests
//#define DEBUG

#ifdef DEBUG
	#include "Function_Parameter.h"
	#include "Function.h"
	#include <iostream>
#endif // DEBUG

// ------------------------------------------------
// Main
// ------------------------------------------------

int main()
{

	File_Reader reader_1{"test.c"};
	File_Reader reader_2{"test.c"};

	if (!reader_1.is_ready_to_read()) { throw std::runtime_error("The file name or its path n°1 is incorrect."); }
	if (!reader_2.is_ready_to_read()) { throw std::runtime_error("The file name or its path n°2 is incorrect."); }

	reader_1.read_file();
	reader_2.read_file();

	return EXIT_SUCCESS;
}
