#ifndef CPU_H
#define CPU_H
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

#include "instructions.h"
#include "registers.h"

//#include "instructions.h"

class CPU
{
	public:
	//excecutes the current program counters instructions and incrementes the "PC" register
	void decode();
//	void excecute();
	//The current state of memory and registers
	void print();
	//Loades the code from the file to the memory
	void fetch(const std::string&);
	private:
	// registers
	Registers registers;
	//memory
	std::vector<std::vector<std::string>> data;
	//instructions set
	Instructions instructions;
	//helper functions
	bool isRegister(const std::string&);
	int toInt(const std::string&);
	bool isLiteral(const std::string&);
	int isMemory(const std::string&);
	//bool isLable(const std::string&);
};

void CPU::decode() {
	//executing the current line of instruction
	std::vector<std::string> current{data[registers.registers["PC"]]};
	//the first value of the instruction is the insdtruction
	//finding the appropriate instruction
	//first looking in the ALU
	auto it = instructions.ALU.find(current[0]);
	if ( it == instructions.ALU.end()) {
		//not final
		throw std::runtime_error("The appropriate operation does not exists!");
	}
	auto aluFunction = it->second;
	if (isRegister(current[1])) {
		if (isRegister(current[2])) {
			aluFunction(registers.registers[current[1]], registers.registers[current[2]]);
		} else if (isLiteral(current[2])) {
			int literal = std::stoi(current[2]);
			aluFunction(registers.registers[current[1]], literal);
		}
	}
	/*
	if (current[0] == "MOV") {
		if (isRegister(current[1])) {
			if (isRegister(current[2])) {
				registers.registers[current[1]] = registers.registers[current[2]];
			} else if (isLiteral(current[2])) {
				registers.registers[current[1]] =  std::stoi(current[2]);		
			}
		}
	} else if (current[0] == "ADD") {
		if (isRegister(current[1])) {
			if (isLiteral(current[2])) {
				registers.registers[current[1]] += std::stoi(current[2]);
			} else if (isRegister(current[2])) {
				registers.registers[current[1]] += registers.registers[current[2]];
			}
		}
	}
	*/
	registers.registers["PC"] += 1;
}
void CPU::fetch(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("The file is not open!");
	}
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream lineStream(line);
		std::vector<std::string> tocens;
		std::string tocen;
		while (lineStream >> tocen) {
			tocens.push_back(tocen);	
		}
		data.push_back(tocens);
	}
	file.close();
}
void CPU::print() {
	std::cout << "________RAM________" << std::endl;
	for (int i{}; i < data.size(); ++i) {
		std::cout << i << ": " ;
		for (auto it : data[i]) {
			std::cout << it << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "___________________" << std::endl; 
	std::cout << "________CPU________" << std::endl;
	for (auto& it: registers.registers) {
		std::cout << it.first << ": " << it.second << std::endl;
	}
	std::cout << "___________________" << std::endl;
}

bool CPU::isRegister(const std::string& value) {
	bool check{false};
	auto it{registers.registers.find(value)};
	if (it != registers.registers.end()) {
		check = true;
	}
	return check;
}
int CPU::toInt(const std::string& value) {
	int strInt{};
	try {
		strInt = std::stoi(value);
	} catch (const std::invalid_argument&) {
		return INT_MIN;
	} catch (const std::out_of_range&) {
		return INT_MIN;
	}
	return strInt;
}

bool CPU::isLiteral(const std::string& value) {
	int number{toInt(value)};
	bool flag{false};
//  = number == INT_MIN ? false : true;

	return flag;
}


int CPU::isMemory(const std::string& value) {
	int lastIndex = value.size() - 1;
	if (value[0] == '[' && value[lastIndex] == ']') {
		std::string memory = value.substr(1, lastIndex - 1);
		
	}
	return 0;
}


#endif
