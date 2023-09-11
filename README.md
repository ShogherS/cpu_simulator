# cpu_simulator
Overview

The CPU Simulator is a C++ program that emulates the behavior of a simplified Central Processing Unit (CPU). 
This CPU is designed to work with registers, execute a set of arithmetic, logic, comparison, and jump instructions, and maintain a memory state. 
This README provides an overview of the CPU class and its functionality.

Table of Contents
  * CPU Class
  	* Methods
  * Usage
  * Examples
  * Contributing
    
CPU Class
Methods
	void decode()
	Executes the current program counter's instructions.

	void execute()
	Executes the decoded instructions.

	void print()
	Displays the current state of memory and registers.

	void fetch(const std::string&)
	Loads the code from a file into memory.
	
	Private Members

	Registers registers
	Represents the CPU's registers.
	std::vector<std::vector<std::string>> data
	Stores the program code and data.
	Instructions instructions
	Contains the set of supported instructions.
	std::map<std::string, int> labels
	Provides labels for jump instructions.
	Helper Functions
	bool isRegister(const std::string&)
	Checks if a given string represents a register.
	int toInt(const std::string&)
	Converts a string to an integer.
	bool isLiteral(const std::string&)
	Checks if a given string is a literal (e.g., a numerical constant).
	void scanLabels()
	Scans the program code for labels used in jump instructions.
Usage
To use this program you need to do the following simple steps
1. Dowbload the entirw content of this repositry
2. The code.txt contains the assembly code, which you may change at your perferance. Make sure to follow the  the invented assembly language syntax.
3. Implement a C++ program including CPU.h file, and create an object of CPU type. Then load the assembly code frim the separate file. And finaly call the excecute() method of the CPU class.
4. You may call the print() method during your main function to see the current state of the registers and their state.
5. Compile the program and runn the it in your computer.

 An example of usage of the program
 
	CPU myCPU;                  //Instantiate an object of the CPU class.          
	myCPU.fetch("program.txt"); //Load program code into memory using the fetch method. //Execute the program by calling decode and execute in sequence.
	myCPU.execute();	    //Execute the program by calling decode and execute in sequence.
	myCPU.print();              //Optionally, use the print method to display the CPU's current state.

Examples
Here's an example of a simple program that adds two numbers:
	
 	MOV EAX 20	//Load 20 into register EAX
	MOV EBX 1	//Load 1 into register EBX
	ADD EAX EBX	//Adds the value of EBX to the value of EAX
	CMP EAX EBX	//Compeares tow values
	JG  _A 		//Makes a conditional jump
	MOV EDX 222 	//Loads 222 into regiser EDX
	LBL _A		//Creates a lable _A
	MOV EDX 111 	//Loade 111 into the register EDX
	AND EDX 1	//Addse 1 to the EDX

Contributing
Contributions to this CPU Simulator project are welcome!
If you'd like to contribute, please fork the repository and create a pull request with your changes.
