#pragma once

#include <vector>

namespace pnums
{
    #define LOOP_MAX_ITER 1000000
    class pnum
    {
    public:
        static void printEratosthenesSieve(const uint64_t &n, const uint64_t &elementsPerLine = 10);
        static bool isPrimary(const uint64_t &n);
        static void init();
    private:
        static std::vector<uint64_t> primaryNumbers;
        static bool initialized;
        static void makeSOE(const uint64_t &n, const bool &isUpperBoundary = false);
    };
} // namespace pnums
