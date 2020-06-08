#pragma once
#include <iostream>
#include <map>

#include "../Command.h"
#include "../../../utils/Utils.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"

using namespace std;

class FilterCommand : public Command
{
private:
	CarService* carService;
	View* view;
public:

	FilterCommand(CarService* carService)
	{
		this->carService = carService;
		name = "filter";
		description = "filter {COLOR, BRAND, MAX_SPEED, PRICE, ELECTRIC, YEAR} {param/floor} [cellar] - filter cars by type";
		admin = false;

	}

	void execute(vector<string> args, User* user) override
	{
		if (args.size() == 4)
		{
			CarProperties prop = Utils::parseStringToCarProperties(args.at(1));
			vector<Car*> cars = carService->filter(prop, stoi(args.at(2)), stoi(args.at(3)));
			view = new ProductsView(user, cars);
		}

		if (args.size() == 3)
		{
			CarProperties prop = Utils::parseStringToCarProperties(args.at(1));
			vector<Car*> cars = carService->filter(prop, args.at(2));
			view = new ProductsView(user, cars);
		}

		view->display();
	}
};
