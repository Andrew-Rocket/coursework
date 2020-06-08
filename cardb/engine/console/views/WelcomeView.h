#pragma once
#include <iostream>

#include "View.h"
#include "../../entities/User.h"

using namespace std;

class WelcomeView : public View
{

public:

	explicit WelcomeView(User* user)
		: View(user)
	{
	}

	void display() override
	{
		cout << "<<-- Welcome to the car shop, " + user->getUsername() + "! -->>" << endl;
		cout << "Type 'help' to view commands" << endl;
		cout << "Type 'logout' to logout" << endl;
		cout << "Type 'exit' to exit" << endl;
		if (user->isAdmin() == true)
		{
			cout << "It looks like your are administrator, you can now see admin commands in 'help', they are marked with star *" << endl;
		}
	}
};
