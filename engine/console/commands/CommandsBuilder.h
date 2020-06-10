#pragma once
#include "Command.h"
#include "admin/CreateCarCommand.h"
#include "admin/DeleteCarCommand.h"
#include "admin/ReceiptsCommand.h"
#include "admin/UpdateCarCommand.h"
#include "admin/UsersCommand.h"
#include "base/AllCommand.h"
#include "base/BalanceCommand.h"
#include "base/BuyCommand.h"
#include "base/ChangePassComand.h"
#include "base/FilterCommand.h"
#include "base/SortCommand.h"

class CommandsBuilder
{
private:
	UserService* us;
	CarService* cs;
	ReceiptService* rs;
public:


	CommandsBuilder(UserService* us, CarService* cs, ReceiptService* rs)
		: us(us), cs(cs), rs(rs)
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
		commands.push_back(new BuyCommand(cs, rs));

		//Admin commands
		commands.push_back(new CreateCarCommand(cs));
		commands.push_back(new DeleteCarCommand(cs));
		commands.push_back(new UpdateCarCommand(cs));
		commands.push_back(new ReceiptsCommand(rs));
		commands.push_back(new UsersCommand(us));
		return commands;
	};


};
