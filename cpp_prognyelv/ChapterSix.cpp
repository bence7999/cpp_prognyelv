#include "ChapterSix.h"

using namespace std;

void OneForLoop() {
	int max_length = 10;
	int input_line[10] = {0, 1, 2, 0, 1, 2, 0 , 1, 2, 0};
	int i;
	int quest_count = 0;
	for (i = 0; i<max_length; i++)
		if (input_line[i] == 2)
			quest_count++;
	
	cout << quest_count << endl;
}

void OneWhileLoop() {
	int i = 0;
	vector<int> input_line = { 0, 1, 2, 0, 1, 2, 0 , 1, 2, 0 };
	int quest_count = 0;
	int max_length = 10;
	while (i < max_length)
	{
		if (input_line[i] == 2)
			quest_count++;
		i++;
	}
	cout << quest_count << endl;
}

void OneWhileLoopPointer() {
	vector<int> input_line = { 0, 1, 2, 0, 1, 2, 0 , 1, 2, 0 };
	int i = 0;
	int max_length = 10;
	int quest_count = 0;
	auto p = input_line.begin();
	while (i < max_length) {
		if( *p == 2 )
			quest_count++;
		p = next(p);
		i++;
	}
	cout << quest_count << endl;
}

int f(int a, int b) {return a*b;}

void TwoBrackets() {
	// a + b * c === a + ( b * c )
	// a + b + c === ( a + b ) + c
	// a = b = c === a = ( b = c )
	// *p++ === *(p++)
	// a = b < c ? d = e : f = g === a = ( ( b < c ) ? ( d = e ) : ( f = g ) ) 
	// kif & kif --> bitenténki és
	// 0 0 -> 0
	// 1 1 -> 1
	// 0 1 -> 0
	// kif << kif --> balra léptetés 10000 = 010(2) << 011(3) --> 3-al shift 2
	// 10000 = 010(2) << 011(3) --> 3-al shift 2
	// 01100 = 011(3) << 101(2) --> 2-vel shift 3 
	
	// a = b + c * d << 2 & 8
	
	int a, b, c, d;
	b = 2; c = 3; d = 4;
	a = b + c * d << 2 & 8;
	cout << a << endl;
	a = (((b + (c * d)) << 2) & 8);
	cout << a << endl;

	//a & 077 != 3
	cout << (a & 077 != 3) << endl;
	cout << (a & (077 != 3)) << endl; // korábban szerepel a táblázatban a != mint a &

	//a == b || a == c && c < 5
	a = 1; b = 1; c = 2;
	cout << (a == b || a == c && c < 5) << endl;
	cout << ((a == b) || ((a == c) && (c < 5))) << endl;

	//c = x != 0
	int x = 0;
	cout << (c = x != 0) << endl;
	cout << (c = (x != 0)) << endl;

	//0 <= i < 7
	int i = 2;
	cout << (0 <= i < 7) << endl;
	//cout << ((0 <= i) < 7) << endl; -> a belső kiértékelés eredménye true or false
	//cout << (0 <= (i < 7)) << endl; -> a belső kiértékelés eredménye true or false
	cout << (0 <= i && i <= 99) << endl;

	//f(1,2)+3
	cout << f(1, 2) + 3 << endl;

	//a = - 1 + + b -- - 5
	b = 2;
	a = -1 + +b-- - 5;
	cout << a << endl;
	b = 2;
	a = (-1 + (+b--) - 5); // végrehajtás után csökken az érték
	cout << a << endl;

	//a = b == c++
	b = 2; c = 1;
	cout << (a = b == c++) << endl;
	b = 2; c = 1;
	cout << (a = (b == (c++))) << endl; // később értékelődik ki a ++
	b = 2; c = 1;
	cout << (a = (b == (++c))) << endl; // egyből kiértékelődik a ++

	// a = b = c = 0
	cout << (a = b = c = 0) << endl;
	cout << (a = (b = (c = 0))) << endl;

	//a[4][2] *= *b ? c : *d * 2
	cout << endl;
	int aa[5][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}, {12,13,14} };             
	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "a[" << i << "][" << j << "]: ";
			cout << aa[i][j] << endl;
		}
	}*/
	cout << aa[4][2] << endl;
	int bb = 0;
	int dd = 2;
	c = 3;
	int* bi = &bb;
	int *di = &dd;
	cout << (*bi ? c : (*di * 2)) << endl;
	cout << (aa[4][2] *= (*bi ? c : (*di * 2))) << endl;
	cout << aa[4][2] << endl;

	// a-b,c=d
	cout << endl << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
	cout << (a - b, c = d) << endl;
	cout << (4, (1)) << endl; // left to right
}	

void ThreeNameAndValue() {
	map<string, float> pair_map;
	string name;
	float value;
	while (cin >> name >> value) {
		if (name == "0" || value == 0) break;
		//cout << name << " " << value << endl;
		pair_map[name] = value;
	}
	//cout << pair_map.size() << endl;
	float sum = 0;
	float average = 0;
	for (std::map<string, float>::iterator it = pair_map.begin(); it != pair_map.end(); ++it) {
		sum += it->second;
	}
	average = sum / pair_map.size();
	cout << "sum: " << sum << " average: " << average << endl;
}

void PrintFourTable(int a, int b, char c, int res) {
	cout << bitset<2>(a) << " " << c << "  (" << a << ")" << endl;
	cout << bitset<2>(b) << " =" << "  (" << b << ")" << endl;
	cout << "==" << endl;
	cout << bitset<2>(res) << "    (" << res << ")" << endl << endl;
}

void PrintFourShift(int a, int s) {
	if (s > 0) { // shift to left
		cout << "orig: " << bitset<2>(a) << " left shifted: " << bitset<2>(a << s) << endl;
	}
	else if (s < 0) { // shift to right
		s = abs(s);
		cout << "orig: " << bitset<2>(a) << " right shifted: " << bitset<2>(a >> s) << endl;
	}
	
}

void FourBitOperation() {
	// & - bitenténki és
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//PrintFourTable(i, j, '&', i&j);
		}
	}
	// | - bitnekénti vagy
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//PrintFourTable(i, j, '|', i|j);
		}
	}

	// ^ - bitenkénti vizáróvagy (XOR)
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//PrintFourTable(i, j, '^', i^j);
		}
	}

	// ~ - bitenkénti 
	int a = 0;
	cout << "a: " << bitset<1>(a) << " not a: " << bitset<1>(~a) << endl;
	a = 1;
	cout << "a: " << bitset<1>(a) << " not a: " << bitset<1>(~a) << endl;

	// >> - jobbra léptetés
	PrintFourShift(2, -1);

	// << - balra léptetés
	PrintFourShift(1, 1);
}

void FiveUndefinedStructure() {
	unsigned char c2 = 1256;
	cout << int(c2) << endl; // 232 lesz
}

void FiveDependOnImplementation() {
	const int size = 4 * 1024;
	char page[size];

	page[size + size] = 7; // nem meghatározható
}

int g(int a) {return 2 * a;}

int f(int b) {return 3 * b;}

void SevenEvaluation() {
	int x = f(2) + g(3); // nem meghatározott, hogy f() vagy g() hívódik meg elõször
	cout << x << endl;

	int v[2] = { 1, 2 };
	int i = 1;
	v[i] = i++; // nem meghatározott eredmény
}

void EightException() {
	// cout << 1 / 0 << endl; // error : divide by zero
	stack<int> mystack;
	//mystack.pop(); // assert: empty before pop
	// int array[1000000]; // 0xC00000FD: Stack overflow (parameters: 0x00000000, 0x002B2000).
}

struct Panda
{
	int Ma() {
		int x = 5;
		int* y = &x;
		return *y;
	}
};

void NineBrackets() {
	int a = 5;
	int *p = &a;
	// *p++
	cout << (*p)++ << endl;
	// *--p
	cout << --(*p) << endl;
	// ++a--
	cout << (++a)-- << endl;

	Panda* pa = new Panda();
	//(int*)p->m;
	cout << (int*)pa->Ma() << endl;
	//*p.m;
	int* arr[3];
	int i = 1;
	//*a[i]
	*arr[i];
}

int TenStrlen(char* c) { // 5.3.1. Tömbök bejárása
	int sum = 0;
	//cout << c << endl << endl;
	for (char* p = c; *p != 0; p++) {
		//cout << p << endl;
		sum++;
	}
	int sum2 = 0;
	for (int i = 0; c[i] != 0; i++) {
		//cout << c[i] << endl;
		sum2++;
	}
	if (sum == sum2)
		return sum;
	else
		return 4;
}

char* TenStrcpy(char* cf, char* ct) {
	cout << strlen(cf) << endl;
	//cout << strcat_s(cf, ct);
	strcpy(cf, ct);
	return cf;
}

void TenStrcmp(char* c1, char* c2) {

}

void ElevenErrors(int a, int b) {
	if (a = 3)
		cout << "no" << endl; // True
	if (a & 077 == 0)
		cout << "nono" << endl; // False
	//a: = b + 1; //Expected az expression
}

string ThirteenCat(char* c1, char* c2) { 
	cout << strlen(c1) << endl;
	size_t sum = strlen(c1) + strlen(c2);
	//cout << sum << endl;
	char* a = new char[sum];
	
	cout << "a: " << sizeof(a) << " " << strlen(a) << endl;

	//char* b = c1;
	//char* c = c2;

	// cout << b[0] << " " << c[0] << endl;

	/*for (char* p = c1; *p != 0; p++) {
		cout << *p << endl;
	}*/
	//cout << "sizeof a: " << sizeof(a) << endl;
	string str1(c1);
	string str2(c2);

	cout << sizeof(c1) << " " << sizeof(c2) << endl;
	for (int i = 0; i < sizeof(c1); i++) {
		a[i] = c1[i];
	}
	for (int i = 0; i < sizeof(c2); i++) {
		a[sizeof(c1)+i] = c2[i];
	}
	for (char* p = a; *p != 0; p++) {
		//cout << 1 << endl;
	}
	//cout << a << endl;
	return str1+str2;
}

void FiveTeenSwitch(int* to, int* from, int count) {
	int n = (count + 7) / 8;
	switch (count % 8) {
	case 0: do {
		*to++ = *from++;
	case 7: *to++ = *from++;
	case 6: *to++ = *from++;
	case 5: *to++ = *from++;
	case 4: *to++ = *from++;
	case 3: *to++ = *from++;
	case 2: *to++ = *from++;
	case 1: *to++ = *from++;
	} while (--n>0);
	}
}

int SixTeenAtoi(const char* src) {
	//cout << sizeof(src) << endl;
	char a[sizeof(src)-1];
	string str = "";
	//int b = int(a)-48;
	//cout << b << endl;
	int sum = 0;
	while (*src != 0)
	{
		//cout << typeid(*src).name() << endl; // type of value
		//cout << int(*src)-48 << endl;
		a[sum] = int(*src) - 48;
		str += to_string(int(*src) - 48); // int to string
		sum++;
		*src++;
	}
	for (int i = 0; i < sizeof(a); i++) {
		//cout << int(a[i]) << endl;
	}
	//cout << str << endl;
	//cout << int(a[0]) << endl;
	//cout << int(a[1]) << endl;
	//cout << int(a[2]) << endl;

	//cout << int(a) << endl;

	return atoi(str.c_str());
}

char* mystrcopy(char *dst, const char *src) {
	char *ptr;
	ptr = dst;
	while (*dst++ = *src++);
	return(ptr);
}

