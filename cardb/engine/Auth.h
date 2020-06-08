#pragma once
#include "services/UserService.h"
#include <clocale>
#include <windows.h>
#include <iostream>
#include "console/ConsoleAuth.h"


class Auth
{
private:

	ConsoleAuth* consoleAuth;
	UserService* userService;
	UserRepository* userRepository;

public:


	Auth()
	{
		userRepository = new UserRepository("users");
		userService = new UserService(userRepository);
		consoleAuth = new ConsoleAuth(userService);
	}

	User* makeAuth()
	{
		return consoleAuth->start();
	}


	UserRepository* getUserRepository() const
	{
		return userRepository;
	}


	UserService* getUserService() const
	{
		return userService;
	}


};
