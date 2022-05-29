#ifndef __FILE_READER_H__
#define __FILE_READER_H__

// ------------------------------------------------
// Includes
// ------------------------------------------------

#include "Data.h"
#include "Include.h"
#include "Define.h"

#include <string>
#include <fstream>
#include <vector>
#include <memory>

// ------------------------------------------------
// Class Definition
// ------------------------------------------------

class File_Reader
{
	protected:
		std::string _file_name;
		std::string _file_extension;
		std::ifstream _file_stream;

		std::vector<Include> _includes;					// Only includes
		std::vector<Define> _defines;					// Only defines
		std::vector<std::unique_ptr<Data> > _file_data; // All data left

		void _read_file(void) noexcept;
		Include _get_include_from_str(const std::string & line) const noexcept;
		Define _get_define_from_str(const std::string & line) const noexcept;
		bool _is_a_function(const std::string & line) const noexcept;

	public:
		File_Reader(const std::string & file_name);
		~File_Reader();

		void read_file(void) noexcept;

		// ------------------------------------------------
		// Inline Getters
		// ------------------------------------------------
		inline auto	is_ready_to_read(void)		const noexcept	{ return _file_stream.is_open() && _file_stream.good(); }
		inline auto	get_file_name(void)			const noexcept	{ return _file_name; }
		inline auto	get_file_extension(void)	const noexcept	{ return _file_extension; }

		inline auto	get_includes(void)			const noexcept	{ return _includes; }
		inline auto	get_defines(void)			const noexcept	{ return _defines; }
};

#endif // __FILE_READER_H__
