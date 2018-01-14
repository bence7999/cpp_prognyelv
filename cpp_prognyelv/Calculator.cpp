#include "Calculator.h"

using namespace std;

//#define THROW_MY_EXCEPTION( msg ) throw MyException( (msg), __FILE__, __LINE__) // macro: kicserélni a sima error-t olyanra ami tartalmazza a file-t és line-t


//////////////////////////////////////////////////////
////                 Hibakezelés                  ////
/////////////////////////////////////////////////////

int no_of_errors;

double error(const string& s, char const * file, long line) {
	no_of_errors++;
	cerr << endl << "Error: " << s << endl;
	cerr << error << " in \"" << file << "\",line:" << line << endl;
	return 1;
}

//////////////////////////////////////////////////////
////        Elemző (szintaktikai elemzés         ////
/////////////////////////////////////////////////////

map<string, double> table;
double number_value;
string string_value;

double term(bool);
double expr(bool);
double prim(bool);

enum Token_value {
	NAME, NUMBER, END,
	PLUS='+', MINUS='-', MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(', RP=')'
};

Token_value curr_tok = PRINT;
Token_value get_token();

double prim(bool get) {
	if (get) 
		get_token();

	switch (curr_tok)
	{
		case NUMBER: {
			double v = number_value;
			get_token();
			return v;
		}
		case NAME: {
			double& v = table[string_value];
			if (get_token() == ASSIGN)
				v = expr(true);
			return v;
		}
		case MINUS: {
			return -prim(true);
		}
		case LP: {
			double e = expr(true);
			if (curr_tok != RP)
				return error(") szükséges!", __FILE__, __LINE__);
			get_token();
			return e;
		}
		default:
			return error("elemi szimbolum szukseges!", __FILE__, __LINE__);
	}

}

double term(bool get) {
	double left = prim(get);

	for (;;) {
		switch (curr_tok)
		{
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true)) {
				left /= d;
				break;
			}
			return error("Nullaval nem osztunk!", __FILE__, __LINE__); // 6.1.4
		default:
			return left;
		}
	}
}

double expr(bool get) {
	double left = term(get);

	for (;;) {
		switch (curr_tok)
		{
			case PLUS:
				left += term(true);
				break;
			case MINUS:
				left -= term(true);
				break;
			default:
				return left;
		}
	}
}

//////////////////////////////////////////////////////
////     Bemeneti függveny (lexikai elemzés)     ////
/////////////////////////////////////////////////////

Token_value get_token() {
	char ch;

	do {
		if ( !cin.get(ch) ) // cin.get olyan mint a cin >>; beolvas egy char-t ch ba, csak nem ugorja át az üreshelyeket
			return curr_tok = END;
	} while (ch != '\n' && isspace(ch));

	switch (ch)
	{
	case ';':
	case '\n':
		return curr_tok = PRINT;
	case 0:
		return curr_tok = END;
	case '*': case '/': case '+': case '-': case '(': case ')': case '=':
		return curr_tok = Token_value(ch);
	case '0': case '1': case '2': case '3': case '4': 
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		cin.putback(ch); // visszateszi a cin-re
		cin >> number_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch)) {
			string_value = ch;
			while (cin.get(ch) && isalnum(ch))
			{
				string_value.push_back(ch); // char-t csap a végére
			}
			cin.putback(ch);
			return curr_tok = NAME;
		}
		error("rossz szimbolum!", __FILE__, __LINE__);
		return curr_tok = PRINT;
	}
}

//////////////////////////////////////////////////////
////            Calculator Vezérlő               ////
////       kezdeti értékadás, kimenet hibák       ////
/////////////////////////////////////////////////////

istream* input;

int Calculator(int argc, char* argv[]) {

	switch (argc)
	{
	case 1: {
		input = &cin;
		break;
	}
	case 2: {
		input = new istringstream(argv[1]);
		break;
	}
	default:
		error("túl sok parameter", __FILE__, __LINE__);
	}

	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;

	while (cin) {
		get_token();
		if (curr_tok == END)
			break;
		if (curr_tok == PRINT)
			continue;
		cout << expr(false) << endl;
	}

	if (input != &cin)
		delete input;
	return no_of_errors;
}