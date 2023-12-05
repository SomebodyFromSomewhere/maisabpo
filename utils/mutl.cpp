#include "mutl.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace mutl
{

    void printMessageInFrame(const std::string &message, char frameChar)
    {
        // Определяем размер рамки
        size_t frameWidth = message.length() + 4;

        // Верхняя граница рамки
        std::cout << std::string(frameWidth, frameChar) << std::endl;

        // Сообщение в рамке
        std::cout << frameChar << ' ' << message << ' ' << frameChar << std::endl;

        // Нижняя граница рамки
        std::cout << std::string(frameWidth, frameChar) << std::endl;
    }

    void printMessageWithTopBorder(const std::string &message, char frameChar, size_t width)
    {
        std::string paddingLeft, paddingRight;

        size_t paddingLeftLength = static_cast<size_t>(std::floor((width - message.length()) / 2.0));
        size_t paddingRightLength = static_cast<size_t>(std::ceil((width - message.length()) / 2.0));
        paddingLeft = std::string(paddingLeftLength, frameChar);
        paddingRight = std::string(paddingRightLength, frameChar);

        std::cout << paddingLeft << message << paddingRight << std::endl;
    }

    void printMessagesInFrame(const std::vector<std::string> &messages, char frameChar, size_t titleMsgPos)
    {
        if (messages.empty())
        {
            std::cout << "No messages to print." << std::endl;
            return;
        }

        // Находим максимальную длину сообщения
        size_t maxMessageLength = 0;
        for (const auto &message : messages)
        {
            maxMessageLength = std::max(maxMessageLength, message.length());
        }

        // Определяем размер рамки
        size_t frameWidth = maxMessageLength + 4;
        size_t titlePosition = 0;
        if (titleMsgPos > 0)
        {
            // Позиция заголовка
            titlePosition = (titleMsgPos > 0 && titleMsgPos <= messages.size()) ? titleMsgPos - 1 : 0;
            // Выводим заголовок вверху
            if (titlePosition < messages.size())
            {
                printMessageWithTopBorder(messages[titlePosition], frameChar, maxMessageLength + 4); // два пробела и два символа границы
            }
        }
        else
        {
            // Верхняя граница рамки
            std::cout << std::string(frameWidth, frameChar) << std::endl;
            titlePosition = messages.size();
        }
        // Печать каждого сообщения внутри рамки
        for (size_t i = 0; i < messages.size(); ++i)
        {
            if (i != titlePosition)
            {
                size_t padding = (maxMessageLength - messages[i].length()) / 2;
                std::cout << frameChar << ' ' << std::string(padding, ' ') << messages[i] << std::string(padding, ' ') << ' ' << frameChar << std::endl;
                // Разделитель
                std::cout << std::string(frameWidth, frameChar) << std::endl;
            }
        }
    }
}