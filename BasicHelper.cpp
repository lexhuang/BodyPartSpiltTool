#include "basichelper.h"

const string BasicHelper::STRING_EMPTY = "";
const string BasicHelper::STRING_COMMA = ",";
const string BasicHelper::STRING_SPACE = " ";

string BasicHelper::intToString(int input) {  //將int轉成string
	ostringstream temp;  //temp as in temporary
	temp << input;
	return (temp.str());   //str is temp as string
}

vector<string>& BasicHelper::split(const string &line, char separator, vector<string> &elements) {  //切割字串回傳陣列
	stringstream ss(line);
	string item;
	elements.clear();
	while (std::getline(ss, item, separator)) {
		elements.push_back(item);
	}
	return (elements);
}

string BasicHelper::trim(const string& str) {  //去除空白
	string::size_type pos = str.find_first_not_of(STRING_SPACE.c_str()[0]);
	if (pos == string::npos) {
		return (str);
	}
	string::size_type pos2 = str.find_last_not_of(STRING_SPACE.c_str()[0]);
	if (pos2 != string::npos) {
		return (str.substr(pos, pos2 - pos + 1));
	}
	return (str.substr(pos));
}

bool BasicHelper::isInt(string input) {
	if (atoi(input.c_str()) == 0 && input[0] != CHAR_ZERO) {  //atio遇到不可處理狀況會回傳0 判斷是否真的是0
		return (false);
	}
	return (true);
}
