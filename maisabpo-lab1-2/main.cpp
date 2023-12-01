#include <iostream>
#include <limits>
#include "bin_ops.h"


using namespace maisabpo;

int main(int argc, char* argv[])
{
	uint64_t a = 21;
	uint64_t b = 4;
	uint64_t result = 0;

	result = bin_ops::xor64(a, b);
	bin_ops::printResult("XOR", a, b, "^", result, 17);

	result = bin_ops::and64(a, b);
	bin_ops::printResult("AND", a, b, "&", result, 4);

	result = bin_ops::or64(a, b);
	bin_ops::printResult("OR", a, b, "|", result, 21);

	result = bin_ops::set1(a, b);
	bin_ops::printResult("SET1", a, b, "SET1", result, 21);

	result = bin_ops::set0(a, b);
	bin_ops::printResult("SET0", a, b, "SET0", result, 5);

	result = bin_ops::shl64(a, b);
	bin_ops::printResult("SHL", a, b, "<<", result, 336);

	result = bin_ops::shr64(a, b);
	bin_ops::printResult("SHR", a, b, ">>", result, 1);

	a = 10465;
	b = 60;
	result = bin_ops::rol64(a, b);
	bin_ops::printResult("ROL", a, b, "ROL", result, 1152921504606847630);

	a = 2;
	b = 2;
	result = bin_ops::ror64(a, b);
	bin_ops::printResult("ROR", a, b, "ROR", result, -std::numeric_limits<int64_t>::min());
	// Even if my type is unsigned it interprets first bit as sign bit

	a = 76543210;
	b = 11;

	result = bin_ops::mix10(a, b);
	bin_ops::printResult("MIX10", a, b, "MIX10", result, 208);

	std::vector<uint64_t> v = { 7, 6, 5, 4,3,2,1,0 };
	b = 11;

	result = bin_ops::mix64(v, b);
	bin_ops::printResult("MIX64", 1707, b, "MIX64", result, 208); // 1707 Just a placeholder, doesn't do anything

	return 0;
}
