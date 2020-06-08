#pragma once
#include <iostream>

#include "../services/UserService.h"

using namespace std;

class ConsoleAuth
{
	UserService* userService;


public:
	ConsoleAuth(UserService* userService)
		: userService(userService)
	{
	}

	User* start()
	{
		while (true)
		{
			cout << "Welcome to the car shop, please login or register" << endl;
			cout << "Type 'login' or 'register' to proceed" << endl;
			cout << "Type 'exit' to exit" << endl;

			string cmd;
			cin >> cmd;

			//Local cmd system
			if (cmd.compare("login") == 0)
			{
				User* user = login();
				if (user != nullptr)
				{
					return user;
				}
			}

			if (cmd.compare("register") == 0)
			{
				User* user = registration();
				if (user != nullptr)
				{
					return user;
				}
			}

			if (cmd.compare("exit") == 0)
			{
				return EXIT_SUCCESS;
			}
		}
	}

	User* login()
	{
		string username;
		string password;

		cout << "Type you username: " << endl;
		cin >> username;

		cout << "Type you password: " << endl;
		cin >> password;

		User* user = userService->login(username, password);
		if (user != nullptr)
		{
			return user;
		}

		cout << "Email or password was incorrect" << endl;
		return nullptr;
	}

	User* registration()
	{
		string username;
		string password;
		string rpassword;

		cout << "Type you username: " << endl;
		cin >> username;

		cout << "Type your password: " << endl;
		cin >> password;

		cout << "Repeat your password: " << endl;
		cin >> rpassword;

		User* user = userService->registration(username, password, rpassword);
		if (user != nullptr)
		{
			return user;
		}
		else
		{
			cout << "Bad credentials" << endl;
			return nullptr;
		}
	}
};
