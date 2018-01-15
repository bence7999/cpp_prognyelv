#include <iostream>
#include <string>
#include <climits>
#include "chapterFour.h"
#include "chapterFive.h"
#include "ChapterSix.h"
#include "Calculator.h"

void Exit();

int main(int argc, char* argv[]){

	TwentyTwoWithoutComment();

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