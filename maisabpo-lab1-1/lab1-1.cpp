#include <iostream>
#include "binary_output.hpp"


void printUsage(std::string programName)
{
	std::cout << "Usage: " << programName << " <input file> <format>\n";
	std::cout << "\t--help\t\t\tPrints this help message\n";
	std::cout << "\t<input file>\t\tThe input file to read\n";
	std::cout << "\t<format>\t\tThe output format\n";
	std::cout << "\t\t format: hex<8, 16, 32>, dec<8, 16>, all\n";
}

int main(int argc, char** argv)
{
	for (size_t i = 0; i < argc; i++)
	{
		if (std::string(argv[i]) == "--help")
		{
			printUsage(argv[0]);
			return 0;
		}
	}

	if (argc < 3)
	{
		printUsage(argv[0]);
		return 1;
	}

	std::string fileName = argv[1];
	std::string format = argv[2];

	maisabpo::bout out;
	out.readFromFile(fileName);
	if (format == "hex8") {
		out.hex8();
	}
	else if (format == "hex16") {
		out.hex16();
	}
	else if (format == "hex32") {
		out.hex32();
	}
	else if (format == "dec8") {
		out.dec8();
	}
	else if (format == "dec16") {
		out.dec16();
	}
	else if (format == "all") {
		out.hex8();
		out.hex16();
		out.hex32();
		out.dec8();
		out.dec16();
	}
	else {
		printUsage(argv[0]);
		return 1;
	}
	
	return 0;
}