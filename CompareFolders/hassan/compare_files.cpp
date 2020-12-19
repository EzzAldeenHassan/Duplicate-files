#include "compare_files.h"

namespace hassan {
	bool CompareFiles(const std::string& file1, const std::string& file2)
	{
		std::ifstream folder1(file1, std::ios::binary);
		std::ifstream folder2(file2, std::ios::binary);
        std::ifstream::pos_type size1, size2;

        size1 = folder1.seekg(0, std::ifstream::end).tellg();
		folder1.seekg(0, std::ifstream::beg);

		size2 = folder2.seekg(0, std::ifstream::end).tellg();
		folder2.seekg(0, std::ifstream::beg);

        if (size1 != size2)
		{
			folder1.close();
			folder2.close();
			return false;
		}

        const size_t buffer_size = 4096;
        size_t remaining = size1;

        while (remaining)
		{
            char buffer1[buffer_size], buffer2[buffer_size];
            size_t size = remaining;

			folder1.read(buffer1, size);
			folder2.read(buffer2, size);

            if (0 != std::memcmp(buffer1, buffer2, size))
			{
                folder1.close();
                folder2.close();
				return false;
			}
            remaining -= size;
        }
		folder1.close();
		folder2.close();
		return true;
	}
}
