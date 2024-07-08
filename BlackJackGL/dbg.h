#ifndef DBG_H
#define DBG_H

#include "Globals.h"

namespace dbg {

	template <typename T>
	inline void print(T value) {
		std::ostringstream oss;
		oss << value;
		std::cout << oss.str() << std::endl;
	}

	template <typename T>
	inline void print(const std::string& str, T value) {
		std::ostringstream oss;
		oss << value;
		std::cout << "[" << str << "] " << oss.str() << std::endl;
	}
}
#endif