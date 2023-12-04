#include "binary_output.hpp"

namespace maisabpo
{
	std::string bout::readFromFile(const std::string& fileName) {
		std::ifstream file(fileName, std::ios::binary);
		if (!file.is_open()) {
			throw std::runtime_error("Error opening file: " + fileName);
		}

		fileContents.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		file.close();

		return std::string(fileContents.begin(), fileContents.end());
	}

	void bout::setContent(const std::string& str) {
		if (!str.empty()) {
			fileContents.assign(str.begin(), str.end());
		}
	}


	void bout::hex8(uint32_t consoleItemsPerLine) {
		if (fileContents.empty()) return;
		printHeader("HEX 8", 3, consoleItemsPerLine);

		std::cout << std::hex << std::uppercase << std::right;
		for (size_t i = 0; i < fileContents.size(); ++i) {
			std::cout << std::setw(2) << static_cast<unsigned int>(fileContents[i]) << ' ';
			if ((i + 1) % consoleItemsPerLine == 0) std::cout << std::endl;
		}

		std::cout << std::nouppercase << std::right << std::setfill(' ') << std::endl;
	}


	void bout::hex16(uint32_t consoleItemsPerLine) {
		if (fileContents.empty()) return;
		printHeader("HEX 16", 5, consoleItemsPerLine);

		std::cout << std::hex << std::uppercase << std::right;
		for (size_t i = 0; i < fileContents.size(); i += 2) {
			unsigned int value = (i + 1 < fileContents.size()) ? ((fileContents[i] << 8) | fileContents[i + 1]) : fileContents[i];
			std::cout << std::setw(4) << value << ' ';
			if ((i + 2) % (consoleItemsPerLine * 2) == 0) std::cout << std::endl;
		}

		std::cout << std::nouppercase << std::right << std::setfill(' ') << std::endl;
	}



	void bout::hex32(uint32_t consoleItemsPerLine) {
		if (fileContents.empty()) return;
		printHeader("HEX 32", 9, consoleItemsPerLine);

		std::cout << std::hex << std::uppercase << std::right;
		for (size_t i = 0; i < fileContents.size(); i += 4) {
			uint32_t value = 0;
			for (size_t j = 0; j < 4; ++j) {
				value |= (i + j < fileContents.size()) ? (fileContents[i + j] << (24 - j * 8)) : 0;
			}
			std::cout << std::setw(8) << value << ' ';
			if ((i + 4) % (consoleItemsPerLine * 4) == 0) std::cout << std::endl;
		}

		std::cout << std::nouppercase << std::right << std::setfill(' ') << std::endl;
	}


	void bout::dec8(uint32_t consoleItemsPerLine) {
		if (fileContents.empty()) return;
		printHeader("DEC 8", 4, consoleItemsPerLine);

		std::cout << std::dec << std::right << std::setfill('0');
		for (size_t i = 0; i < fileContents.size(); ++i) {
			std::cout << std::setw(3) << static_cast<unsigned int>(fileContents[i]) % 256 << ' ';
			if ((i + 1) % consoleItemsPerLine == 0) std::cout << std::endl;
		}

		std::cout << std::nouppercase << std::right << std::setfill(' ') << std::endl;
	}


	void bout::dec16(uint32_t consoleItemsPerLine) {
		if (fileContents.empty()) return;
		printHeader("DEC 16", 6, consoleItemsPerLine);

		std::cout << std::dec << std::right << std::setfill('0');
		for (size_t i = 0; i < fileContents.size(); i += 2) {
			unsigned int value = 0;
			for (size_t j = 0; j < 2; ++j) {
				value |= (i + j < fileContents.size()) ? (fileContents[i + j] << ((1 - j) * 8)) : 0;
			}
			std::cout << std::setw(5) << value << ' ';
			if ((i + 2) % (consoleItemsPerLine * 2) == 0) std::cout << std::endl;
		}

		std::cout << std::nouppercase << std::right << std::setfill(' ') << std::endl;
	}



	void bout::printHeader(const std::string& message, uint32_t itemsLength, uint32_t consoleItemsPerLine) {
		// Ceil in first setw is for odd number of items to be displayed correctly, if item count is even it won't affect the output
		// If second setfill not set to space other the output with setw will be messed up with equal signs
		std::cout << std::setfill('=') << std::setw(static_cast<uint64_t>(std::ceil(itemsLength * consoleItemsPerLine / 2.0))) << message
			<< std::setw(static_cast<uint64_t>(std::floor(itemsLength * consoleItemsPerLine / 2.0))) << ' ' << std::setfill(' ') << std::endl;
	}

}