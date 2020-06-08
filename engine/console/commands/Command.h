#pragma once
#include <string>
#include <vector>
using namespace std;
class Command
{

protected:
	string name;
	string description;
	bool admin;

	virtual ~Command() = default;


public:

	virtual void execute(vector<string> args, User* user) = 0;

	string getName()
	{
		return name;
	}

	string getDescription()
	{
		return description;
	}

	bool isAdmin()
	{
		return admin;
	}
};
