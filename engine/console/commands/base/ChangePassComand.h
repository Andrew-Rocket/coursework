#pragma once
#include <iostream>
#include "../Command.h"
#include "../../../entities/User.h"

using namespace std;

class ChangePassCommand : public Command
{
private:
	UserService* userService;
public:

	ChangePassCommand(UserService* userService)
	{
		this->userService = userService;
		name = "changepass";
		description = "changepass {old pass} {new pass} - to  change your pass";
		admin = false;
	}

	void execute(vector<string> args, User* user) override
	{
		if (args.at(1) == user->getPassword())
		{
			user->setPassword(args.at(2));
			userService->updateById(user->getId(), user);
			cout << "Password successfully changed" << endl;
		}
		else
		{
			cout << "Wrong password" << endl;
		}
	}
};
