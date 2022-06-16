// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "File_Reader.h"

#include <stdexcept>

// ------------------------------------------------
// Debug & Tests
// ------------------------------------------------

// Uncomment the following define if you need it for some tests
#define DEBUG

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
	File_Reader reader_2{"test.h"};

	// Do not check the stream status for debug and tests
	#ifndef DEBUG
		if (!reader_1.is_ready_to_read()) { throw std::runtime_error("The file name or its path n°1 is incorrect."); }
		if (!reader_2.is_ready_to_read()) { throw std::runtime_error("The file name or its path n°2 is incorrect."); }
	#endif // !DEBUG

	reader_1.read_file();
	reader_2.read_file();

	// TODO
	// Create Analyzer class that'll receive the File_Reader objects and re-order data based on what are the common stuff
	// It should create vectors for all what's common, ordered on alphabetic names
	// It should create vectors of what's unique to each file

	return EXIT_SUCCESS;
}
