#pragma once
#include "../console/commands/Command.h"
#include "../console/commands/CommandsBuilder.h"

class CommandService
{
private:
	vector<Command*> commands;

public:


	CommandService(const vector<Command*>& commands)
		: commands(commands)
	{
	}

	void start(User* user)
	{
		while (true)
		{
			vector<string> args = getAndParseCommand();
			if (args.at(0).compare("help") == 0)
			{
				for (auto cmd : commands)
				{
					if (user->isAdmin() >= cmd->isAdmin()) {
						cout << cmd->getDescription() << endl;
					}
				}
			}
			if (args.at(0).compare("logout") == 0)
			{
				system("CLS");
				break;
			}

			if (args.at(0).compare("exit") == 0)
			{

				throw exception("exit");
			}

			for (auto cmd : commands)
			{
				if (cmd->getName() == args.at(0))
				{
					if (user->isAdmin() >= cmd->isAdmin()) {
						cmd->execute(args, user);
						break;
					}
					cout << "You have no access to this command" << endl;
				}
			}
			cout << endl;
		}
	}

	vector<std::string> getAndParseCommand()
	{
		string command;
		vector<std::string> parsed;
		getline(cin, command);
		command += " ";

		while (true) {
			parsed.push_back(command.substr(0, command.find(" ")));
			command.erase(0, command.find(" ") + 1);

			if (strcmp(&command[0], "\0") == 0 || strcmp(&command[0], " ") == 0)
			{
				break;
			}
		}
		return parsed;
	}
};
