#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>

namespace maisabpo {
	class bout
	{
	public:
		/**
		 * Default read from file, also sets private class member fileContents.
		 * 
		 * \param fileName - Path to file
		 * \return String of file contents
		 */
		std::string readFromFile(const std::string& fileName);

		/**
		 * Sets private class member fileContents, if nothing was passed does nothing.
		 * 
		 * \param string - String to set class member
		 */
		void setContent(const std::string& string);
		/**
		 * Prints contents of class member in hex8.
		 */
		void hex8(uint32_t consoleItemsPerLine = 30);
		/**
		 * Prints contents of class member in hex16.
		 */
		void hex16(uint32_t consoleItemsPerLine = 20);
		/**
		 * Prints contents of class member in hex32.
		 */
		void hex32(uint32_t consoleItemsPerLine = 10);
		/**
		 * Prints contents of class member in hex8.
		 */
		void dec8(uint32_t consoleItemsPerLine = 20);
		/**
		 * Prints contents of class member in hex16.
		 */
		void dec16(uint32_t consoleItemsPerLine = 10);
	private:
		std::vector<unsigned char> fileContents;

		void printHeader(const std::string& message, uint32_t itemsLength, uint32_t consoleItemsPerLine = 10);
	};
}