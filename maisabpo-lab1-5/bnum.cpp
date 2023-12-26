#include "bnum.hpp"

// создает длинное целое число со значением 0
bnum::bnum() {
    this->_is_negative = false;
}
 
// создает длинное целое число из C++-строки
bnum::bnum(std::string str) {
    if (str.length() == 0) {
        this->_is_negative = false;
    }
    else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->_is_negative = true;
        }
        else {
            this->_is_negative = false;
        }
 
        for (long long i = str.length(); i > 0; i -= 9) {
            if (i < 9)
                this->_digits.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->_digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }
 
        this->_remove_leading_zeros();
    }
}
 
// удаляет ведущие нули
void bnum::_remove_leading_zeros() {
    while (this->_digits.size() > 1 && this->_digits.back() == 0) {
        this->_digits.pop_back();
    }
 
    if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}
 
// печатает число в поток вывода
std::ostream& operator <<(std::ostream& os, const bnum& bi) {
    if (bi._digits.empty()) os << 0;
    else {
        if (bi._is_negative) os << '-';
        os << bi._digits.back();
        char old_fill = os.fill('0');
        for (long long i = static_cast<long long>(bi._digits.size()) - 2; i >= 0; --i) os << std::setw(9) << bi._digits[i];
        os.fill(old_fill);
    }
 
    return os;
}
 
// сравнивает два числа на равенство
bool operator ==(const bnum& left, const bnum& right) {
    if (left._is_negative != right._is_negative) return false;
    if (left._digits.empty()) {
        if (right._digits.empty() || (right._digits.size() == 1 && right._digits[0] == 0)) return true;
        else return false;
    }
    
    if (right._digits.empty()) {
        if (left._digits.size() == 1 && left._digits[0] == 0) return true;
        else return false;
    }
 
    if (left._digits.size() != right._digits.size()) return false;
    for (size_t i = 0; i < left._digits.size(); ++i) if (left._digits[i] != right._digits[i]) return false;
 
    return true;
}
 
// возвращает копию переданного числа
const bnum bnum::operator +() const {
    return bnum(*this);
}
 
// возвращает переданное число с другим знаком
const bnum bnum::operator -() const {
    bnum copy(*this);
    copy._is_negative = !copy._is_negative;
    return copy;
}
 
// проверяет, является ли левый операнд меньше правого
bool operator <(const bnum& left, const bnum& right) {
    if (left == right) return false;
    if (left._is_negative) {
        if (right._is_negative) return ((-right) < (-left));
        else return true;
    }
    else if (right._is_negative) return false;
    else {
        if (left._digits.size() != right._digits.size()) {
            return left._digits.size() < right._digits.size();
        }
        else {
            for (long long i = left._digits.size() - 1; i >= 0; --i) {
                if (left._digits[i] != right._digits[i]) return left._digits[i] < right._digits[i];
            }
            
            return false;
        }
    }
}
 
// сравнивает два числа на неравенство
bool operator !=(const bnum& left, const bnum& right) {
    return !(left == right);
}
 
// проверяет, является ли левый операнд меньше либо равен правого
bool operator <=(const bnum& left, const bnum& right) {
    return (left < right || left == right);
}
 
// проверяет, является ли левый операнд больше правого
bool operator >(const bnum& left, const bnum& right) {
    return !(left <= right);
}
 
// проверяет, является ли левый операнд больше либо равен правого
bool operator >=(const bnum& left, const bnum& right) {
    return !(left < right);
}
 
// складывает два числа
const bnum operator +(bnum left, const bnum& right) {
    if (left._is_negative) {
        if (right._is_negative) return -(-left + (-right));
        else return right - (-left);
    }
    else if (right._is_negative) return left - (-right);
    int carry = 0;
    for (size_t i = 0; i < std::max(left._digits.size(), right._digits.size()) || carry != 0; ++i) {
        if (i == left._digits.size()) left._digits.push_back(0);
        left._digits[i] += carry + (i < right._digits.size() ? right._digits[i] : 0);
        carry = left._digits[i] >= bnum::BASE;
        if (carry != 0) left._digits[i] -= bnum::BASE;
    }
 
    return left;
}
 
// прибавляет к текущему числу новое
bnum& bnum::operator +=(const bnum& value) {
    return *this = (*this + value);
}
 
// префиксный инкремент
const bnum bnum::operator++() {
    return (*this += 1);
}
 
// преобразует число к строке
bnum::operator std::string() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}
 
// преобразует signed char к bnum
bnum::bnum(signed char c) {
    if (c < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(c));
}
 
// преобразует unsigned char к bnum
bnum::bnum(unsigned char c) {
    this->_is_negative = false;
    this->_digits.push_back(c);
}
 
// преобразует signed short к bnum
bnum::bnum(signed short s) {
    if (s < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(s));
}
 
// преобразует unsigned short к bnum
bnum::bnum(unsigned short s) {
    this->_is_negative = false;
    this->_digits.push_back(s);
}
 
// преобразует signed int к bnum
bnum::bnum(signed int i) {
    if (i < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(i) % bnum::BASE);
    i /= bnum::BASE;
    if (i != 0) this->_digits.push_back(std::abs(i));
}
 
// преобразует unsigned int к bnum
bnum::bnum(unsigned int i) {
    this->_digits.push_back(i % bnum::BASE);
    i /= bnum::BASE;
    if (i != 0) this->_digits.push_back(i);
}
 
// преобразует signed long к bnum
bnum::bnum(signed long l) {
    if (l < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(l) % bnum::BASE);
    l /= bnum::BASE;
    if (l != 0) this->_digits.push_back(std::abs(l));
}
 
// преобразует unsigned long к bnum
bnum::bnum(unsigned long l) {
    this->_digits.push_back(l % bnum::BASE);
    l /= bnum::BASE;
    if (l != 0) this->_digits.push_back(l);
}
 
// преобразует signed long long к bnum
bnum::bnum(signed long long l) {
    if (l < 0) { this->_is_negative = true; l = -l; }
    else this->_is_negative = false;
    do {
        this->_digits.push_back(l % bnum::BASE);
        l /= bnum::BASE;
    } while (l != 0);
}
 
// преобразует unsigned long long к bnum
bnum::bnum(unsigned long long l) {
    this->_is_negative = false;
    do {
        this->_digits.push_back(l % bnum::BASE);
        l /= bnum::BASE;
    } while (l != 0);
}
 
// постфиксный инкремент
const bnum bnum::operator ++(int) {
    *this += 1;
    return *this - 1;
}
 
// префиксный декремент
const bnum bnum::operator --() {
    return *this -= 1;
}
 
// постфиксный декремент
const bnum bnum::operator --(int) {
    *this -= 1;
    return *this + 1;
}
 
// вычитает два числа
const bnum operator -(bnum left, const bnum& right) {
    if (right._is_negative) return left + (-right);
    else if (left._is_negative) return -(-left + right);
    else if (left < right) return -(right - left);
    int carry = 0;
    for (size_t i = 0; i < right._digits.size() || carry != 0; ++i) {
        left._digits[i] -= carry + (i < right._digits.size() ? right._digits[i] : 0);
        carry = left._digits[i] < 0;
        if (carry != 0) left._digits[i] += bnum::BASE;
    }
 
    left._remove_leading_zeros();
    return left;
}
 
// вычитает из текущего числа новое
bnum& bnum::operator -=(const bnum& value) {
    return *this = (*this - value);
}
 
// перемножает два числа
const bnum operator *(const bnum& left, const bnum& right) {
    bnum result;
    result._digits.resize(left._digits.size() + right._digits.size());
    for (size_t i = 0; i < left._digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < right._digits.size() || carry != 0; ++j) {
            long long cur = result._digits[i + j] + 
                left._digits[i] * 1LL * (j < right._digits.size() ? right._digits[j] : 0) + carry;
            result._digits[i + j] = static_cast<int>(cur % bnum::BASE);
            carry = static_cast<int>(cur / bnum::BASE);
        }
    }
 
    result._is_negative = left._is_negative != right._is_negative;
    result._remove_leading_zeros();
    return result;
}
 
// домножает текущее число на указанное
bnum& bnum::operator *=(const bnum& value) {
    return *this = (*this * value);
}
 
// сдвигает все разряды на 1 вправо (домножает на BASE)
void bnum::_shift_right() {
    if (this->_digits.size() == 0) {
        this->_digits.push_back(0);
        return;
    }
    this->_digits.push_back(this->_digits[this->_digits.size() - 1]);
    for (size_t i = this->_digits.size() - 2; i > 0; --i) this->_digits[i] = this->_digits[i - 1];
    this->_digits[0] = 0;
}
 
// делит два числа
const bnum operator /(const bnum& left, const bnum& right) {
    if (right == 0) throw bnum::divide_by_zero();
    bnum b = right;
    b._is_negative = false;
    bnum result, current;
    result._digits.resize(left._digits.size());
    for (long long i = static_cast<long long>(left._digits.size()) - 1; i >= 0; --i) {
        current._shift_right();
        current._digits[0] = left._digits[i];
        current._remove_leading_zeros();
        int x = 0, l = 0, r = bnum::BASE;
        while (l <= r) {
            int m = (l + r) / 2;
            bnum t = b * m;
            if (t <= current) {
                x = m;
                l = m + 1;
            }
            else r = m - 1;
        }
 
        result._digits[i] = x;
        current = current - b * x;
    }
 
    result._is_negative = left._is_negative != right._is_negative;
    result._remove_leading_zeros();
    return result;
}
 
// делит текущее число на указанное
bnum& bnum::operator /=(const bnum& value) {
    return *this = (*this / value);
}
 
// возвращает остаток от деления двух чисел
const bnum operator %(const bnum& left, const bnum& right) {
    bnum result = left - (left / right) * right;
    if (result._is_negative) result += right;
    return result;
}
 
// присваивает текущему числу остаток от деления на другое число
bnum& bnum::operator %=(const bnum& value) {
    return *this = (*this % value);
}
 
// проверяет, является ли текущее число нечетным
bool bnum::odd() const {
    if (this->_digits.size() == 0) return false;
    return this->_digits[0] & 1;
}
 
// проверяет, является ли текущее число четным
bool bnum::even() const {
    return !this->odd();
}
 
// возводит текущее число в указанную степень
const bnum bnum::pow(bnum n) const {
    bnum a(*this), result(1);
    while (n != 0) {
        if (n.odd()) result *= a;
        a *= a;
        n /= 2;
    }
 
    return result;
}