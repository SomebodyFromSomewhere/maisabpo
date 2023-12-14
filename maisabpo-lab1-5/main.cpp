#include <iostream>
#include <string>
#include "bnum.hpp"

int main()
{
    std::cout << "Test" << std::endl;

    bnum x1 = static_cast<int64_t>(-1);
    // bnum x2 = static_cast<uint64_t>(1);
    // bnum x3 = static_cast<int32_t>(-1);
    // bnum x4 = static_cast<uint32_t>(1);
    // bnum x5 = (int)-1;
    // bnum x6 = (unsigned int)1;
    // bnum x7;
    // bnum x8 = x7;
    // bnum x9 = x6;

    bnum x = "9999999999999999999999999999999999999998";
    bnum y = "2";

    // std::cout << "Sum: " << (x + y) << std::endl;

    return 0;
}