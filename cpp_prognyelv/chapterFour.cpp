#include "chapterFour.h"

void helloword() {
	std::string s = "Hello Word!";
	std::string s2;
	std::cout << s << std::endl;
}

void sizeOfProgram() {
	enum keyword { ASM, AUTO, BREAK };

	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "char*: " << sizeof(char*) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "int*: " << sizeof(int*) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "float*: " << sizeof(float*) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "double*: " << sizeof(double*) << std::endl;
	std::cout << "short: " << sizeof(short) << std::endl;
	std::cout << "short*: " << sizeof(short*) << std::endl;
	std::cout << "long: " << sizeof(long) << std::endl;
	std::cout << "long*: " << sizeof(long*) << std::endl;
	std::cout << "unsigned: " << sizeof(unsigned) << std::endl;
	std::cout << "unsigned*: " << sizeof(unsigned*) << std::endl;
	std::cout << "enum: " << sizeof(keyword) << std::endl;
}

int getArsciiCode(char c) {
	return int(c);
}

void printCharsAndValues() {
	std::string alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\f]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	std::string::iterator it;
	int index = 0;
	for (it = alphabet.begin(); it < alphabet.end(); it++, index++) {
		std::cout << "char: " << *it << " number: " << std::dec << getArsciiCode(*it) << " hex: " << std::hex << getArsciiCode(*it) << std::endl;
	}
	//std::cout << c << ": " << int(c) << '\n';
}

void maxMinValueOfTypes() {
	std::cout << "Minimum of signed char: " << SCHAR_MIN << std::endl;
	std::cout << "Maximum of signed char: " << SCHAR_MAX << std::endl;
	std::cout << "Minimum of unsigned char: " << SCHAR_MIN << std::endl;
	std::cout << "Maximum of unsigned char: " << SCHAR_MAX << std::endl;
	std::cout << "Minimum of char: " << CHAR_MIN << std::endl;
	std::cout << "Maximum of char: " << CHAR_MAX << std::endl;
	std::cout << "Minimum of short int: " << SHRT_MIN << std::endl;
	std::cout << "Maximum of short int: " << SHRT_MAX << std::endl;
	std::cout << "Maximum of unsigned short int: " << USHRT_MAX << std::endl;
	std::cout << "Minimum of int: " << INT_MIN << std::endl;
	std::cout << "Maximum of int: " << INT_MAX << std::endl;
	std::cout << "Maximum of unsigned int: " << UINT_MAX << std::endl;
	std::cout << "Minimum of long int: " << LONG_MIN << std::endl;
	std::cout << "Maximum of long int: " << LONG_MAX << std::endl;
	std::cout << "Maximum of unsigned long int: " << ULONG_MAX << std::endl;
	std::cout << "Minimum of long long int: " << LLONG_MIN << std::endl;
	std::cout << "Maximum of long long int: " << LLONG_MAX << std::endl;
	std::cout << "Maximum of unsigned long long int: " << ULLONG_MAX << std::endl;

}

