#pragma once

#ifdef CONSOLE_UTILS_EXPORTS
#define CONSOLE_UTILS_API __declspec(dllexport)
#else
#define CONSOLE_UTILS_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

namespace mutl
{
    extern "C" CONSOLE_UTILS_API void printMessageInFrame(const std::string &message, char frameChar);
    extern "C" CONSOLE_UTILS_API void printMessagesInFrame(const std::vector<std::string>& messages, char frameChar, size_t titleMsgPos = 0);
} // namespace CONSOLE_UTILS