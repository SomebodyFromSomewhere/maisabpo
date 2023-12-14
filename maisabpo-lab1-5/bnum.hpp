#pragma once
#include <iostream>
#include <stdint.h>
#include <limits>
#include <string>
#include <vector>

class bnum
{
public:
    bnum();
    bnum(int64_t x);
    bnum(int64_t& x);
    bnum(std::string& x);
    bnum(const char *x);
    bnum(const bnum &src);
    bnum(bnum &&src) noexcept;
    ~bnum();

    // bnum &operator=(const bnum &src);
    // bnum &operator=(bnum &&src) noexcept;

    friend bnum operator+(const bnum &x, const bnum &y);
    friend bnum operator-(const bnum &x, const bnum &y);
    friend bnum operator*(const bnum &x, const bnum &y);
    friend bnum operator/(const bnum &x, const bnum &y);
    friend std::ostream &operator<<(std::ostream &strm, const bnum &x);
    friend std::istream &operator>>(std::istream &strm, const bnum &x);

private:
    bool sign = true; // plus
    std::vector<int32_t> chunks = {}; // TODO: Check if array version will be faster
    const uint32_t MODULO = 1000000000;
    void _init(std::string &&x);
};
