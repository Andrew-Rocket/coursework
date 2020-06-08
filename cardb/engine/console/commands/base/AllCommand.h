#pragma once
#include <iostream>
#include <map>

#include "../Command.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"
#include "../../views/ProductsView.h"
#include "../../views/View.h"

using namespace std;

class AllCommand : public Command
{
private:
	CarService* carService;
	View* view;
public:

	AllCommand(CarService* carService)
	{
		this->carService = carService;
		name = "all";
		description = "all - show all the cars sorted by id";
		admin = false;

	}

	void execute(vector<string> args, User* user) override
	{
		view = new ProductsView(user, carService->getAll());
		view->display();
	}
};
