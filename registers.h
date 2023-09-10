#ifndef REGISTERS
#define REGISTERS
#include <map>
#include <string>

struct Registers{
	// karoxa valuen chkaroxanam poxem heto?
	std::map<const std::string, int> registers;
	Registers(): registers({
		{"EAX", 0},
		{"EBX", 0},
		{"ECX", 0},
		{"EDX", 0},
		{"FLG", -1},
		{"PC", 0}
	}) {};
};

#endif	
