#pragma once
#include <iostream>
#include "../Command.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"

using namespace std;

class UpdateCarCommand : public Command
{
	CarService* carService;
public:

	UpdateCarCommand(CarService* carService)
	{
		this->carService = carService;
		name = "updatecar";
		description = "*updatecar {id} {COLOR, BRAND, MAX_SPEED, PRICE, ELECTRIC, YEAR} {value}- update car by id";
		admin = true;
	}

	void execute(vector<string> args, User* user) override
	{
		int id = stoi(args.at(1));
		CarProperties prop = Utils::parseStringToCarProperties(args.at(2));

		if (carService->updateCarByIdWithParam(id, prop, args.at(3)))
		{
			cout << "Car successfully updated" << endl;
		}
		else
		{
			cout << "Error, no such car" << endl;
		}


	}
};
