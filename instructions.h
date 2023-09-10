#ifndef INSTRUCTIONS
#define INSTRUCTIONS
#include <string>
#include <map>
#include <functional>

struct Instructions
{
	std::map<std::string, std::function<void(int&, int)>> ALU{
		{"MOV", [](int& a, int b){ a = b; }},
		{"ADD", [](int& a, int b){ a += b; }},  
		{"SUB", [](int& a, int b){ a -= b; }}, 
		{"MUL", [](int& a, int b){ a *= b; }},
		{"DIV", [](int& a, int b){ a /= b; }},
		{"AND", [](int& a, int b){ a &= b; }},
		{"OR", [](int& a, int b){ a |= b; }},
		{"NOR", [](int& a, int b){ a ^= b; }}
	};
	std::function<void(int, int, int&)> CMP = [](int r1, int r2, int& flag){ 
			if (r1 == r2){
				flag = 0;
			} else if (r1 > r2){
				flag = 1;
			} else {
				flag = 2;
			}
		};
	std::map<std::string, std::function<void(int, int&, int)>> JMP{
		{"JMP", [](int lable, int& pc, int fake){pc = lable;} },
		{"JG", [](int lable, int& pc, int flag){flag == 1 ? pc = lable : pc;} },
		{"JL", [](int lable, int& pc, int flag){flag == 2 ? pc = lable : pc;} },
		{"JE", [](int lable, int& pc, int flag){flag == 0 ? pc = lable : pc;} }
	};
};

#endif
