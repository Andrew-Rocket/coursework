#pragma once
#include <iostream>
#include "../Command.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"

using namespace std;

class CreateCarCommand : public Command
{
	CarService* carService;
public:

	CreateCarCommand(CarService* carService)
	{
		this->carService = carService;
		name = "createcar";
		description = "*createcar {brand} {model} {year} {color} {isElectric(true/false)} {maxSpeed} {baseCost} {price} - add new car to db";
		admin = true;
	}

	void execute(vector<string> args, User* user) override
	{

		if (carService->createAndSave(args.at(1), args.at(2), stoi(args.at(3)),
			args.at(4), Utils::stringToBool(args.at(5)),
			stoi(args.at(6)), stod(args.at(7)), stod(args.at(8))))
		{
			cout << "Car successfully created" << endl;
		}
		else
		{
			cout << "Error, bad credentials" << endl;
		}


	}
};
