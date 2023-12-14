#include "bnum.hpp"
#include <string>
#include <algorithm>

bnum::bnum()
{
}

bnum::bnum(int64_t x)
{
    _init(std::move(std::to_string(x)));
}

bnum::bnum(int64_t& x)
{
    _init(std::move(std::to_string(x)));
}

bnum::bnum(std::string &x)
{
    _init(std::move(x));
}

bnum::bnum(const char *x)
{
    _init(std::string(x));
}

bnum::~bnum()
{
}

void bnum::_init(std::string &&x)
{
    if (x.empty())
    {
        sign = true;
        chunks.push_back(0);
        return;
    }
    const size_t CHUNKSIZE = 9;
    size_t index = 0;
    size_t i = x.length() - 1;
    std::string chunk = "";
    for (; i > 0;)
    {
        chunk += x[i--];
        index++;
        if (index == CHUNKSIZE)
        {
            index = 0;
            std::reverse(chunk.begin(), chunk.end());
            chunks.push_back(std::stoi(chunk));
            chunk.clear();
        }
    }

    if (x.at(0) == '-')
    {
        sign = false; // minus
    }
    else
    {
        chunk += x.at(0);
    }

    if (index != 0)
    {
        std::reverse(chunk.begin(), chunk.end());
        chunks.push_back(std::stoi(chunk));
    }
}

std::ostream &operator<<(std::ostream &strm, const bnum &x)
{
    strm << ((x.sign) ? "" : "-");
    for (int i = x.chunks.size() - 1; i >= 0; i--)
    {
        strm << x.chunks[i];
    }
    
    return strm;
}
