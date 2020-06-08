#pragma once
#include <iostream>
#include "../Command.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"

using namespace std;

class DeleteCarCommand : public Command
{
	CarService* carService;
public:

	DeleteCarCommand(CarService* carService)
	{
		this->carService = carService;
		name = "deletecar";
		description = "*deletecar {id} - delete car by id";
		admin = true;
	}

	void execute(vector<string> args, User* user) override
	{
		int id = stoi(args.at(1));
		if (carService->deleteCarById(id))
		{
			cout << "Car successfully deleted" << endl;
		}
		else
		{
			cout << "Error, wrong id" << endl;
		}


	}
};
