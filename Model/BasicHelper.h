#ifndef BASICHELPER_H
#define BASICHELPER_H
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

class BasicHelper {
public:
	enum Char {
		CHAR_SPACE = ' ', CHAR_ZERO = '0'
	};
	static const string STRING_EMPTY;
	static const string STRING_SPACE;
	static const string STRING_COMMA;
	static string intToString(int input);
//    static vector<string>& split(const string &line, char separator);
	static vector<string>& split(const string &line, char separator, vector<string> &elements);
	static string trim(const string& str);
	static bool isInt(string input);
};

#endif // BASICHELPER_H
