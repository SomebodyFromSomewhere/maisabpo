#include <cstdint>
#include <string>
#include <vector>
#include "mutl.hpp"

int main()
{
	uint64_t a = 123;
	uint64_t b = 456;
	uint64_t M = 551;

	std::vector<std::string> myMessages = {"Hello", "World!", "Center Me"};
    char frameCharacter = '#';

    // Печать сообщений с рамкой, указывая, что "World!" является заголовком
    mutl::printMessagesInFrame(myMessages, frameCharacter, 2);
    mutl::printMessagesInFrame(myMessages, frameCharacter, 0);
	//uint64_t result = (a + b) mod M = 28;
	//result = (a - b) mod M = 218;
	//result = (a * b) mod M = 437;
	//result = (a ^ b) mod M = 239;
	//result = a ^ (-1) mod M = 112;
	//result = b ^ (-1) mod M = NULL;
	//result = (b / a) mod M = 291;
	//result = (a / b) mod M = NULL;

	return 0;
}