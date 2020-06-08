#pragma once
#include "Command.h"
#include "admin/CreateCarCommand.h"
#include "base/AllCommand.h"
#include "base/BalanceCommand.h"
#include "base/ChangePassComand.h"
#include "base/FilterCommand.h"
#include "base/SortCommand.h"

class CommandsBuilder
{
private:
	UserService* us;
	CarService* cs;
public:


	explicit CommandsBuilder(UserService* us, CarService* cs)
		: us(us), cs(cs)
	{
	}

	vector<Command*> build()
	{
		vector<Command*> commands;
		//Regular commands
		commands.push_back(new BalanceCommand());
		commands.push_back(new ChangePassCommand(us));
		commands.push_back(new FilterCommand(cs));
		commands.push_back(new SortCommand(cs));
		commands.push_back(new AllCommand(cs));

		//Admin commands
		commands.push_back(new CreateCarCommand(cs));
		return commands;
	};


};
