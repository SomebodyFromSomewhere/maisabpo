#include "bin_ops.h"

namespace maisabpo
{
	uint64_t bin_ops::xor64(const uint64_t& a, const uint64_t& b)
	{
		return a ^ b;
	}

	uint64_t bin_ops::and64(const uint64_t& a, const uint64_t& b)
	{
		return a & b;
	}

	uint64_t bin_ops::or64(const uint64_t& a, const uint64_t& b)
	{
		return a | b;
	}

	uint64_t bin_ops::set1(const uint64_t& a, const uint64_t& pos)
	{
		return a | ((uint64_t)1 << pos);
	}

	uint64_t bin_ops::set0(const uint64_t& a, const uint64_t& pos)
	{
		return a & ~((uint64_t)1 << pos);
	}

	uint64_t bin_ops::shl64(const uint64_t& a, const uint64_t& pos)
	{
		return a << pos;
	}

	uint64_t bin_ops::shr64(const uint64_t& a, const uint64_t& pos)
	{
		return a >> pos;
	}

	uint64_t bin_ops::rol64(const uint64_t& a, const int64_t& pos)
	{
		return static_cast<uint64_t>(a << pos) | static_cast<uint64_t>(a >> ((uint64_t)64 - pos));
	}

	uint64_t bin_ops::ror64(const uint64_t& a, const int64_t& pos)
	{
		std::int64_t s = pos >= 0 ? pos % 64 : -((-pos) % 64);
		return (a >> s) | (a << (64 - s));
	}

	bool bin_ops::checkSequence(const std::vector<uint64_t>& vector)
	{
		std::vector<uint64_t> vec_copy;

		for (uint64_t i = 0; i < vector.size(); i++)
		{
			if (vector[i] >= 64)
				return false;
		}

		return true;
	}

	uint64_t bin_ops::mix10(const uint64_t& pos, const uint64_t& a)
	{
		std::string positions = std::to_string(pos);
		if (positions.size() > 10) throw std::invalid_argument("Positions given more than can resolve.");
		uint64_t result = 0;
		uint64_t mask = 0;
		uint64_t bits = positions.length() - 1;

		for (int i = 0; i < positions.size(); i++)
		{
			mask = static_cast<uint64_t>(1) << i;
			if ((a & mask) == 0)
				continue;
			
			uint64_t pos = std::stoi(std::string(1, positions.at(positions.size() - 1 - i)));
			uint64_t new_pos = bits - pos;

			result |= static_cast<uint64_t>(1) << new_pos;
		}

		return result;
	}

	uint64_t bin_ops::mix64(const std::vector<uint64_t>& pos, const uint64_t& a)
	{
		std::vector<uint64_t> pos_copy = pos;
		std::reverse(pos_copy.begin(), pos_copy.end());
		if (pos_copy.size() > 64) throw std::invalid_argument("Positions given more than can resolve.");
		if (!bin_ops::checkSequence(pos_copy))
			throw std::invalid_argument("Positions given are contains positions out of bound.");
		uint64_t result = 0;
		uint64_t mask = 0;
		uint64_t maxVecPos = pos_copy.size() - 1;
		for (int i = 0; i < pos_copy.size(); i++)
		{
			mask = static_cast<uint64_t>(1) << i;
			if ((a & mask) == 0)
				continue;

			uint64_t position = pos_copy[(maxVecPos - i)];
			result |= static_cast<uint64_t>(1) << position;
		}

		return result;
	}

	void bin_ops::printResult(std::string title, uint64_t lop, uint64_t rop, std::string op, uint64_t result, uint64_t expected)
	{
		const char fillChar = '#';
		const std::string lineStart = "# ";
		const std::string lineEnd = " #";
		const std::string resultMessage = "Result: " + std::to_string(result);
		const std::string expectedMessage = "Expected: " + std::to_string(expected);
		const std::string opeartionString = " " + op + " ";
		const std::string equalString = " = ";
		const std::string example = std::to_string(lop) + opeartionString + std::to_string(rop) + equalString + std::to_string(result);
		const std::string exampleInBinary = std::bitset<BIN_BITS_PER_NUMBER>(lop).to_string() + opeartionString + std::bitset<BIN_BITS_PER_NUMBER>(rop).to_string()
			+ equalString + std::bitset<BIN_BITS_PER_NUMBER>(result).to_string();


		uint64_t exampleLineLenght = opeartionString.length() + equalString.length() + example.length();
		uint64_t exampleInBinaryLineLenght = opeartionString.length() + equalString.length() + exampleInBinary.length();
		uint64_t resultLineLenght = lineStart.length() + resultMessage.length() + expectedMessage.length() + lineEnd.length() + 1; // 1 stands for space in midle
		uint64_t lineLenght = std::max(std::max(exampleLineLenght, exampleInBinaryLineLenght), resultLineLenght);
		uint64_t sidesOffset = static_cast<uint64_t>(std::ceil(lineLenght / 2.0));
		uint64_t titleHalf = static_cast<uint64_t>(std::floor(title.length() / 2.0));
		uint64_t exampleHalf = static_cast<uint64_t>(std::ceil(example.length() / 2.0));
		uint64_t exampleInBinaryHalf = static_cast<uint64_t>(std::ceil(exampleInBinary.length() / 2.0));

		// Title
		std::cout << std::setfill(fillChar);	// Enable fill character
		std::cout << std::setw(sidesOffset + titleHalf) << title << std::setw(sidesOffset - titleHalf) << '#' << std::endl;
		std::cout << std::setfill(' ');			// Disable fill character

		// Example
		std::cout << lineStart << std::setw(sidesOffset + exampleHalf - lineStart.length()) << example << std::setw(sidesOffset - exampleHalf) << lineEnd << std::endl;
		std::cout << lineStart << std::setw(sidesOffset + exampleInBinaryHalf - lineStart.length())
			<< exampleInBinary << std::setw(sidesOffset - exampleInBinaryHalf) << lineEnd << std::endl;


		// Separator
		std::cout << std::setfill(fillChar);	// Enable fill character
		std::cout << std::setw(sidesOffset * 2) << '#' << std::endl;
		std::cout << std::setfill(' ');			// Disable fill character

		// Result
		std::cout << lineStart << std::left << std::setw(sidesOffset - lineStart.length() + COLOR_GREEN_BG.length()) << ((result == expected) ? COLOR_GREEN_BG : COLOR_RED_BG) + resultMessage;
		std::cout << std::right << std::setw(sidesOffset - lineEnd.length() + COLOR_CLEAR.length()) << expectedMessage + COLOR_CLEAR << lineEnd << std::endl;

		// Separator
		std::cout << std::setfill(fillChar);	// Enable fill character
		std::cout << std::setw(sidesOffset * 2) << '#' << std::endl;
		std::cout << std::setfill(' ');			// Disable fill character
	}
}
