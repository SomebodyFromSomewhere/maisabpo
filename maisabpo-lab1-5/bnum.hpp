#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <iomanip>
#include <sstream>

class bnum
{
public:
    // класс-исключение, бросаемое при делении на ноль
    class divide_by_zero : public std::exception
    {
    };

    bnum();
    bnum(std::string);
    bnum(signed char);
    bnum(unsigned char);
    bnum(signed short);
    bnum(unsigned short);
    bnum(signed int);
    bnum(unsigned int);
    bnum(signed long);
    bnum(unsigned long);
    bnum(signed long long);
    bnum(unsigned long long);

    friend std::ostream &operator<<(std::ostream &, const bnum &);
    operator std::string() const;
    const bnum operator+() const;
    const bnum operator-() const;
    const bnum operator++();
    const bnum operator++(int);
    const bnum operator--();
    const bnum operator--(int);
    friend bool operator==(const bnum &, const bnum &);
    friend bool operator<(const bnum &, const bnum &);
    friend bool operator!=(const bnum &, const bnum &);
    friend bool operator<=(const bnum &, const bnum &);
    friend bool operator>(const bnum &, const bnum &);
    friend bool operator>=(const bnum &, const bnum &);
    friend const bnum operator+(bnum, const bnum &);
    bnum &operator+=(const bnum &);
    friend const bnum operator-(bnum, const bnum &);
    bnum &operator-=(const bnum &);
    friend const bnum operator*(const bnum &, const bnum &);
    bnum &operator*=(const bnum &);
    friend const bnum operator/(const bnum &, const bnum &);
    bnum &operator/=(const bnum &);
    friend const bnum operator%(const bnum &, const bnum &);
    bnum &operator%=(const bnum &);

    bool odd() const;
    bool even() const;
    const bnum pow(bnum) const;

private:
    // основание системы счисления (1 000 000 000)
    static const int BASE = 1000000000;

    // внутреннее хранилище числа
    std::vector<int> _digits;

    // знак числа
    bool _is_negative;

    void _remove_leading_zeros();
    void _shift_right();
};