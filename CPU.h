#ifndef CPU_H
#define CPU_H
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

#include "instructions.h"
#include "registers.h"

class CPU
{
	public:
	void decode();					//excecutes the current program counters instructions
	void excecute();				//excecutes the entire assembly code
	void print();					//The current state of memory and registers
	void fetch(const std::string&);			//Loades the code from the file to the memory
	private:
	Registers registers;				// registers
	std::vector<std::vector<std::string>> data;	//an instance of Instructions class, it containss all the instructions	
	Instructions instructions;			//instructions set
	std::map<std::string, int> lables;		//lables for jump
	bool isRegister(const std::string&);		//helper functions checkes if the input is registers name
	int toInt(const std::string&);			//helper function convertes the string into an integer
	bool isLiteral(const std::string&);		//helper function checkes it the input is literal
	void scanLables();				//scanes all the instructions into an lables data structure
};
	
void CPU::decode() {				
	int& pc = registers.registers["PC"];
	if (pc >= data.size()) {
		throw std::runtime_error("Out of bounds!");
	}
	if (instructions.ALU.count(data[pc][0])) {	//ALU 
		if (isRegister(data[pc][1])) {
			if (isRegister(data[pc][2])) {
				instructions.ALU[data[pc][0]](registers.registers[data[pc][1]], registers.registers[data[pc][2]]);
			} else if (isLiteral(data[pc][2])) {
				int literal = toInt(data[pc][2]);
				instructions.ALU[data[pc][0]](registers.registers[data[pc][1]], literal);
			}
		}
	} else if (instructions.JMP.count(data[pc][0])){	//Jump
		int lable = lables[data[pc][1]];
		instructions.JMP[data[pc][0]](lable, pc, registers.registers["FLG"]);
	} else if (data[pc][0] == "CMP"){			//comperison
		if (isRegister(data[pc][1])) {
			if(isRegister(data[pc][2])) {
				instructions.CMP(registers.registers[data[pc][1]], registers.registers[data[pc][2]], registers.registers["FLG"]);
			} else if (isLiteral(data[pc][2])) {
				int literal = toInt(data[pc][2]);
				instructions.CMP(registers.registers[data[pc][1]], literal, registers.registers["FLG"]);
			} else {
				throw std::runtime_error("Syntax error!");
			}	
		} else if (isLiteral(data[pc][1])) {
			if (isLiteral(data[pc][2])) {
				int literal1 = toInt(data[pc][1]);
				int literal2 = toInt(data[pc][1]);
				instructions.CMP(literal1, literal2, registers.registers["FLG"]);
			} else if (isRegister(data[pc][2])) {
				int literal = toInt(data[pc][1]);
				instructions.CMP(literal, registers.registers[data[pc][2]], registers.registers["FLG"]);
			} else {
				throw std::runtime_error("Syntax error!");
			}	
		}
	}
	registers.registers["PC"] += 1;
}


void CPU::excecute(){
	do {
		decode();
	} while( registers.registers["PC"] < data.size());
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
	scanLables();
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
	bool flag = number == INT_MIN ? false : true;
	return flag;
}


int CPU::isMemory(const std::string& value) {
	int lastIndex = value.size() - 1;
	if (value[0] == '[' && value[lastIndex] == ']') {
		std::string memory = value.substr(1, lastIndex - 1);
	}
	return 0;
}

void CPU::scanLables(){
	for(int i{}; i < data.size(); ++i) {
		if (data[i][0] == "LBL") {
			lables[data[i][1]] = i;
		}
	} 
}
#endif
