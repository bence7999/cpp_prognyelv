#include <iostream>
#include <string>
#include <climits>
#include "chapterFour.h"
#include "chapterFive.h"
#include "ChapterSix.h"
#include "Calculator.h"
#include "ChapterSeven.h"

void Exit();

int main(int argc, char* argv[]){

	AddElemToTnode("1");
	AddElemToTnode("2");
	AddElemToTnode("3");
	AddElemToTnode("4");
	AddElemToTnode("5");
	AddElemToTnode("6");
	AddElemToTnode("7");
	AddElemToTnode("8");
	//AddElemToTnode("9");

	Exit();
	return 0;
}

void Exit() {
	bool exit = true;
	std::string str;
	while (exit)
	{
		std::cout << "\nDo you want exit: (y/n)";
		std::cin.clear();
		getline(std::cin, str);
		const char *cstr = str.c_str();
		if (*cstr == 'y')
			exit = false;
	}
}