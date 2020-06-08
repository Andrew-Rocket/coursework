#pragma once
#include <iostream>
#include <map>

#include "../Command.h"
#include "../../../utils/Utils.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"
#include "../../views/ProductsView.h"
#include "../../views/View.h"

using namespace std;

class SortCommand : public Command
{
private:
	CarService* carService;
	View* view;
public:

	SortCommand(CarService* carService)
	{
		this->carService = carService;
		name = "sort";
		description = "sort {COLOR, BRAND, MAX_SPEED, PRICE, ELECTRIC, YEAR} {ASC, DESC} - sort cars by type in specific order";
		admin = false;

	}

	void execute(vector<string> args, User* user) override
	{

		CarProperties prop = Utils::parseStringToCarProperties(args.at(1));
		Order order = Utils::parseStringToOrder(args.at(2));
		vector<Car*> cars = carService->sort(prop, order);
		view = new ProductsView(user, cars);


		view->display();
	}
};
