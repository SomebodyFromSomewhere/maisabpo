#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <bitset>
#include <iomanip>

namespace maisabpo {
	static const std::string COLOR_GREEN_BG = "\033[0;42m";
	static const std::string COLOR_RED_BG = "\033[0;41m";
	static const std::string COLOR_CLEAR = "\033[0m";
	class bin_ops
	{
	public:
		static uint64_t xor64(const uint64_t& a, const uint64_t& b);
		static uint64_t and64(const uint64_t& a, const uint64_t& b);
		static uint64_t or64(const uint64_t& a, const uint64_t& b);
		static uint64_t set1(const uint64_t& a, const uint64_t& pos);
		static uint64_t set0(const uint64_t& a, const uint64_t& pos);
		static uint64_t shl64(const uint64_t& a, const uint64_t& pos);
		static uint64_t shr64(const uint64_t& a, const uint64_t& pos);
		static uint64_t rol64(const uint64_t& a, const int64_t& pos);
		static uint64_t ror64(const uint64_t& a, const int64_t& pos);
		static uint64_t mix64(const uint64_t& a, const uint64_t& pos);
		static void printResult(std::string title, uint64_t lop, uint64_t rop, std::string op, uint64_t result, uint64_t expected);
	};
}
