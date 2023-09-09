#ifndef INSTRUCTIONS
#define INSTRUCTIONS
#include <string>
#include <map>
#include <functional>

struct Instructions
{
	const std::map<std::string, void (*)(int&, int)> ALU{
		{"MOV", [](int& a, int b){ a = b; }},
		{"ADD", [](int& a, int b){ a += b; }},  
		{"SUB", [](int& a, int b){ a -= b; }}, 
		{"MUL", [](int& a, int b){ a *= b; }},
		{"DIV", [](int& a, int b){a /= b; }}
/*
		{"AND", },
		{"OR", },
		{"NOR", },
		{"CMP", },
		{"JMP", },
		{"JG", },
		{"JL", },
		{"JE", }
*/
	};
};

#endif
