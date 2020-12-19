#ifndef HASSAN_COMPARE_FILES_H
#define HASSAN_COMPARE_FILES_H
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

namespace hassan {
	bool CompareFiles(const std::string& file1, const std::string& file2);
} 
#endif
