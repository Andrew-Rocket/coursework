#pragma once
#include <iomanip>
#include <iostream>

#include "HelpView.h"
#include "View.h"
#include "../../entities/Receipt.h"
#include "../../entities/User.h"

using namespace std;

//View to view products
class UsersView : public View
{

private:
	vector<User*> users;
	HelpView* view;
public:


	UsersView(User* user, vector<User*> users)
		: View(user)
	{
		this->users = users;
		view = new HelpView(user);
	}

	void display() override
	{
		//	system("CLS");

			//Using printf instead of cout to make it shorter 
		printf("|%+10s|%+10s|%+10s|%+10s|%+10s|\n",
			"Id", "Username", "Balance", "Spent", "Role");
		cout << string(55, '-') << endl;

		for (auto user : users)
		{
			string role = user->isAdmin() ? "Admin" : "User";

			cout << "|" << setw(10) << std::right << user->getId();
			cout << "|" << setw(10) << std::right << user->getUsername();
			cout << "|" << setw(10) << std::right << user->getBalance();
			cout << "|" << setw(10) << std::right << user->getSpent();
			cout << "|" << setw(10) << std::right << role;
			cout << "|" << endl;
		}
		cout << endl;
		view->display();
	};
};
