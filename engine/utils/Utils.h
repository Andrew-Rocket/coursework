#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../enums/CarProperties.h"
#include "../enums/Order.h"
#include "../exceptions/StringToBoolCastException.h"

using namespace std;
class Utils
{
public:
	//Check if the string is numeric
	static bool isNumericString(std::string& str)
	{
		return std::all_of(std::begin(str), std::end(str), [](auto ch) { return isdigit(ch); });
	}

	//Parser to CarProperties enum
	static CarProperties parseStringToCarProperties(string str)
	{
		str = toUpperCase(str);
		static unordered_map<std::string, CarProperties> const table = {
			{"COLOR", COLOR},
			{"BRAND", BRAND},
			{"ELECTRIC", ELECTRIC},
			{"MAX_SPEED", MAX_SPEED},
			{"PRICE", PRICE},
			{"YEAR", YEAR},
		};
		auto it = table.find(str);
		if (it != table.end()) {
			return it->second;
		}
		return COLOR;
	}

	static Order parseStringToOrder(string str)
	{
		str = toUpperCase(str);
		static unordered_map<std::string, Order> const table = {
			{"ASC", ASC},
			{"DESC", DESC},
		};
		auto it = table.find(str);
		if (it != table.end()) {
			return it->second;
		}
		return DESC;
	}


	static string toUpperCase(string str)
	{
		string up;
		for (auto ch : str)
		{
			up += toupper(ch);
		}
		return up;
	}

	static bool stringToBool(string str)
	{
		str = toUpperCase(str);
		if (str.compare("TRUE") == 0 || str.compare("1") == 0)
		{
			return true;
		}

		if (str.compare("FALSE") == 0 || str.compare("0") == 0)
		{
			return false;
		}

		throw StringToBoolCastException("String is neither true/false or 1/0");
	}

};
