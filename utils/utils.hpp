#pragma once

#ifdef CONSOLE_UTILS_EXPORTS
#define CONSOLE_UTILS_API __declspec(dllexport)
#else
#define CONSOLE_UTILS_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include <vector>

namespace CONSOLE_UTILS
{
    enum MarkdownEl
    {
        UNDEFINED,
        MESSAGE,
        TITLE
    };

    extern "C++" CONSOLE_UTILS_API void printInsideFrame(const std::vector<std::string> &messages, char fillChar = '#') noexcept;
} // namespace CONSOLE_UTILS