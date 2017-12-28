#include <iostream>
#include <string>
#include <climits>
#include "chapterFour.h"
#include "chapterFive.h"

void Exit() {
	bool exit = true;
	std::string str;
	while (exit)
	{
		std::cout << "\nDo you want exit: (y/n)";
		getline(std::cin, str);
		const char *cstr = str.c_str();
		if (*cstr == 'y')
			exit = false;
	}
}

int main(){

	Exit();
	return 0;
}