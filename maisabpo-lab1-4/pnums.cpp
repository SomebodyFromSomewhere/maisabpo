#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <algorithm>
#include <vector>
#include "pnums.hpp"

std::vector<uint64_t> pnums::pnum::primaryNumbers = {};
bool pnums::pnum::initialized = false;
bool __isPrimary(uint64_t n);

void pnums::pnum::init()
{
    initialized = true;
    makeSOE(10);
}

void pnums::pnum::makeSOE(const uint64_t &n, const bool &isUpperBoundary)
{
    size_t loopLimit = 0;
    if (isUpperBoundary)
        loopLimit = n;
    else
        loopLimit = std::numeric_limits<uint64_t>::max();
    size_t i = 0;
    int64_t lastElementIndex = std::max(static_cast<int64_t>(primaryNumbers.size() - 1), static_cast<int64_t>(0));
    if (lastElementIndex > 0)
    {
        i = primaryNumbers.at(lastElementIndex) + 1;
    }

    for (; i < loopLimit; i++)
    {
        if (__isPrimary(i))
            primaryNumbers.push_back(i);
        if (primaryNumbers.size() == n)
            break;
    }
}

void pnums::pnum::printEratosthenesSieve(const uint64_t &n, const uint64_t &elementsPerLine)
{
    if (!initialized)
        makeSOE(10);
    int64_t loopLimit = std::min(primaryNumbers.size(), n);
    std::cout << "Printing " << loopLimit << " prime numbers of " << primaryNumbers.size() << " in total." << std::endl;
    for (size_t i = 0; i < loopLimit; i++)
    {
        std::cout << primaryNumbers.at(i) << " ";
        if (i % elementsPerLine == 0 && i > 0)
            std::cout << std::endl;
    }
}

bool pnums::pnum::isPrimary(const uint64_t &n)
{
    if (!initialized)
        makeSOE(10);
    if (n < 2)
        return false;

    for (size_t i = 0; i < LOOP_MAX_ITER; i++)
    {
        if (primaryNumbers.back() < n)
            makeSOE(primaryNumbers.size() + 9);
        else
            return std::binary_search(primaryNumbers.begin(), primaryNumbers.end(), n);
    }

    // if (primaryNumbers.back() < n)
    // {
    //     // std::cout << "[DBG][ISP] failed to find cached value, updating cache." << std::endl;
    //     makeSOE(primaryNumbers.size() + 9);
    //     return isPrimary(n); // TODO: Replace recursive call, with loop.
    //                          // NOTE: Recursion BAD! With big spans between previous number and target, too many recursion calls.
    //                          // Example: between 10 and 100000 could be 1065
    // }
    // else
    // {
    //     return std::binary_search(primaryNumbers.begin(), primaryNumbers.end(), n);
    // }

    return false;
}

bool __isPrimary(uint64_t n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}