#pragma once
#include <iostream>

#include "View.h"
#include "../../entities/User.h"

using namespace std;

class HelpView : public View
{

public:

	HelpView(User* user)
		: View(user)
	{
	}

	void display() override
	{
		cout << "Type 'help' to view commands" << endl;
		cout << "Type 'logout' to logout" << endl;
		cout << "Type 'exit' to exit" << endl;
	}
};
