#pragma once
#include <iostream>
#include "../Command.h"
#include "../../../entities/User.h"

using namespace std;

class BalanceCommand : public Command
{
public:

	BalanceCommand()
	{
		name = "balance";
		description = "balance - to view your balance";
		admin = false;
	}

	void execute(vector<string> args, User* user) override
	{
		cout << "Balance: $" << user->getBalance() << "." << endl;
	}
};
