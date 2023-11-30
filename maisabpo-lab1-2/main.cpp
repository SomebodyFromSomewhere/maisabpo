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
	// Dont fucking know why it is interpreted as signed, it takes -(2^64) and just removes sign. why last bit is counted as sign bit in unsigned type?

	return 0;
}
