#include "chapterFive.h"

void Variables() {
	char* ch; // karakterre hivatkozó mutató
	char* ch2 = "ch";
	int arr[10]; // 10 egészbõl álló tömb
	int arr2[] = { 0,1,2,3,4,5,6,7,8,9 };
	int& int_ref = *arr; // 10 egészbõl álló tömb referenciája
	std::string* str_ref[10]; // karakterláncokból álló tömbre hivatkozó mutató
	std::string str_lst[10] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
	std::string* str_ref2 = str_lst;
	char** ppc; // karakterre hivatkozó mutatóra hivatkozó mutató
	char** ppc2 = &ch;
	const int FOUR = 4; // konstans egész
	const int* const_int; // konstans egészre hivatkozó mutató
	const int* c_int = &FOUR;
	int *const const_point = new int(4); // egészre hivatkozó konstans mutató
}

void TypeOfPointers() {
	const char* p = "Herakleitosz";
	const char* q = "Herakleitosz";
	if (p == q) 
		std::cout << "Egyezik!\n";
}

void SomeTypeDef() { // Használjunk typedef-et a következõk meghatározására
	typedef unsigned char uchar; // unsigned char
	typedef const unsigned char cuchar; // const unsigned char
	typedef int* pint; // egészre hivatkozó mutató
	typedef char** ppchar; // karakterre hivatkozó mutatóra	hivatkozó mutató
	typedef char* parrchar[]; // karaktertömbökre hivatkozó mutató
	typedef int* psevenint[7]; // elemû, egészre hivatkozó mutatókból álló tömb
	typedef int** ppseneint[7]; // 7 elemû, egészre hivatkozó mutatókból álló tömbre hivatkozó mutató
	typedef int* pintint[8][7];
}

void swap1(int* a, int* b)	 {
	int* c = b;
	b = a;
	a = c;
	std::cout << "a: " << *a << " b: " << *b << std::endl;
}

void swap2(int& a, int& b) {
	int c = b;
	b = a;
	a = c;
	std::cout << "a: " << a << " b: " << b;
}

void DefOfSwap() {
	int a = 1;
	int b = 2;
	swap1(&a, &b);
	swap2(a, b);
}

void SizeOfCharArr() {
	char str[] = "rövid karakterlánc";
	std::cout << sizeof(str);
}

void f(char c) {

}

void g(char& c) {

}

void h(const char& c) {

}

void CallUserFunctions() {
	char ch = 'a';
	char num1 = 49;
	char num2 = 3300;
	char c = 'c';
	unsigned char uc = '1';
	signed char sc = '-1';

	f(ch);
	f(num1);
	f(num2);
	f(c);
	f(uc);
	f(sc);

	g(ch);
	g(num1);
	g(num2);
	g(c);
	//g(uc);
	//g(sc);

	h(ch);
	h(num1);
	h(num2);
	h(c);
	h(uc);
	h(sc);
}

void MonthAndDays() {
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (int i = 0; i < 12; i++) {
		std::cout << months[i] << ": " << days[i] << std::endl;
	}

	std::pair<std::string, int> monday[12] = {std::make_pair("January", 31), std::make_pair("February", 28), std::make_pair("March", 31), 
											std::make_pair("April", 30), std::make_pair("May", 31), std::make_pair("June", 30), 
											std::make_pair("July", 31), std::make_pair("August", 31), std::make_pair("September", 30),
											std::make_pair("October", 31), std::make_pair("November", 30), std::make_pair("December", 31)};

	for (int i = 0; i < 12; i++) {
		std::cout << monday[i].first << ": " << monday[i].second << std::endl;
	}
}

void IndexOrPointerInArray() {
	char v[10] = { 'a', 'b', 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j'};
	for (int i = 0; i < 10 != 0; i++)
		std::cout << v[i] << std::endl;

	for (char* p = v; *p != 'j'; p++)
		std::cout << *p << std::endl;
}

void UseOwnName() {
	//int x = x; // nincs értelme
}

void PrintReceivedList(std::string(&months)[12]) {

	//std::string first[] = { "a","be","see" };
	//std::cout << sizeof(first) / sizeof(first[0]) << std::endl;

	int size = sizeof(months) / sizeof(months[0]);

	for (int i = 0; i < size; i++) {
		std::cout << months[i] << std::endl;
	}
}

void PrintArrayOfMonth() {
	std::string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	for (const std::string &text : months) {
		std::cout << text << std::endl;
	}
	std::cout << std::endl;
	//std::cout << sizeof(months) << std::endl;
	
	PrintReceivedList(months);
}

void ReadUnlessQuit() {

	std::list<std::string> str_list;
	std::string str;
	do
	{
		std::cin >> str;
		str_list.push_back(str);

	} while (str != "Quit");

	for (std::list<std::string>::iterator it = str_list.begin(); it != str_list.end(); ++it)
		std::cout << *it << ' ';

	str_list.unique();
	std::cout << std::endl;

	for (std::list<std::string>::iterator it = str_list.begin(); it != str_list.end(); ++it)
		std::cout << *it << ' ';

	str_list.sort();
	str_list.unique();
	std::cout << std::endl;

	for (std::list<std::string>::iterator it = str_list.begin(); it != str_list.end(); ++it)
		std::cout << *it << ' ';
}

std::map<std::string, int> CountCharPairs(std::string count_str) {
	std::map<std::string, int> m_str;
	std::string::iterator it;
	std::map<std::string, int>::iterator m_it;
	std::string str;

	for (it = count_str.begin(); it != count_str.end() - 1; ++it) {
		str = std::string(1, *it) + std::string(1, *(it + 1));
		m_it = m_str.find(str);
		if (m_it != m_str.end()) {
			m_it->second++;
		}
		else {
			m_str.insert(std::pair<std::string, int>(str, 1));
		}
	}
	return m_str;
}

void PrintMap(std::map<std::string, int> m_str) {
	std::map<std::string, int>::iterator m_it;

	for (m_it = m_str.begin(); m_it != m_str.end(); ++m_it) {
		std::cout << m_it->first << " " << m_it->second << std::endl;
	}
}

void FindPairOfChars() {
	std::string cpp_str = "ettlxwljgqjrhhxplmnzintltimqrrvglhocvfxbwxxasgmymaecmopfmyijxisfzkqcpwsekrjxywxxblszxzudiuqjxcgcvufg";
	char* cstr = "ettlxwljgqjrhhxplmnzintltimqrrvglhocvfxbwxxasgmymaecmopfmyijxisfzkqcpwsekrjxywxxblszxzudiuqjxcgcvufg";

	std::map<std::string, int> cpp_m = CountCharPairs(cpp_str);
	std::map<std::string, int> c_m = CountCharPairs(std::string(cstr));
	
	PrintMap(cpp_m);
	std::cout << std::endl;
	PrintMap(c_m);
}

struct Date
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	Date() {};
	Date(int y, int mo, int d, int h, int mi, int s) {
		year = y;
		month = mo;
		day = d;
		hour = h;
		minute = mi;
		second = s;
	}
	~Date() {};
	void setYear(int y) { year = y; }
	int* getYear() { return &year; }
	void setMonth(int m) { month = m; }
	int* getMonth() { return &month; }
	void setDay(int d) { day = d; }
	int* getDay() { return &day; }
	void setHour(int h) { hour = h; }
	int* getHour() { return &hour; }
	void setMinute(int m) { minute = m; }
	int* getMinute() { return &minute; }
	void setSecond(int s) { second = s; }
	int* getSecond() { return &second; }
};

std::ostream& operator << (std::ostream &strm, Date &date) {
	char date_delim = '/';
	char time_delim = ':';
	return strm << *date.getYear() << date_delim << *date.getMonth() << date_delim << *date.getDay() << " " << *date.getHour() << time_delim << *date.getMinute() << time_delim << *date.getSecond() << std::endl;
}

void PrintDate(Date date) {
	std::cout << date << std::endl;
}

void ReadDate() {
	std::string s;
	Date date;
	int arr[6];
	std::cout << "Type a date (yyyy mm dd hh mm ss): " << std::endl;
	getline(std::cin, s);
	std::stringstream ss(s); 
	int i = 0;
	while (ss.good() && i < 6) {
		ss >> arr[i];
		++i;
	}
	date.setYear(arr[0]);
	date.setMonth(arr[1]);
	date.setDay(arr[2]);
	date.setHour(arr[3]);
	date.setMinute(arr[4]);
	date.setSecond(arr[5]);

	PrintDate(date);
}

