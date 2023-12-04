#include "utils.hpp"
#include <iomanip>

namespace CONSOLE_UTILS
{
    void printInsideFrame(const std::vector<std::pair<MarkdownEl ,std::string>> &messages, char fillChar = '#') noexcept
    {
        if (messages.size() <= 0)
            return;
        size_t maxMessageLenght = 0;

        for (auto msg : messages)
            maxMessageLenght = std::max(maxMessageLenght, msg.second.size());

        if (maxMessageLenght <= 0)
            return;
    
        size_t halfMessageLenght = std::ceil(maxMessageLenght / 2.0);
        for (auto msg : messages)
        {
            switch (msg.first)
            {
            case MarkdownEl::TITLE:
                std::setfill(fillChar);
                size_t titleHalf = msg.second.size();

                std::cout << std::setw(50);
                std::setfill(' ');
                break;
            case MarkdownEl::MESSAGE:
                /* code */
                break;
            case MarkdownEl::UNDEFINED:            
            default:
                break;
            }
        }
        
    }
}