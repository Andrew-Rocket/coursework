#pragma once
#include <iostream>
#include <map>

#include "../Command.h"
#include "../../../utils/Utils.h"
#include "../../../entities/User.h"
#include "../../../services/UserService.h"
#include "../../views/ReceiptView.h"
#include "../../views/UsersView.h"
#include "../../views/View.h"

using namespace std;

class UsersCommand : public Command
{
private:
	UserService* userService;
	View* view;
public:

	UsersCommand(UserService* userService)
	{
		this->userService = userService;
		name = "users";
		description = "*users - show all the users in the db";
		admin = true;

	}

	void execute(vector<string> args, User* user) override
	{
		view = new UsersView(user, userService->getAll());
		view->display();
	}
};
