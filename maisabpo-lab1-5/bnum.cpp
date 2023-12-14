#include "bnum.hpp"
#include <string>
#include <algorithm>

bnum::bnum()
{
}

bnum::bnum(int64_t x)
{
    bnum(std::to_string(x));
}

bnum::bnum(std::string x)
{
    const size_t CHUNKSIZE = 9;
    size_t index = 0;
    size_t i = x.length();
    std::string chunk = "";
    for (; i > 1; i--)
    {
        chunk += x[i];
        index++;
        if (index == CHUNKSIZE)
        {
            index = 0;
            std::reverse(chunk.begin(), chunk.end());
            chunks.push_back(std::stoi(chunk));
        }
    }

    if (x.at(0) == '-')
    {
        sign = false; // minus
    }
    else
    {
        chunk += x.at(0);
        index++;
    }

    if (index != 0)
    {
        std::reverse(chunk.begin(), chunk.end());
        chunks.push_back(std::stoi(chunk));
    }
}

bnum::bnum(const char *x)
{
    bnum(std::string(x));
}

bnum::~bnum()
{
}

std::ostream &operator<<(std::ostream &strm, const bnum &x)
{
    strm << ((x.sign) ? "-" : "") << x.chunks[0];
    return strm;
}
