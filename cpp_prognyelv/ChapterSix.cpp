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